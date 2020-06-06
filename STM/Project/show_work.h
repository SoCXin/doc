#ifndef SHOW_WORK_H
#define SHOW_WORK_H

#include "model.h"
#include "Types.h"

//字库基础配置
#define SHOW_FONT_FLASH_FALSH_ADDRESS			0x8010000
#define SHOW_FONT_FLASH_FALSH_KEY_START		101
#define SHOW_FONT_FLASH_FALSH_KEY_END			120
#define SHOW_FONT_FLASH_FALSH_SIZE				2048

//给力量器械准备的狗逼图标
#define SHOW_PIC_ADDR_CI									SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 14
#define SHOW_PIC_ADDR_KG									SHOW_FONT_FLASH_FALSH_ADDRESS + SHOW_FONT_FLASH_FALSH_SIZE * 15


#define   SHOW_INTO_LINE				show_scheme(1);	 	//未插入网线
#define   SHOW_ERROR_CON				show_scheme(2);	 	//未连接上控制器
#define   SHOW_ERROR_SERVER			show_scheme(3);		//未连接服务器
#define   SHOW_NO_CONFIG				show_scheme(4);	 	//没有配置信息

//显示3秒
#define   SHOW_RFID_ERROR				show_scheme(5);	 	//卡号错误
#define   SHOW_FINGER_ERROR			show_scheme(6);	 	//指纹错误
#define   SHOW_MSG_ERROR				show_scheme(7);	 	//错误
#define   SHOW_SUCCEED					show_scheme(8);		//验证成功
#define   SHOW_NET_ERROR				show_scheme(9);		//网络错误

#define   SHOW_LOGO							show_scheme(100);	//默认显示LOGO

//显示层级
extern unsigned char		g_show_live;
//内部显示方案
extern char	g_show_scheme_id;
//显示时长
extern unsigned char		g_show_time;

//判断窗口层级
#define		CHECK_SHOW_LIVE(l)				if(l < g_show_live)\
	return 0;\
else\
	g_show_live = l;

//清理窗口
#define		SHOW_LIVE_CLEARE					{g_show_live = 0;g_show_scheme_id = 0;}


int show_net_work(MODEL_HEADER_S *header, char *in_buff, int len, unsigned int *show_number);

int show_check_pic_format(char *buff, int len);

int show_scheme(char scheme);

void show_check_time(void);

//测试是否进入待机状态
void show_check_standby(void);

//显示图标靠左
void show_left_pic(int x, int y, char *buff, uint16 fc, uint16 bc);

//显示数字
int show_num_pic(char *text, int x, int y, uint16 bc, uint16 fc);

////写字库
//void show_write_falsh(char *buff, int len);

////写数字字库
//int show_num_write_falsh(char *buff, int len);


#endif
