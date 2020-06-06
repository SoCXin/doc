#include "show_work.h"
#include "gui.h"
#include "Lcd_Driver.h"
#include "SYSTICK.h"
#include "user_config.h"
#include "usart.h"
#include "user_config.h"


unsigned char FONT_NUM_WRITE_TOP[3] = { 0xFD, 0xF0, 0xF1 };
unsigned char FONT_NUM_WRITE_END[3] = { 0xF1, 0xF0, 0xFD };

#define SHOW_FONT_FLASH_NUM_ADDRESS				0x8018000

#define SHOW_FONT_FLASH_NUM_MAX_COUNT			20

////////////////////////////////////////////////////////////////////////////////////////////

unsigned char FONT_TOP[3] = { 0xF1, 0xF2, 0xF3 };
unsigned char FONT_END[3] = { 0xF4, 0xF5, 0xF6 };




#define SHOW_TXT_ADDR_INTO_INLINE					SHOW_FONT_FLASH_FALSH_ADDRESS
#define SHOW_TXT_ADDR_CON									SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 1
#define SHOW_TXT_ADDR_SERVER							SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 2
#define SHOW_TXT_ADDR_NO_CONFIG						SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 3
#define SHOW_TXT_ADDR_INVALID_CARD				SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 4
#define SHOW_TXT_ADDR_INVALID_FINGER			SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 5
#define SHOW_TXT_ADDR_ERROR								SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 6
#define SHOW_TXT_ADDR_SUCCEED							SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 7
#define SHOW_TXT_ADDR_NET_ERROR						SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 8

#define SHOW_PIC_ADDR_NET_ERROR						SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 10
#define SHOW_PIC_ADDR_LOGO								SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 11
#define SHOW_PIC_ADDR_ERROR								SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 12
#define SHOW_PIC_ADDR_SUCCEED							SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 13


//显示层级
unsigned char		g_show_live = 0;
//内部显示方案
char						g_show_scheme_id = 0;
//显示时长
unsigned char		g_show_time = 0;

//////////////////////////////////////////////////////////////////

//data末尾加上3个字节FONT_END的结束校验码
#pragma pack(1)
typedef struct FontHeader
{
	char			top[3];		  //头校验码
	unsigned short  byte_size;	  //长度
	char			weight;		  //宽度
	char			height;		  //高度
	char			key[2];		  //key
}FONT_HEADER_S;


//61显示图片
#pragma pack(1)
typedef struct DevShowPic
{
	MODEL_HEADER_S				header;			//协议头信息
	unsigned short				x;
	unsigned short				y;
	int										font_color;
	int										bg_color;
	unsigned char					clear;
	unsigned int					time;				//显示时长
}DEV_SHOW_PIC_H;

//63显示数字
#pragma pack(1)
typedef struct DevShowNum
{
	MODEL_HEADER_S				header;			//协议头信息
	unsigned short				x;
	unsigned short				y;
	int										font_color;
	int										bg_color;
	char									value[10];	//显示的文本
	unsigned char					clear;
	unsigned int					time;				//显示时长
}DEV_SHOW_NUM_H;

//字体
#pragma pack(1)
typedef struct FontNumIndex
{
	unsigned char					key;
	unsigned short				pos;
}FONT_NUM_INDEX_S;	

//图层显示时间 一秒运行一次
void show_check_time(void)
{
	if(g_show_live <= 1 || g_show_live == 0xFE)
		return;
	
	if(g_show_time <= 0)
	{
		SHOW_LIVE_CLEARE;
	}
	else
	{
		g_show_time--;
	}
}


//检查源格式是否正确
int show_check_pic_format(char *buff, int len)
{
	FONT_HEADER_S *info = 0;
	
	if(len < sizeof(FONT_HEADER_S) + sizeof(FONT_END))
		return 0;

	if(memcmp(buff, FONT_TOP, 3) != 0)
		return 0;
	if(memcmp(buff + len - 3, FONT_END, 3) != 0)
		return 0;
	
	info = (FONT_HEADER_S *)buff;
	if(info->byte_size != len)
		return 0;
	
	return 1;
}


