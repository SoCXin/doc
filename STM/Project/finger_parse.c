#include "finger_parse.h"
#include "usart.h"
#include "user_config.h"
#include "string.h"
#include "udp_tool.h"
#include "model.h"
#include "Finger.h"
#include "led_beep.h"
#include "Relay.h"
#include "systick.h"

uint32	g_rs232_package_num = 1;
char		g_finger_parge_ext_first = 0;
uint32  g_last_wake_up_finger_time = 0;

//只有门禁设备才能装指纹
void eg_finger_init(void)
{
	
	//限制门禁设备才能用指纹模块
	if(g_user_config.type != 1) 
		return;
	
	////////////////定时维护下指纹模块-不要掉线
	if((g_finger_is == 0 && g_time_now - g_last_wake_up_finger_time >= 500) || 
		(g_time_now - g_last_wake_up_finger_time >= 60000))
	{
		g_last_wake_up_finger_time = g_time_now;
		g_send_len = FingerMakeBuff((unsigned char *)g_send_buff, FINGER_SYS_STATUS, 0, 0, 0);
		sendDatatoTTL((char *)g_send_buff, g_send_len);
		g_send_len = 0;
	}
}

int eg_finger_parse(void)
{
	FINGER_HEADER_S *finger_header = 0;
	char					 	*content_buff = 0;
	int 		 				 content_len = 0;
	
	
	//限制门禁设备才能用指纹模块
	if(g_user_config.type != 1) 
		return 0;
	

	//解析详细情况
	if((finger_header = FingerCheckBuff((unsigned char *)g_rev_buff, g_rev_len, 
		&content_buff, &content_len, g_rs232_package_num, g_finger_parge_ext_first)) != 0)
	{
		//没有接收完需要继续接收
		if(content_len == -1)
			return 0;
		
		g_send_len = 0;
		
		if(finger_header->command != 0)
		{
			//包序加1
			g_rs232_package_num ++ ;
			//安装指纹模块
			g_finger_is = 1;
			//扩展协议接收重置
			g_finger_parge_ext_first = 0;
			
			//主动按指纹
			if(finger_header->command == FINGER_IDENTIFY_FREE)
			{
				if(finger_header->flag == 0x61)
				{
					GROUP_PRO_FINGER;
					g_send_len = ModelMakeFingerReq((char *)g_send_buff, (short)finger_header->param);
					UDP_PUSH;
				}
				else
				{
					GROUP_PRO_FAILED;
				}
			}
			
			//添加用户
			else if(finger_header->command == 0x17)
			{
				g_send_len = ModelMakeCodeAck((char *)g_send_buff, 102, finger_header->flag);
			}
			
			//删除用户
			else if(finger_header->command == 0xF3)
			{
				g_send_len = ModelMakeCodeAck((char *)g_send_buff, 104, finger_header->flag);
			}
			
			//指纹登记结果
			else if(finger_header->command == 0x15)
			{
				g_finger_ing = 0;
				
				if(finger_header->flag == 0x61)
				{
					GROUP_PRO_SUCCEED;
				}
				else
				{
					GROUP_PRO_FAILED;
				}
				
				g_send_len = ModelMakeFingerScanReq((char *)g_send_buff, finger_header->param & 0xFF, finger_header->flag == 0x61 ? 1:0);
				UDP_PUSH;
			}
			
			//读取指纹模板
			else if(finger_header->command == 0x89)
			{
				if(finger_header->flag != 0x61)
					g_send_len = ModelMakeFingerTmpAck((char *)g_send_buff, (char *)g_rev_buff + 26, 0);
				else
					g_send_len = ModelMakeFingerTmpAck((char *)g_send_buff, (char *)g_rev_buff + 26, (finger_header->param & 0xFFFF) + 4);
			}
			
			//设备复位
			else if(finger_header->command == 0xD0)
			{
				g_send_len = ModelMakeCodeAck((char *)g_send_buff, 112, finger_header->flag);
			}
			
			//删除所有的用户
			else if(finger_header->command == 0xF5)
			{
				g_send_len = ModelMakeCodeAck((char *)g_send_buff, 114, finger_header->flag);
			}
			
			//删除数据库
			else if(finger_header->command == 0xF8)
			{
				g_send_len = ModelMakeCodeAck((char *)g_send_buff, 114, finger_header->flag);
			}
			
			//读取所有的用户
			else if(finger_header->command == 0xA0)
			{
				if(content_len > 17)
				{
					g_send_len = ModelMakeHeader((char *)g_send_buff, 110, content_len);
					memcpy(g_send_buff + g_send_len, content_buff, content_len);
					g_send_len += content_len;
					UDP_SYNC_ACK;
					delay_ms(100);
				}
				
				g_rev_len = 0;
				g_data_type = 0;
				if(content_len > 17 && 
					(finger_header->flag == 0x61 || finger_header->flag == 0) && 
					(*(short *)(content_buff+2)) - 1 > *(short *)(content_buff+4))
				{
					FingerCheckMore(0xA0, *(short *)(content_buff+2), *(short *)(content_buff+4));
					delay_ms(10);
				}
				else
				{
					FingerCheckMore(0xA0, 0, 0);
					g_send_len = ModelMakeCodeAck((char *)g_send_buff, 110, 0);
				}
			}
			
			//获取指纹模块状态
			else if(finger_header->command == 0x14)
			{
				if((g_time_now - g_last_wake_up_finger_time) > 10)
				{
					g_send_len = ModelMakeCodeAck((char *)g_send_buff, 116, finger_header->param);
				}
			}
		}
		
		UDP_SYNC_ACK;
		return 1;
	}
	
	return 0;
}

