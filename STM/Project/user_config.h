#ifndef USER_CONFIG_H
#define USER_CONFIG_H

#include "Types.h"
#include "udp_tool.h"
#include "stm32f10x_it.h"

//全局配置 flash配置
#pragma pack(1)
typedef struct UserConfig
{
	char device_id[50];			//id
	char device_se[50];			//授权码
	char type;							//设备类型（0：默认，1：道闸门禁， 2：衣柜 ）
	
	//232透传过滤器
	char pass_232_start;
	char pass_232_end;
	int  pass_232_len;
	
	//波特率 
	unsigned int  baud_rate_ttl_1;					//tt1波特率
	unsigned int  baud_rate_232_2;					//232波特率
	
	//WIFI密码
	char wifi_name[50];
	char wifi_password[50];

	//是否配置账号信息(2广州版本的，0山东版本的)
	char hd_version;
}USER_CONFIG_S;

extern  USER_CONFIG_S		g_user_config;
#define FLASH_ADR   		0x0801F000  		/* 存储数据Flash页首地址 128K */


//板子版本 - 广州版本的
#define HD_VERSION_GZ		2
#define HD_VERSION_JN		1


//#define ALIYUN_NAME 			"HW-RELAY-000003"
//#define ALIYUN_SECRET 		"iF5XSRrs2nVq6aq0"
////是否安装RFID模块
//#define IS_EXIST_RFID			1
////是否安装WIFI模块
//#define IS_EXIST_WIFI			0

//配置代码版本
#define CODE_VERSION			"HW 1.2.2"

//是否开启调 控制DHCP用的
//#define EG_DEBUG

//调试信息输出端口
#define PRINT_USART				USART_TTL

//是否默认开启输出调试信息
#define PRINT_SWITCH			1

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//默认监听端口
#define SERVER_PORT				5301
//默认监听长数据端口
#define SERVER_LONG_PORT	5401
//缓冲区大小
#define BUFF_LEN 					4280

//是否开启调试打印数据(1开启，0关闭)
extern uint8							g_show_printf;

//设置配置信息
#define WRITE_USER_CONFIG_LEN			10
extern 	char		WRITE_USER_CONFIG_START[5];
extern  char		WRITE_USER_CONFIG_END[5];
//////////////////////////////////////////////////////////////

//是否安装RFID读卡器
extern uint8		g_have_rfid;

//控制器IP和端口
extern uint8		g_server_ip[4];					
extern uint16		g_server_port;
extern uint8		g_sync_work_ip[4];				//异步任务的IP和端口				
extern uint16		g_sync_work_port;
extern uint16		g_server_push_port;  //专门存储推送服务器接收端口

//在主函数内推送
extern uint8		g_main_udp_push;
extern uint8	 *g_main_udp_push_buff;

//定时器
extern unsigned int g_time_now;
extern uint32				g_time_now_ms;

//返回网络数据
#define MAIN_UDP_PUSH			g_main_udp_push = 1;
#define UDP_PUSH					if(g_send_len != 0){eg_upd_sendto(g_send_buff, g_send_len, g_server_ip, g_server_push_port);g_send_len = 0;}
#define UDP_SYNC_ACK			if(g_send_len != 0){eg_upd_sendto(g_send_buff, g_send_len, g_sync_work_ip, g_sync_work_port);g_send_len = 0;}

//发送异步TTL数据
#define TTL_SYNC_SEND(ip, port)			if(g_send_len != 0){\
	memcpy(g_sync_work_ip, ip, 4);\
	g_sync_work_port = port;\
	sendDatatoTTL((char *)g_send_buff, g_send_len);\
	g_send_len = 0;}

//限制执行频率(time 0.01秒单位)
#define WORK_HZ_LIMIT(time) 	{static uint32 last_check_time = 0;\
	if(g_time_now - last_check_time < time)\
	{return 0;}\
	else\
	{last_check_time = g_time_now;}}
#define WORK_HZ_LIMIT_VOID(time) 	{static uint32 last_check_time = 0;\
	if(g_time_now - last_check_time < time)\
	{return;}\
	else\
	{last_check_time = g_time_now;}}

//数据类型
extern uint8		g_data_type;
extern uint32		g_data_time;
#define 				DATA_TYPE_NONE  	0
#define 				DATA_TYPE_TTL  		1
#define 				DATA_TYPE_232  		2
#define 				DATA_TYPE_NET  		3
//很长的UDP包
#define 				DATA_TYPE_NET_LONG  		4	

//芯片ID
extern uint32				g_chip_uuid[3];

//是否安装指纹模块
extern uint8				g_finger_is;

//记录心跳时间
extern uint32				g_heart_client;
extern uint32				g_heart_server;

//看门狗计时器
extern uint32			  g_dog_client_time;

//继电器打开时间
extern uint32				g_replay_time;

//w5500芯片联网情况
extern uint8				g_w5500_status;

//是否连接上IOT
extern uint8				g_iot_status;


//////////////////////////////////////////////////////////////

//缓存区域
extern uint8  		g_rev_buff[BUFF_LEN+1];
extern uint16  		g_rev_len;
extern uint8  		g_send_buff[BUFF_LEN+1];
extern uint16  		g_send_len;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////


//初始化变量
void user_config_init(void);

//设置配置信息
int user_set_config(char *buff, int len);

//清理掉超时的数据
void eg_clear_timeout_data(void);

//数据标志复位
void eg_clear_data(void);

//定时器工作
void time_work(void);

//监控各种数据
int update_status(void);

//看门狗
void open_iwdg(uint8 pr, uint16 rlr);

#endif
