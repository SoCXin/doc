#include "user_config.h"
#include "stm32f10x.h"
#include "model.h"
#include "w5500.h"

//设置配置信息协议
char						WRITE_USER_CONFIG_START[5]=  {0xfa, 0xc0, 0x71, 0xb9, 0x01};
char						WRITE_USER_CONFIG_END[5]  =  {0x2a, 0x81, 0x2d, 0xb8, 0x6d};

//全局配置 flash
USER_CONFIG_S		g_user_config;

//是否安装RFID读卡器
uint8		g_have_rfid = 0;

//是否开启printf打印
uint8						g_show_printf = PRINT_SWITCH;

//控制器IP和端口
uint8						g_server_ip[4];					
uint16					g_server_port = 0;
uint16					g_server_push_port = 0;
uint8						g_sync_work_ip[4];				//异步任务的IP和端口				
uint16					g_sync_work_port = 0;

//在主函数内推送
uint8						g_main_udp_push = 0;
uint8					 *g_main_udp_push_buff = g_send_buff + BUFF_LEN - 200;

//数据类型
uint8						g_data_type = 0;
uint32					g_data_time = 0;

//芯片ID
uint32					g_chip_uuid[3];

//是否安装指纹模块
uint8						g_finger_is = 0;

//是否连接上了IOT
uint8						g_iot_status = 0;

//记录心跳时间
uint32					g_heart_client = 0;
uint32					g_heart_server = 0;

//看门狗计时器 - 初始化必须和g_time_now一样
unsigned int 			g_time_now = 0xFFFF;
uint32					g_time_now_ms = 0xFFFF;
uint32					g_dog_client_time = 0xFFFF;

//继电器打开时间
uint32					g_replay_time = 0;

//缓存区域
uint8  					g_rev_buff[BUFF_LEN+1];
uint16  				g_rev_len = 0;
uint8  					g_send_buff[BUFF_LEN+1];
uint16  				g_send_len = 0;


//w5500芯片联网情况
uint8						g_w5500_status = 1;


void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4 , TIM_IT_Update) != RESET ) 
	{
		TIM_ClearITPendingBit(TIM4 , TIM_FLAG_Update);
		
		g_time_now++;
		time_work();
	}
}


void user_config_init(void)
{
	//获取芯片ID
	g_chip_uuid[2] = *(__IO u32*)(0X1FFFF7E8);  
	g_chip_uuid[1] = *(__IO u32 *)(0X1FFFF7EC); 
	g_chip_uuid[0] = *(__IO u32 *)(0X1FFFF7F0); 
	ModelInit((char*)g_chip_uuid);
	
	//读取flash配置文件
	if(*(vu32*)(FLASH_ADR) == 0xffffffff)
		memset(&g_user_config, 0, sizeof(FLASH_ADR));
	else
		memcpy(&g_user_config, (char *)FLASH_ADR, sizeof(g_user_config));
}

int user_set_config(char *buff, int len)
{
	int i = 0;

	FLASH_Unlock();
	FLASH_ErasePage(FLASH_ADR);
	for(i = 0; i < (len + 1) / 2; i++) {
		FLASH_ProgramHalfWord(FLASH_ADR + i * 2, *(u16 *)(buff + i * 2));
	}
	FLASH_Lock();

	user_config_init();		
	
	return memcmp((char *)&g_user_config, buff, len) == 0;
}

void eg_clear_timeout_data(void)
{
	if((g_data_type != DATA_TYPE_NONE || g_send_len > 0) && g_time_now - g_data_time > 50)
	{
		eg_clear_data();
	}
}

void eg_clear_data(void)
{
		g_send_len = 0;
		g_data_type = DATA_TYPE_NONE;
		g_rev_len = 0;
}

void open_iwdg(uint8 pr, uint16 rlr)
{
	if(g_user_config.device_id[0] == 0 || (unsigned char)g_user_config.device_id[0] == 0xFF) 
		return;
	
  IWDG->KR = 0x5555;        //使能对IWDG->PR和IWDG->RLR的写
  IWDG->PR = pr;            //LSI/32=40Khz/(4*2^pre) //4、8、16、32、64、128、256
  IWDG->RLR = rlr;          //从加载寄存器 IWDG->RLR，Max=0xFFF。因为看门狗计数器正是从这个值开始向下计数。
  IWDG->KR = 0xAAAA;        //reload
  IWDG->KR = 0xCCCC;        //使能看门狗
}

void IWDG_Feed(void)
{
    IWDG->KR=0XAAAA;                                  
}

int update_status(void)
{
	WORK_HZ_LIMIT(10);
	g_w5500_status = getNetLink();	
	//看门狗喂狗 - 超过20秒没收到心跳包就重启设备
	if(g_time_now - g_dog_client_time < 2000 || g_show_printf == 1)	IWDG_Feed();
	return 0;
}
