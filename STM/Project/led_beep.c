#include "led_beep.h"
#include "LED.h"
#include "user_config.h"
#include "beep.h"

//LED和BEEP控制
uint16_t  g_led_start_time = 0;
uint16_t  g_led_time = 0;
uint16_t 	g_led_cycle = 0;
uint16_t	g_led_color = 0;
uint16_t 	g_led_scale = 0;
uint16_t  g_led_delay = 0;
uint16_t	g_beep_start_time = 0;
uint16_t	g_beep_time = 0;
uint16_t 	g_beep_cycle = 0;
uint16_t	g_beep_scale = 0;
uint16_t	g_beep_delay = 0;

uint8			g_beep_status = 0;

uint32_t 	g_led_pro = 0;

//////////////////////////////////////////////////////////////////////////////////////
//设置灯
void CON_LED(int pro)
{
	if(g_led_pro >= 7)
	{
		if(g_led_pro == pro)
			return;
	}
	else if(g_led_pro <= pro && g_led_pro != 0)
	{
		return;
	}
	
	g_led_delay = 20;
	g_led_pro = pro;

	g_led_start_time = 0;
	if(pro == 1)
	{
		g_led_time = 20;
		g_led_cycle = 40;
		g_led_scale = 20;
		g_led_color = 1;
	}
	else if(pro == 2)
	{
		g_led_time = 20;
		g_led_cycle = 40;
		g_led_scale = 20;
		g_led_color = 1;
	}
	else if(pro == 3)
	{
		g_led_time = 20;
		g_led_cycle = 40;
		g_led_scale = 20;
		g_led_color = 1;
	}
	else if(pro == 4)
	{
		g_led_time = 80;
		g_led_cycle = 40;
		g_led_scale = 20;
		g_led_color = 1<<3;
	}
	else if(pro == 5)
	{
		g_led_time = 20;
		g_led_cycle = 40;
		g_led_scale = 20;
		g_led_color = 1<<2;
	}
	else if(pro == 6)
	{
		g_led_time = 0xFF;
		g_led_cycle = 100;
		g_led_scale = 50;
		g_led_color = 1<<2;
	}
	else if(pro == 7)
	{
		g_led_time = 0xFF;
		g_led_cycle = 0xFF;
		g_led_scale = 0xFF;
		g_led_color = 1<<2;
	}
	else if(pro == 8)
	{
		g_led_time = 0xFF;
		g_led_cycle = 0xFF;
		g_led_scale = 0xFF;
		g_led_color = 1<<3;
	}
	else if(pro == 9)
	{
		g_led_time = 0xFF;
		g_led_cycle = 120;
		g_led_scale = 60;
		g_led_color = 1;
	}
	else if(pro == 10)
	{
		g_led_time = 0xFF;
		g_led_cycle = 300;
		g_led_scale = 200;
		g_led_color = 1 | 1<<2 | 1<<3;
	}
	else if(pro == 11)
	{
		g_led_time = 0xFF;
		g_led_cycle = 0xFF;
		g_led_scale = 0xFF;
		g_led_color = 1 | 1<<2;
	}
	else if(pro == 12)
	{
		g_led_time = 36;
		g_led_cycle = 12;
		g_led_scale = 6;
		g_led_color =  1<<2;
	}	
	else if(pro == 13)
	{
		g_led_time = 60;
		g_led_cycle = 20;
		g_led_scale = 10;
		g_led_color = 1;
	}
	else if(pro == 14)			//紫色
	{
		g_led_time = 0xFF;
		g_led_cycle = 120;
		g_led_scale = 60;
		g_led_color = 1 << 3;
		
//		g_led_time = 0xFF;
//		g_led_cycle = 0xFF;
//		g_led_scale = 0xFF;
//		g_led_color = 1 | 1<<3;
	}
	else if(pro == 15)
	{
		g_led_time = 0xFF;
		g_led_cycle = 80;
		g_led_scale = 40;
		g_led_color = 1 | 1<<2 | 1<<3;
	}
	else if(pro == 16)
	{
		g_led_time = 0xFF;
		g_led_cycle = 60;
		g_led_scale = 30;
		g_led_color = 1<<3;
	}
}

void CON_BEEP(int pro)
{
	g_beep_delay = 20;
	g_beep_start_time = 0;
	if(pro == 1)
	{
		g_beep_time = 20;
		g_beep_cycle = 40;
		g_beep_scale = 20;
	}
	else if(pro == 2)
	{
		g_beep_time = 80;
		g_beep_cycle = 40;
		g_beep_scale = 20;
	}
	else if(pro == 3)
	{
		g_beep_time = 160;
		g_beep_cycle = 80;
		g_beep_scale = 40;
	}
	else if(pro == 4)
	{
		g_beep_time = 500;
		g_beep_cycle = 0xFFFF;
		g_beep_scale = 0xFFFF;
	}
	else if(pro == 5)
	{
		g_beep_time = 30;
		g_beep_cycle = 10;
		g_beep_scale = 5;
	}
	else if(pro == 6)
	{
		g_beep_time = 60;
		g_beep_cycle = 20;
		g_beep_scale = 10;
	}
}

void led_beep_force(void)
{
	g_led_delay = 20;
	g_led_pro = 0;
	g_led_start_time = 0;
	g_led_time = 0;
	g_led_cycle = 0;
	g_led_scale = 0;
	
	g_beep_delay = 20;
	g_beep_start_time = 0;
	g_beep_time = 0;
	g_beep_cycle = 0;
	g_beep_scale = 0;
	
	GREEN_LED_OFF;
	BLUE_LED_OFF;
	RED_LED_OFF;
	BEEP_OFF;
}

void SET_LED(char ledR, char ledG, char ledB) {
	if(ledR != 0)
	{
		RED_LED_ON;
	}
	else
	{
		RED_LED_OFF;
	}
	
	if(ledG != 0)
	{
		GREEN_LED_ON;
	}
	else
	{
		GREEN_LED_OFF;
	}
	
	if(ledB != 0)
	{
		BLUE_LED_ON;
	}
	else
	{
		BLUE_LED_OFF;
	}
}


void led_beep_time_work(void)
{
	
	//LED
	if(g_led_delay == 0)
	{
		g_led_start_time++;
		if(g_led_time > 0)
		{
			if(g_led_time == 0xFF || g_led_start_time < g_led_time){
				if(g_led_cycle == 0xFF ||	g_led_start_time % g_led_cycle < g_led_scale) {
					SET_LED(g_led_color >> 3 & 1, g_led_color >> 2 & 1, g_led_color & 1);
				} else {
					SET_LED(0, 0, 0);
				}
			} else {
				g_led_time = 0;
			}
		}
		if(g_led_time == 0)
		{
			GREEN_LED_OFF;
			BLUE_LED_OFF;
			RED_LED_OFF;
			g_led_pro = 0;
		}
	}
	else
	{
		g_led_delay--;
	}
	
	
	//BEEP
	if(g_beep_delay == 0)
	{
		g_beep_start_time++;
		if(g_beep_time > 0)
		{
			
			if(g_beep_start_time < g_beep_time) {
				if(	g_beep_start_time % g_beep_cycle < g_beep_scale) {
						BEEP_ON;
				} else {
					BEEP_OFF;
				}
			} else {
				g_beep_time = 0;
			}
			
		}
		if(g_beep_time == 0)
		{
			BEEP_OFF;
		}
	}
	else
	{
		g_beep_delay--;
	}
}
