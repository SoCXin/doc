#include "strength_lp.h"
#include "SYSTICK.H"
#include "Types.h"
#include "exti.h"
#include "model.h"
#include "user_config.h"
#include <stdlib.h>
#include "show_work.h"
#include "led_beep.h"
#include "key.h"
#include "work_btn.h"

uint8 	g_strength_pl_status = 0; 																			//0关闭 1打开 2待机
uint8		g_strength_pl_beep = 0;																					//是否开启归位提示音

/////////////////////////////////////////////////////////////////////////////////////////

#define STREANGTH_PL_BUFF_LEN					50

uint8   g_strength_pl_exercise_lock = 0;																							//是否锁定片数
uint8  *g_strength_pl_btn1 = (g_send_buff + BUFF_LEN - STREANGTH_PL_BUFF_LEN);				//按键1记录
uint8  *g_strength_pl_btn2 = (g_send_buff + (BUFF_LEN - STREANGTH_PL_BUFF_LEN * 2));	//按键2记录
uint8   g_strength_pl_btn1_pos = 0;
uint8   g_strength_pl_btn2_pos = 0;
	
//网络设置状态
int eg_strength_lp_net_set_status(unsigned int status, unsigned int space_time, unsigned int one_time, unsigned char beep)
{
	//设置状态
	g_strength_pl_status = status;
	g_strength_pl_beep = beep;
	
	//数据复位
	g_strength_pl_exercise_lock = 0;
	g_strength_pl_btn1_pos = 0;
	g_strength_pl_btn2_pos = 0;
	memset(g_strength_pl_btn1, 0, STREANGTH_PL_BUFF_LEN);
	memset(g_strength_pl_btn2, 0, STREANGTH_PL_BUFF_LEN);
	
	return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//上传拉力值
void eg_strength_lp_push(void)
{
	//提示音
	if(g_strength_pl_beep)
		GROUP_PRO_SUCCEED;
	
	g_send_len = ModelMakeStrengthReq((char *)g_send_buff, 0, 0, 0, 
		(char *)g_strength_pl_btn1, (char *)g_strength_pl_btn2);
	UDP_PUSH;
}


void eg_strength_lp_btn(unsigned int interval, char btn_key)
{
	if(g_strength_pl_status == 0)
		return;
	
	//锁定了就不要再触发了
	if(g_strength_pl_exercise_lock)
		return;
	
	//记录光感1 
	if(btn_key == 1 && g_strength_pl_btn1_pos < STREANGTH_PL_BUFF_LEN)
		g_strength_pl_btn1[g_strength_pl_btn1_pos++] = interval > 0xFF ? 0xFF : interval;
	
	//记录光感2
	if(btn_key == 2 && g_strength_pl_btn2_pos < STREANGTH_PL_BUFF_LEN)
		g_strength_pl_btn2[g_strength_pl_btn2_pos++] = interval > 0xFF ? 0xFF : interval;
}


uint8 btn4_s = 0;
