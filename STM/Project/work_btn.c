#include "work_rfid.h"
#include "SYSTICK.H"
#include "usart.h"
#include "Types.h"
#include "user_config.h"
#include "led_beep.h"
#include "model.h"
#include "work_btn.h"
#include "exti.h"
#include "strength.h"
#include "strength_lp.h"
#include "key.h"
#include <stdlib.h>
#include "adc.h"


//累积次数
unsigned char 	g_btn_adc_count = 0;
//触发时间
unsigned int		g_btn1_trigger_time = 0;


//触发间隔
unsigned short 	g_btn1_limit_time = 100;
//触发空闲时间
unsigned int 	  g_tickt_free = 0;
//触发计算速度
unsigned short  g_btn1_speed = 0;


void eg_check_btn1(void)
{
	//非默认设备都不要启动精确计数功能
	if(g_user_config.type == 1)
		return;
	
	if(g_adc1_value >= 3500)
	{
		//触发
		if(g_tickt_free > g_btn1_limit_time)
		{
			g_btn1_speed = g_time_now_ms - g_btn1_trigger_time;
			g_btn1_trigger_time = g_time_now_ms;
			g_btn_adc_count++;
		}
		g_tickt_free = 0;
	}
	else
	{
		g_tickt_free++;
	}
}

//int eg_counter_work()
//{
//	//没有数据就不要触发
//	if(g_btn_adc_count == 0)
//		return 0;
//	
//	//限制发送频率
//	if((unsigned int)(g_time_now - g_btn1_last_push_time) < 100)
//		return 0;
//	g_btn1_last_push_time = g_time_now;
//		
//	//发送推送信息
//	g_send_len = ModelMakeBtnReq((char *)g_send_buff, 1, g_btn_adc_count, g_btn1_speed);
//	UDP_PUSH;
//	
//	g_btn_adc_count = 0;
//	
//	return 1;
//}


//最后推送时间
unsigned int g_btn1_last_push_time = 0;
int eg_btn_loop(void)
{
//	if(eg_strength_loop() != 0)					//解析力量器械需要单独处理		
//		return 1;
//	if(eg_strength_lp_loop() != 0)			//光感力量器械
//		return 1;
//	return eg_counter_work();						//计数器
	
	/////////////////////////////////////////////////////////////////
	
	//没有数据就不要触发
	if(g_btn_adc_count == 0)
		return 0;
	
	//限制发送频率
	if((unsigned int)(g_time_now - g_btn1_last_push_time) < 100)
		return 0;
	g_btn1_last_push_time = g_time_now;
	
	//推送-计数清零
	g_send_len = ModelMakeBtnReq((char *)g_send_buff, 1, g_btn_adc_count, g_btn1_speed);
	UDP_PUSH;
	g_btn_adc_count = 0;
	
	return 1;
}