//检查数字资源地址
uint32 show_check_num_address(char key)
{
	FONT_NUM_INDEX_S *index = (FONT_NUM_INDEX_S *)SHOW_FONT_FLASH_NUM_ADDRESS;
	int i = 0;
	
	for(; i < SHOW_FONT_FLASH_NUM_MAX_COUNT; i++)
	{
		if(index[i].key == key)
			return SHOW_FONT_FLASH_NUM_ADDRESS + index[i].pos;
	}	
	
	return 0;
}


//显示数字
int show_num_pic(char *text, int x, int y, uint16 bc, uint16 fc)
{
	int 					 i = 0;
	uint32 				 address = 0;
	FONT_HEADER_S *pic_info = 0;
	int 					 index_len = 0;
	int						 pos = 0;
	
	for(; i<10; i++)
	{
		if(text[i] == 0)
			return 1;
		
		address = show_check_num_address(text[i]);
		pic_info = (FONT_HEADER_S *)address;
			
		
		if(address != 0 && show_check_pic_format((char *)pic_info, pic_info->byte_size) == 1)
		{
			index_len = pic_info->weight * pic_info->height /8 +1;
			Gui_DrawFont_PIC(x + pos, y, pic_info->weight, pic_info->height, fc, bc, 
			(unsigned char *)pic_info + sizeof(FONT_HEADER_S),
			(unsigned char *)pic_info + sizeof(FONT_HEADER_S) + index_len, 
			pic_info->byte_size - sizeof(FONT_HEADER_S) - index_len);
			
			pos += (pic_info->weight + 5);
		}
	}
	return 1;
}





void show_mid_pic(int x, int y, int wight, int height, FONT_HEADER_S *pic_info, uint32 fc, uint32 bc)
{
	int index_len = 0;
	u16 bg_color = WHITE;
	u16 color = GRAY0;
	
	index_len = pic_info->weight * pic_info->height /8 +1;
	
	color = (BLUE * ((char *)(&fc))[2] / 255) |  
			((GREEN >> 5) * ((char *)(&fc))[1] / 255) << 5 | 
				((RED >> 11) * ((char *)(&fc))[0] / 255) << 11;
			
	bg_color = (BLUE * ((char *)(&bc))[2] / 255) |  
			((GREEN >> 5) * ((char *)(&bc))[1] / 255) << 5 | 
				((RED >> 11) * ((char *)(&bc))[0] / 255) << 11;
	
	Gui_DrawFont_PIC(x + (wight - pic_info->weight) / 2, 
	y + (height - pic_info->height) / 2, 
	pic_info->weight, pic_info->height, color, bg_color, 
	(unsigned char *)pic_info + sizeof(FONT_HEADER_S),
		(unsigned char *)pic_info + sizeof(FONT_HEADER_S) + index_len, 
			pic_info->byte_size - sizeof(FONT_HEADER_S) - index_len);
}

void show_left_pic(int x, int y, char *buff, uint16 fc, uint16 bc)
{

	FONT_HEADER_S *pic_info = (FONT_HEADER_S *)buff;
	int index_len = pic_info->weight * pic_info->height /8 +1;
	
	Gui_DrawFont_PIC(x,	y, pic_info->weight, pic_info->height, fc, bc, 
	(unsigned char *)pic_info + sizeof(FONT_HEADER_S),
		(unsigned char *)pic_info + sizeof(FONT_HEADER_S) + index_len, 
			pic_info->byte_size - sizeof(FONT_HEADER_S) - index_len);
}


