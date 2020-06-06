#include "work_232.h"
#include "usart.h"
#include "user_config.h"
#include "string.h"
#include "udp_tool.h"
#include "model.h"
#include "work_net.h"
#include "show_work.h"
#include "strength.h"
#include "finger_parse.h"
#include "work_rfid.h"
#include "led_beep.h"

#define QR_START			"qr_egqr_egqr_eg"
#define QR_END				"qr_endqr_endqr_end"
#define QR_LEN				33
#define RFID_START		"rfid_egrfid_egrfid_eg"
#define RFID_END			"rfid_endrfid_endrfid_end"
#define RFID_LEN			45

void USART2_IRQHandler(void)
{
  if(USART_GetITStatus(USART_232, USART_IT_RXNE) != RESET)
  { 	
		//USART1->DR = USART_ReceiveData(USART_232);//将接受到的数据直接返回打印
		uint8 byte = USART_ReceiveData(USART_232);
		
		//接收网络数据
		if(g_data_type <= DATA_TYPE_232)
		{
			
//			//需要单独处理下力量器械的数据
//			if(eg_strength_add_data(byte) == 1) {
//				return;
//			}
			
			//防止数据越界
			if(g_rev_len >= BUFF_LEN)
					return;
			
			//挤掉低级数据
			if(g_data_type != DATA_TYPE_232)
				g_rev_len = 0;
			
			g_rev_buff[g_rev_len] = byte;
			g_rev_len++;
			g_data_type = DATA_TYPE_232;
			g_data_time = g_time_now;
		}
  } 
}


int eg_232_loop(void)
{
	if(g_data_type != DATA_TYPE_232)
		return 0;
	
	////////////////////////////////////////////////////////////////////////////刷卡
	if(eg_rfid_7941D3_ttl_read((unsigned char *)g_rev_buff, g_rev_len) == 1)
	{
		eg_clear_data();
		return 1;
	}
	
	/////////////////////////////////////////////////////解析二维码
	if(g_rev_len > QR_LEN && memcmp(g_rev_buff, QR_START, 15) == 0 && memcmp(g_rev_buff + g_rev_len - 18, QR_END, 18) == 0)
	{
		if(g_rev_len - QR_LEN <= 500) 
		{
			g_rev_buff[g_rev_len-18] = 0;
			sprintf((char *)g_send_buff, "{\"qr\":\"%s\"}", (char *)g_rev_buff + 15);
			strncpy((char *)g_rev_buff, (char *)g_send_buff, BUFF_LEN - 100);
			
			//sendDatatoTTL((char *)g_rev_buff, strlen((char *)g_rev_buff)); //测试输出
			BEEP_PRO_S;
		
			g_send_len = ModelMakeUserPushReq((char *)g_send_buff, (char *)g_rev_buff, strlen((char *)g_rev_buff));
			eg_upd_sendto(g_send_buff, g_send_len, g_server_ip, g_server_push_port);
		}
		
		eg_clear_data();
		return 1;
	}
	
	///////////////////////////////////////////////////////解析RFID
	if(g_rev_len > RFID_LEN && memcmp(g_rev_buff, RFID_START, 21) == 0 && memcmp(g_rev_buff + g_rev_len - 24, RFID_END, 24) == 0)
	{
		if(g_rev_len - RFID_LEN <= 500) 
		{
			g_rev_buff[g_rev_len - 24] = 0;
			sprintf((char *)g_send_buff, "{\"rfid\":\"%s\"}", (char *)g_rev_buff + 21);
			strncpy((char *)g_rev_buff, (char *)g_send_buff, BUFF_LEN - 100);
		
			g_send_len = ModelMakeUserPushReq((char *)g_send_buff, (char *)g_rev_buff, strlen((char *)g_rev_buff));
			eg_upd_sendto(g_send_buff, g_send_len, g_server_ip, g_server_push_port);
		}
		
		eg_clear_data();
		return 1;
	}
	
	///////////////////////////////////////////////////////////默认收到的数据都透传出去
	if(g_user_config.type != 1 && g_time_now - g_data_time > 20)
	{
		g_send_len = ModelMakePush232ExtReq((char *)g_send_buff, (char *)g_rev_buff, g_rev_len);
		UDP_PUSH;
		
		eg_clear_data();
		return 1;
	}
	
	return 0;
}
