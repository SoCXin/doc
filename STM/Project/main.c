/******************** (C) COPYRIGHT   ********************************
 * 文件名  ：main.c
 * 描述    ：MCU通过SPI对w5500的读写操作
 * 库版本  ：V3.50
 * 作者    ：
 * 调试方式：J-Link-OB
**********************************************************************/

#include <stdio.h>
#include "stm32f10x.h"

#include "led.h"
#include "SYSTICK.h"
#include "usart.h"
#include "i2c.h"
#include "adc.h"
#include "SPIx.h"
#include "pwm.h"
#include "timer.h" 
#include "w5500.h"
#include "W5500_conf.h"
#include "socket.h"

#include "exti.h"
#include "key.h"

#include "Relay.h"
#include "rc522.h"
#include "voice.h"
#include "beep.h"

#include "dhcp.h"
#include "udp_tool.h"
#include "led_beep.h"
#include "work_net.h"
#include "user_config.h"
#include "Finger.h"
#include "work_232.h"
#include "work_ttl.h"
#include "work_rfid.h"
#include "work_btn.h"
#include "led.h"
#include "Lcd_Driver.h"
#include "gui.h"
#include "show_work.h"
#include "strength.h"
#include "finger_parse.h"


int main(void)
{
	user_config_init();							//初始化化自定义变量		
	SYSTICK_Init();								//初始化滴答时钟
	
	USART1_Config_ttl((g_user_config.baud_rate_ttl_1 > 256000 || g_user_config.baud_rate_ttl_1 < 110) ? 9600 : g_user_config.baud_rate_ttl_1);	
	USART2_Config_232((g_user_config.baud_rate_232_2 > 256000 || g_user_config.baud_rate_232_2 < 110) ? 9600 : g_user_config.baud_rate_232_2);
	LED_GPIO_Config();							//初始化LED端口
	
	/////////////////////////////////////////////
	LED_GPIO_Config();							//初始化LED
	Lcd_Init();									//初始化显示
	Lcd_Clear(GRAY0);							//清除屏幕
	LCD_LED_SET;								//通过IO控制背光亮	
	/////////////////////////////////////////////
//	if(g_user_config.hd_version == HD_VERSION_JN)
//	{
//		TIM2_PWM_Init();							//初始化PWM
//	}
//	else
//	{
//		eg_beep_GPIO_config();
//	}
	/////////////////////////////////////////////
	TIM4_Start();								//初始化4号定时器
	//Exti_Config();							//按键配置
	//KEY_GPIO_Config();						//按键配置
	if(g_user_config.type != 1)
		adc_init();								//ADC转换器();
	Relay_GPIO_Config();						//继电器初始化
	/////////////////////////////////////////////
	
	//eg_rfid_init();							//读卡器初始化
	//delay_ms(1000);

	/////////////////////////////////////////////
	I2C_Configuration();						//W5500通信
	WizW5500_Init(IP_FROM_DHCP);				//初始化W5500网卡
	delay_ms(3000);								//必须等待3秒 w5500模块初始化完成
	/////////////////////////////////////////////
	close(SOCK_UDPS);	//必须启动的时候关掉UDPS这一路socket
	close(SOCK_DHCP);
	close(SOCK_UDP_LONG);
	delay_ms(100);
	/////////////////////////////////////////////
	open_iwdg(4, 1875);//启动看门狗
	//printf("start");
	while (1)
	{
		update_status();				//刷新各种数据			
		do_dhcp();						//获取DHCP
//		if(dhcp_ok != 1) continue;		
		eg_clear_timeout_data();		//数据超时清空			
		if(eg_net_loop() == -1)	continue;	//解析网络数据		
		eg_232_loop();					//解析232			
		eg_ttl_loop();					//解析TTL		
		
		//计数器功能留下
		eg_btn_loop();					//解析按键			
		eg_finger_init();				//初始化指纹模块
	}
}

/******************************************************************
 * 描述    ：MCU通过SPI对w5500的读写操作，完成对mac，gateway等的操作
********************************************************************/

//限制运行速度
unsigned char g_time_work_limit_01 = 0; //0.1秒
unsigned char g_time_work_limit_1 = 0;  //1秒

//每隔0.01秒运行一次
void time_work(void)
{
	//继电器自动关闭
	if(g_replay_time <= 0)
	{
		REALY0_OFF;
		REALY1_OFF;
	}
	else
	{
		g_replay_time--;
	}
	//控制0.1秒显示一次
	g_time_work_limit_01++;
	if(g_time_work_limit_01 >= 10) 
	{
		g_time_work_limit_01 = 0;
		
		if(g_finger_ing > 0)	//录入指纹中
		{
			CON_LED(11);
			g_finger_ing--;
		}
		else if(g_user_config.device_id[0] == 0)	//没有配置信息 - 红快速闪烁
		{
			CON_LED(16);
			SHOW_NO_CONFIG;
		}
		else if(g_w5500_status == 0)	//没有插网线 - 红色常亮
		{
			CON_LED(8);
			SHOW_INTO_LINE;
		}
		else if(g_time_now - g_heart_server >= 1000)//10s没收到广播数据 - 紫色常亮 红色闪烁
		{
			CON_LED(14);
			SHOW_ERROR_CON;
		}
		else if(g_time_now - g_heart_client >= 1000)//10s没收到client数据 - 红色闪烁 蓝色闪烁
		{
			CON_LED(9);
			SHOW_ERROR_CON;
		}
		else  //正常情况 - 白色慢闪烁
		{
			if(g_iot_status == 0)
			{
				CON_LED(15);
				SHOW_ERROR_SERVER;
			}
			else
			{
				if(Relay_Status(2)) //继电器打开-绿色常亮
					CON_LED(7);
				else
					CON_LED(10);
				
				//网络连接正常后恢复连接等级
				if(g_show_live == 0xFE)
					SHOW_LIVE_CLEARE
				
				SHOW_LOGO;
			}
		}
	}	
	//控制显示窗口时间 1秒钟
	g_time_work_limit_1++;
	if(g_time_work_limit_1 > 100) 
	{
		g_time_work_limit_1 = 0;		
		//控制图层显示
		show_check_time();
	}	
	//声音和灯光控制
	led_beep_time_work();
}