int show_scheme(char scheme)
{
	//防止重复调用显示
	if(g_show_scheme_id == scheme)
		return 0;
	
	
	//显示除去
	if(scheme == 1)
	{
		if(g_show_live != 0xFE)
			Lcd_Clear(GRAY0);
		
		CHECK_SHOW_LIVE(0xFE);
		show_mid_pic(0, 0, 128, 90, (FONT_HEADER_S *)(SHOW_PIC_ADDR_NET_ERROR), 0x0011FF, 0x0);
		Gui_Clear_Rect(0, 90, 128, 128-90, 0x0);
		show_mid_pic(0, 80, 128, 128 - 90, (FONT_HEADER_S *)(SHOW_TXT_ADDR_INTO_INLINE), 0x0011FF, 0x0);
	}
	else if(scheme == 2)
	{
		if(g_show_live != 0xFE)
			Lcd_Clear(GRAY0);
		
		CHECK_SHOW_LIVE(0xFE);
		show_mid_pic(0, 0, 128, 90, (FONT_HEADER_S *)(SHOW_PIC_ADDR_NET_ERROR), 0xD0D0D0, 0x0);
		Gui_Clear_Rect(0, 90, 128, 128-90, 0x0);
		show_mid_pic(0, 80, 128, 128 - 90, (FONT_HEADER_S *)(SHOW_TXT_ADDR_CON), 0xD0D0D0, 0x0);
	}
	else if(scheme == 3)
	{
		if(g_show_live != 0xFE)
			Lcd_Clear(GRAY0);
		
		CHECK_SHOW_LIVE(0xFE);
		show_mid_pic(0, 0, 128, 90, (FONT_HEADER_S *)(SHOW_PIC_ADDR_NET_ERROR), 0xF0F0F0, 0x0);
		Gui_Clear_Rect(0, 90, 128, 128-90, 0x0);
		show_mid_pic(0, 80, 128, 128 - 90, (FONT_HEADER_S *)(SHOW_TXT_ADDR_SERVER), 0xF0F0F0, 0x0);
	}
	else if(scheme == 4)
	{
		if(g_show_live != 0xFE)
			Lcd_Clear(GRAY0);
		
		CHECK_SHOW_LIVE(0xFE);
		show_mid_pic(0, 0, 128, 90, (FONT_HEADER_S *)(SHOW_PIC_ADDR_NET_ERROR), 0x0011FF, 0x0);
		Gui_Clear_Rect(0, 90, 128, 128-90, 0x0);
		show_mid_pic(0, 80, 128, 128 - 90, (FONT_HEADER_S *)(SHOW_TXT_ADDR_NO_CONFIG), 0x0011FF, 0x0);
	}
	else if(scheme == 100)
	{
		CHECK_SHOW_LIVE(0x1);
		
		//显示LOGO的时候推送信息刷新二维码
		g_main_udp_push= ModelMakeHeader((char *)(g_main_udp_push_buff), 161, 0);
		Lcd_Clear(GRAY0);
		show_mid_pic(0, 0, 128, 128, (FONT_HEADER_S *)(SHOW_PIC_ADDR_LOGO), 0xFFFFFF, 0x0);
	}
	
	//////////////////////////////////////////////////////////////////////////定时显示
	else if(scheme == 5)
	{
		CHECK_SHOW_LIVE(0x3);
		
		g_show_time = 3;
		Lcd_Clear(GRAY0);
		show_mid_pic(0, 0, 128, 90, (FONT_HEADER_S *)(SHOW_PIC_ADDR_ERROR), 0x0011FF, 0x0);
		Gui_Clear_Rect(0, 90, 128, 128-90, 0x0);
		show_mid_pic(0, 80, 128, 128 - 90, (FONT_HEADER_S *)(SHOW_TXT_ADDR_INVALID_CARD), 0x0011FF, 0x0);
	}
	else if(scheme == 6)
	{
		CHECK_SHOW_LIVE(0x3);
		
		g_show_time = 3;
		Lcd_Clear(GRAY0);
		show_mid_pic(0, 0, 128, 90, (FONT_HEADER_S *)(SHOW_PIC_ADDR_ERROR), 0x0011FF, 0x0);
		Gui_Clear_Rect(0, 90, 128, 128-90, 0x0);
		show_mid_pic(0, 80, 128, 128 - 90, (FONT_HEADER_S *)(SHOW_TXT_ADDR_INVALID_FINGER), 0x0011FF, 0x0);
	}
	else if(scheme == 7)
	{
		CHECK_SHOW_LIVE(0x3);
		
		g_show_time = 3;
		Lcd_Clear(GRAY0);
		show_mid_pic(0, 0, 128, 90, (FONT_HEADER_S *)(SHOW_PIC_ADDR_ERROR), 0x0011FF, 0x0);
		Gui_Clear_Rect(0, 90, 128, 128-90, 0x0);
		show_mid_pic(0, 80, 128, 128 - 90, (FONT_HEADER_S *)(SHOW_TXT_ADDR_ERROR), 0x0011FF, 0x0);
	}
	else if(scheme == 8)
	{
		CHECK_SHOW_LIVE(0x3);
		
		g_show_time = 3;
		Lcd_Clear(GRAY0);
		show_mid_pic(0, 0, 128, 90, (FONT_HEADER_S *)(SHOW_PIC_ADDR_SUCCEED), 0x00FF11, 0x0);
		Gui_Clear_Rect(0, 90, 128, 128-90, 0x0);
		show_mid_pic(0, 80, 128, 128 - 90, (FONT_HEADER_S *)(SHOW_TXT_ADDR_SUCCEED), 0x00FF11, 0x0);
	}
	else if(scheme == 9)
	{
		CHECK_SHOW_LIVE(0x3);
		
		g_show_time = 3;
		Lcd_Clear(GRAY0);
		show_mid_pic(0, 0, 128, 90, (FONT_HEADER_S *)(SHOW_PIC_ADDR_ERROR), 0x0011FF, 0x0);
		Gui_Clear_Rect(0, 90, 128, 128-90, 0x0);
		show_mid_pic(0, 80, 128, 128 - 90, (FONT_HEADER_S *)(SHOW_TXT_ADDR_NET_ERROR), 0x0011FF, 0x0);
	}
	
	//记录显示方案
	g_show_scheme_id = scheme;
	return 1;
}