int eg_finger_net_comment(unsigned char type, unsigned char *content_buff, int content_len,
	unsigned char *out_buff, unsigned short *out_len, unsigned char *ip, unsigned short port)
{
	unsigned int tmp_num_32 = 0;
	
	//添加指纹
	if (type == 101)
	{
		if(content_len > 200)
		{
			tmp_num_32 = *((uint16_t *)content_buff);
			
			if(tmp_num_32 > 0 && 
				tmp_num_32 < 2000 && 
				FingerCheckTmp((unsigned char *)(content_buff + 2), content_len-2) == 1){
				
					g_send_len = FingerMakeBuff((unsigned char *)g_send_buff, 0x17, (char *)&tmp_num_32, content_len-2, 0x71);
					memcpy(out_buff + g_send_len, content_buff + 2, content_len-2);
					g_send_len += content_len-2;
					
					TTL_SYNC_SEND(ip, port);
					return 1;
			}
		}
		
		*out_len = ModelMakeCodeAck((char *)out_buff, 102, 0);
	}
	
	//删除用户
	else if (type == 103)
	{
		if(content_len >= 2)
		{
			tmp_num_32 = *((uint16_t *)content_buff);
			g_send_len = FingerMakeBuff((unsigned char *)g_send_buff, 0xF3, (char *)&tmp_num_32, 0, 0);
			TTL_SYNC_SEND(ip, port);
		}
	}
	
	//进入录入指纹
	else if (type == 105)
	{
		if(g_finger_ing <= 0)
		{
			if(content_len >= 2)
			{
				tmp_num_32 = *((uint16_t *)content_buff);
		
				//删除进入录入模式
				g_send_len = FingerMakeBuff((unsigned char *)g_send_buff, 0x15, (char *)&tmp_num_32, 0, 0x71);
				TTL_SYNC_SEND(ip, port);
			
				g_finger_ing = 150;
				GROUP_PRO_FINGER;
			}
			*out_len = ModelMakeCodeAck((char *)out_buff, 106, content_len >= 2  ? 1:0);
		}
		else
		{
			*out_len = ModelMakeCodeAck((char *)out_buff, 106, 5);
		}
	}
	
	//读取模板
	else if (type == 107)
	{
		if(content_len >= 2)
		{
			tmp_num_32 = *((uint16_t *)content_buff);
			g_send_len = FingerMakeBuff((unsigned char *)g_send_buff, 0x89, (char *)&tmp_num_32, 0, 1);
			TTL_SYNC_SEND(ip, port);
		}
	}
	
	//读取指纹器所有的用户
	else if (type == 109)
	{
		tmp_num_32 = 4000;
		g_send_len = FingerMakeBuff((unsigned char *)g_send_buff, 0xA0, (char *)&tmp_num_32, 0, 0);
		g_finger_parge_ext_first = 1;
		TTL_SYNC_SEND(ip, port);
	}
	
	//指纹复位
	else if (type == 111)
	{
		g_send_len = FingerMakeBuff((unsigned char *)g_send_buff, 0xD0, 0, 0, 0);
		TTL_SYNC_SEND(ip, port);
	}
	
	//删除所有的用户
	else if (type == 113)
	{
		g_send_len = FingerMakeBuff((unsigned char *)g_send_buff, 0xF8, 0, 0, 0); //0xF5
		TTL_SYNC_SEND(ip, port);
	}

	//获取指纹模块状态
	else if (type == 115)
	{
		g_send_len = FingerMakeBuff((unsigned char *)g_send_buff, 0x14, 0, 0, 0);
		TTL_SYNC_SEND(ip, port);
	}
	else
	{
		return 0;
	}
	
	return 1;
}
