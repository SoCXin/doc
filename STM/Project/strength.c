#include "strength.h"
#include "usart.h"
#include "user_config.h"
#include "show_work.h"
#include "gui.h"
#include "Lcd_Driver.h"
#include "SYSTICK.h"
#include "exti.h"
#include "work_btn.h"

//记录状态
unsigned char 	g_strength_status = 0;

//缓存区域-缓冲力量点
unsigned char		g_strength_buff[18];
unsigned char		g_strength_buff_len = 0;
unsigned int		g_strength_values[3];
unsigned int		g_strength_value_pos = 0;

//记录任务index
unsigned int		g_strength_index = 0;

//显示次数
unsigned short	g_strength_count = 0;

//记录最小值校准用
unsigned int		g_strength_min = 0xFFFFFFFF;

//记录显示的index
unsigned int 	  g_streng_show_index = 0;

//记录之前显示的信息，加速刷新用的
char g_strength_old_show[4] = {0};

#define EG_STRENGTH_VALUE					"\xA5\x02\xA7"
#define EG_STRENGTH_VALUE_ALL			"\xA5\x03\xA6"

#define EG_STRENGTH_SHOW_LEFT			20

void eg_strength_close(void)
{
		sendDatatoRS232(EG_STRENGTH_VALUE, 3);
		g_strength_status = 0;
}


int eg_strength_sync_status(unsigned char staus, unsigned int index, unsigned char *out_buff, unsigned short *out_len)
{	
	if(index != g_strength_index)
	{
		g_strength_count = 0;
		g_strength_index = index;
	}
	
	//开启
	if(staus == 1 && g_strength_status == 0)
	{
		CHECK_SHOW_LIVE(2);
		
		memset(g_strength_old_show, 0, sizeof(g_strength_old_show));
		g_strength_count = 0;
		g_strength_min = 0xFFFFFFFF;
		
		//开启
		sendDatatoRS232(EG_STRENGTH_VALUE_ALL, 3);
	}
	
	//关闭
	if(staus == 0 && g_strength_status != 0)
	{
		eg_strength_close();
		
		//关闭显示
		CHECK_SHOW_LIVE(2);
		SHOW_LIVE_CLEARE;
	}
	
	//进入待机状态
	if(staus == 2 && g_strength_status == 1)
	{
	}
	
	//退出待机状态
	if(staus == 1 && g_strength_status == 2)
	{
	}
	
	g_strength_status = staus;
	
	//设置计数器灵敏度300毫秒
	g_btn1_limit_time = 300;
	
	////////////////////////////////////
	*out_len = ModelMakeStrengthStatusAck((char *)out_buff, 1, 0, g_streng_show_index, g_strength_count/2, g_strength_status);
	
	return 1;
}


int eg_strength_add_data(unsigned char data)
{
	if(g_user_config.type != 3 || g_w5500_status == 0)
		return 0;
	
	if(g_strength_buff_len < 9) {
		g_strength_buff[g_strength_buff_len] = data;
		g_strength_buff_len++;
	}
	return 1;
}

int eg_strength_check_view(void)
{
	static char send_time = 0;
	if(g_show_live == 2)
		return 0;
	
	if(g_time_now - send_time < 200)
		return 1;
	send_time = g_time_now;

	g_send_len = ModelMakeHeader((char *)g_send_buff, 167, 0);
	UDP_PUSH;
	return 1;
}

void eg_strength_push(void)
{
	static uint32 strength_last_push_time = 0;
	char show[4] = {0};
	
	if(g_btn_adc_count > 0) 
	{
		//触发时间间隔1.2秒
		g_btn_adc_count = 0;
		if(g_time_now - strength_last_push_time < 120)
			return;
		
		//如果采集的力量点不够就不要计数
		if(g_strength_value_pos < 3)
			return;
		strength_last_push_time = g_time_now;
		g_strength_count++;
		
		if(g_strength_count % 2 == 0)
		{			
			//推送数据
			g_send_len = ModelMakeStrengthReq((char *)g_send_buff, 
			g_strength_values[0], g_strength_values[1], g_strength_values[2], 0, 0);
			UDP_PUSH;
			
			//更新次数
			if(g_strength_status == 1)
			{
				g_show_time = 0xFF;
				snprintf(show, 4, "%03d", g_strength_count/2);
				show_num_pic(show, EG_STRENGTH_SHOW_LEFT, 80, 0, 0xFFFF);
				g_streng_show_index = g_draw_pic_number;
			}
		}
	}
}

int eg_strength_loop(void)
{
	unsigned char key = 0, i = 0;
	unsigned char *p = 0;
	char show[4] = {0};
	
	//停止状态就不要执行
	if(g_strength_status == 0)
		return 0;
	
	//检查是否进入待机状态
	show_check_standby();					
	
	//如果图层变更关闭力量器械
	if(eg_strength_check_view())
		return 0;
	
	//推送数据
	eg_strength_push();
	
	///////////////////////////////////////////////////////////////////////////////////////////
	
	if(g_strength_buff_len < 9)
		return 1;
	
	//验证数据是否有效
	for (i = 0;i < 8; i++)
		key = key ^ g_strength_buff[i];
	
	//读取数据
	if (key == g_strength_buff[8]) {
		
		//缓存值
		if(g_strength_value_pos >= 3)
		{
			g_strength_values[0] = g_strength_values[1];
			g_strength_values[1] = g_strength_values[2];
			g_strength_value_pos = 2;
		}
		p = (unsigned char *)(g_strength_values + g_strength_value_pos);
		g_strength_value_pos++;
		
		//获取这次测量的值
		for (i= 0; i < 4; i++)
				p[i] = g_strength_buff[6-i];
		
		//减去最小校准值
		if(g_strength_min > g_strength_values[g_strength_value_pos - 1]) {
			g_strength_min = g_strength_values[g_strength_value_pos - 1];
		}
		g_strength_values[g_strength_value_pos - 1] -= g_strength_min;
		
		
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//显示当前重量
		
		//过滤掉没变化的数字
		snprintf(show, 4, "%03d", (g_strength_values[g_strength_value_pos - 1] + 500)/1000);
		for(i = 0; i < 3; i++) {
				if(show[i] != g_strength_old_show[i])
					break;
		}
		
		if(i < 3) {
			
			//如果不是连续显示就整个刷新
			if(g_streng_show_index != g_draw_pic_number)
			{
				i = 0;
				g_streng_show_index |= 0xF0000000;
				g_streng_show_index++;
			}
			
			//显示数字变化
			if(g_strength_status == 1)
			{
				g_show_time = 0xFF;
				show_num_pic(show + i, EG_STRENGTH_SHOW_LEFT + 21 * i, 40, 0, 0xFFFF);
				memcpy(g_strength_old_show, show, sizeof(show));
				g_streng_show_index = g_draw_pic_number;
			}
		}
	}
	
	g_strength_buff_len = 0;
	return 1;
}