//检测是否进入待机状态(5秒检测一次待机状态)
void show_check_standby(void)
{
	if(g_time_now - g_draw_pic_time > 650)
	{
		g_send_len = ModelMakeInStandbyReq((char *)g_send_buff, g_draw_pic_number);
		UDP_PUSH;
		g_draw_pic_time = g_time_now;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//处理网络指令
int show_net_work(MODEL_HEADER_S *header, char *in_buff, int len, unsigned int *show_number)
{
	int 						index_len = 0;
	DEV_SHOW_PIC_H *show_info = 0;
	DEV_SHOW_NUM_H *show_num = 0;
	FONT_HEADER_S	 *pic_info  = 0;
	u16 						bg_color = GRAY0;
	u16 						color = WHITE;
	
	if(header->type == 61)
	{
		if(header->len <= sizeof(DEV_SHOW_PIC_H) + sizeof(FONT_HEADER_S))
			return 0;
		
		show_info = (DEV_SHOW_PIC_H *)in_buff;
		pic_info = (FONT_HEADER_S *)(in_buff + sizeof(DEV_SHOW_PIC_H));
		if(show_check_pic_format((char *)pic_info, len - sizeof(DEV_SHOW_PIC_H)) <= 0)
			return 0;
		
		//设置显示等级
		CHECK_SHOW_LIVE(2);
		g_show_time = show_info->time;
		g_show_scheme_id = 0;

		
		color = (BLUE * ((char *)(&show_info->font_color))[2] / 255) |  
			((GREEN >> 5) * ((char *)(&show_info->font_color))[1] / 255) << 5 | 
				((RED >> 11) * ((char *)(&show_info->font_color))[0] / 255) << 11;
			
		bg_color = (BLUE * ((char *)(&show_info->bg_color))[2] / 255) |  
			((GREEN >> 5) * ((char *)(&show_info->bg_color))[1] / 255) << 5 | 
				((RED >> 11) * ((char *)(&show_info->bg_color))[0] / 255) << 11;
			
		if(show_info->clear == 1)
		{
			Lcd_Clear(bg_color);
			delay_ms(50);
		}
			
		index_len = pic_info->weight * pic_info->height /8 +1;
		Gui_DrawFont_PIC(show_info->x, show_info->y, pic_info->weight, pic_info->height, color, bg_color, 
		(unsigned char *)pic_info + sizeof(FONT_HEADER_S),
		(unsigned char *)pic_info + sizeof(FONT_HEADER_S) + index_len, 
		pic_info->byte_size - sizeof(FONT_HEADER_S) - index_len);
	}
	else if(header->type == 63)
	{
		if(header->len < sizeof(DEV_SHOW_NUM_H))
			return 0;
		
		show_num = (DEV_SHOW_NUM_H *)in_buff;
		
		//设置显示等级
		CHECK_SHOW_LIVE(2);
		g_show_time = show_num->time;
		g_show_scheme_id = 0;

		//转换颜色
		color = (BLUE * ((char *)(&show_num->font_color))[2] / 255) |  
			((GREEN >> 5) * ((char *)(&show_num->font_color))[1] / 255) << 5 | 
				((RED >> 11) * ((char *)(&show_num->font_color))[0] / 255) << 11;
			
		bg_color = (BLUE * ((char *)(&show_num->bg_color))[2] / 255) |  
			((GREEN >> 5) * ((char *)(&show_num->bg_color))[1] / 255) << 5 | 
				((RED >> 11) * ((char *)(&show_num->bg_color))[0] / 255) << 11;
		if(show_num->clear == 1)
		{
			Lcd_Clear(bg_color);
			delay_ms(50);
		}
		
		//显示数字
		show_num_pic(show_num->value, show_num->x, show_num->y, bg_color, color);
	}
	else if(header->type == 65)
	{
		//获取显示序列号
		CHECK_SHOW_LIVE(2);
	}
	else if(header->type == 71)
	{
		SHOW_LIVE_CLEARE;
	}

	//返回显示状态码
	*show_number = g_draw_pic_number;
	return 1;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
////配置信息

//void show_write_falsh(char *buff, int len)
//{
//	int i = 0;
//	uint32_t address = SHOW_FONT_FLASH_FALSH_ADDRESS;
//	FONT_HEADER_S *info = (FONT_HEADER_S *)buff;
//	
//	g_show_printf = 1;
//	
//	if(info->key[1] < SHOW_FONT_FLASH_FALSH_KEY_START || info->key[1] > SHOW_FONT_FLASH_FALSH_KEY_END)
//	{
//		printf("write font key error:%d\r\n", info->key[1]);
//		return;
//	}
//	if(info->byte_size <= 0 || info->byte_size > SHOW_FONT_FLASH_FALSH_SIZE)
//	{
//		printf("write font size error:%d\r\n", info->byte_size);
//		return;
//	}
//	
//	address = SHOW_FONT_FLASH_FALSH_ADDRESS + (info->key[1] - SHOW_FONT_FLASH_FALSH_KEY_START) * SHOW_FONT_FLASH_FALSH_SIZE;
//	FLASH_Unlock();
//	FLASH_ErasePage(address);
//	for(i = 0; i < (info->byte_size + 1) / 2; i++) {
//		FLASH_ProgramHalfWord(address + i * 2, *(u16 *)(buff + i * 2));
//	}
//	FLASH_Lock();
//	
//	info = (FONT_HEADER_S *)address;
//	printf("write font sucess address:%d-len:%d\r\n", info->key[1], info->byte_size);
//}

//int show_num_write_falsh(char *buff, int len)
//{
//	int 	i = 0;
//	int 	n = 0;
//	char  *pos_addr = (char  *)SHOW_FONT_FLASH_NUM_ADDRESS;
//	char  *pos_buff = buff + 3;
//	int   size_item = 0;
//	
//	if(buff == NULL || len < 300 || memcmp(buff, FONT_NUM_WRITE_TOP, 3) != 0 || memcmp(buff + len - 3, FONT_NUM_WRITE_END, 3) != 0)
//		return 0;
//	
//	FLASH_Unlock();
//	for(n = 0; n < (len - 6 + 2047) / 2048; n++)
//	{
//		if((len - 6 - n * 2048 + 1) > 2048)
//			size_item = 1024;
//		else
//			size_item = (len - 6 - n * 2048 + 1)/2;
//		
//		FLASH_ErasePage((uint32)pos_addr);
//		for(i = 0; i < size_item; i++) {
//			FLASH_ProgramHalfWord((uint32)pos_addr, *((uint16 *)pos_buff));
//			pos_addr += 2;
//			pos_buff += 2;
//		}
//	}
//	FLASH_Lock();

//	g_show_printf = 1;
//	printf("write font num sucess len:%lu\r\n", (uint32)pos_addr - SHOW_FONT_FLASH_NUM_ADDRESS);
//	return 1;
//}



