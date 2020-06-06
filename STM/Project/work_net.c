#include "work_net.h"
#include "model.h"
#include "user_config.h"
#include "udp_tool.h"
#include "led_beep.h"
#include "Relay.h"
#include "w5500_conf.h"
#include "Finger.h"
#include "work_ttl.h"
#include "work_232.h"
#include "voice.h"
#include "exti.h"
#include "show_work.h"
#include "strength.h"
#include "finger_parse.h"
#include "SYSTICK.h"
#include "strength_lp.h"
#include "beep.h"
#include "work_btn.h"

int eg_net_loop(void)
{
	uint8			net_recv_ip[4];
	uint16		net_recv_port = 0;
	int 			work_net_code = 0;
	uint16		net_recv_len = 0;	
	if(g_main_udp_push > 0)
	{
		eg_upd_sendto(g_main_udp_push_buff, g_main_udp_push, g_server_ip, g_server_push_port);
		g_main_udp_push = 0;
	}	
	//接收长数据包用的-可能会拆分成多个包
	if(g_data_type <= DATA_TYPE_NET_LONG)
	{
		net_recv_port = 0;
		memset(net_recv_ip, 0, sizeof(net_recv_ip));
		if(g_data_type == DATA_TYPE_NET_LONG)
		{
			net_recv_len = eg_upd_long_recvfrom(g_rev_buff + g_rev_len, BUFF_LEN - g_rev_len, net_recv_ip, &net_recv_port);
		}
		else
		{
			net_recv_len = eg_upd_long_recvfrom(g_rev_buff, BUFF_LEN, net_recv_ip, &net_recv_port);
		}		
		if(net_recv_len > 0)
		{
			if(g_data_type == DATA_TYPE_NET_LONG)
				g_rev_len += net_recv_len;
			else
				g_rev_len = net_recv_len;
			
			g_data_type = DATA_TYPE_NET_LONG;
			g_data_time = g_time_now;
		}
	}	
	//接收普通网络包
	if(g_data_type <= DATA_TYPE_NET)
	{
		net_recv_port = 0;
		memset(net_recv_ip, 0, sizeof(net_recv_ip));
		if((net_recv_len = eg_upd_recvfrom(g_rev_buff, BUFF_LEN, net_recv_ip, &net_recv_port)) > 0)
		{
			g_rev_len = net_recv_len;
			g_data_type = DATA_TYPE_NET;
			g_data_time = g_time_now;
		}
	}		
	//解析网络数据
	if(g_data_type == DATA_TYPE_NET || g_data_type == DATA_TYPE_NET_LONG) 
	{
		work_net_code = eg_work_net(g_rev_buff, g_rev_len, g_send_buff, &g_send_len, net_recv_ip, net_recv_port);
		if(work_net_code == -1)
		{
			//数据没获取完
			return -1;
		}
		else if(work_net_code == 1)
		{
			//返回网络数据
			if(g_send_len > 0 && net_recv_port != 0)
				eg_upd_sendto(g_send_buff, g_send_len, net_recv_ip, net_recv_port);
			eg_clear_data();
			return 1;
		}
		else
		{
			eg_clear_data();
			return 0;
		}
	}	
	return 0;
}



int eg_work_net(uint8 *in_buff, uint16 in_len, uint8 *out_buff, uint16 *out_len, uint8 *ip, uint16 port)
{
	char						*content_buff = 0;
	int 		 				 content_len 	= 0;
	uint32_t 				 tmp_num_32 	= 0;
	MODEL_HEADER_S 	*header 			= 0;
	uint8						 tmp_ret 			= 0;
	
	//解析数据
	header = ModelCheckBuff((char *)in_buff, in_len, &content_buff, &content_len);
	if(content_len == -1)
		return -1;
	if(header == 0 || header->type == 0)
		return 1;
	
	////////////////////////////////////////////////////////
	
	*out_len = 0;
	
	//心跳信息检测
	if (header->type == 1)
	{
		
		if(in_len >= sizeof(DEV_ID_REQ_S))
		{
			DEV_ID_REQ_S *devIdReq = (DEV_ID_REQ_S *)in_buff;
			if (devIdReq->isRegServer == 1)
			{
				memcpy(g_server_ip, ip, 4);
				g_server_port = port;
				g_server_push_port = devIdReq->port;
				g_iot_status = devIdReq->isIotOK;
				g_heart_client = g_time_now;
				g_dog_client_time = g_time_now;
			}
		}
		g_heart_server = g_time_now;
		
		*out_len = ModelMakeDevIdAck((char *)out_buff, g_user_config.device_id, g_user_config.device_se, g_finger_is, g_user_config.type);
	}
	
	//获取转换器本身信息
	else if (header->type == 5)
	{
		//基础信息
		DEV_INFO_ACK_S info;
		memset(&info, 0, sizeof(info));
		info.relay1 = Relay_Status(1);
		info.relay2 = Relay_Status(2);
		info.isWifi =0;
		info.hummer = eg_beep_status();
		info.isCardReader = g_have_rfid;
		strncpy(info.ip, get_w5500_ip(), sizeof(info.ip) - 1);
		info.isFinger = g_finger_is;
		strncpy(info.codeVersion, CODE_VERSION, sizeof(info.codeVersion) - 1);
		info.clientType = g_user_config.type;
		
		*out_len = ModelMakeInfoAck((char *)out_buff, &info);
	}
	
	//配置信息
	else if (header->type == 7)
	{
		char code = 0;
		if(content_buff != 0 &&
			content_len > WRITE_USER_CONFIG_LEN && 
			memcmp(content_buff, WRITE_USER_CONFIG_START, 5) == 0 &&
 		  memcmp(content_buff + content_len - 5, WRITE_USER_CONFIG_END, 5) == 0)
		{
			if(content_len < 1024)
			{
				code = user_set_config((char *)((char *)content_buff + 5), content_len - WRITE_USER_CONFIG_LEN);	
			}
		}
		*out_len = ModelMakeCodeAck((char *)out_buff, 8, code);
	}

	//继电器控制
	else if (header->type == 51)
	{
		if(in_len >= sizeof(DEV_CON_RELAY_REQ_S))
		{
			DEV_CON_RELAY_REQ_S *conRelayReq = (DEV_CON_RELAY_REQ_S *)in_buff;
			if(conRelayReq->relayId == 0) 
			{
				if(conRelayReq->control == 0) 
				{
					REALY0_OFF;
				}
				else
				{
					REALY0_ON;
					g_replay_time = conRelayReq->duration > 0 ? conRelayReq->duration * 100 : 100;
				}
			}
			else
			{
				if(conRelayReq->control == 0) 
				{
					REALY1_OFF; 
				}
				else 
				{
					REALY1_ON;
					GROUP_PRO_NET_SUCCEED;
					g_replay_time = conRelayReq->duration > 0 ? conRelayReq->duration * 100 : 100;
				}
			}
		}
		
		*out_len = ModelMakeConRelayAck((char *)out_buff);
	}
	
	//蜂鸣器控制
	else if (header->type == 53)
	{
		if(in_len >= sizeof(DEV_CON_BUZZER_REQ_S))
		{
			DEV_CON_BUZZER_REQ_S *conBuzzerReq = (DEV_CON_BUZZER_REQ_S *)in_buff;
			CON_BEEP(conBuzzerReq->plan);
		}
		
		*out_len = ModelMakeConBuzzerAck((char *)out_buff);
	}
	
	//组合交互控制
	else if (header->type == 55)
	{
		
	  if(in_len >= sizeof(DEV_CON_GROUP_REQ_S))
		{
			DEV_CON_GROUP_REQ_S *conGroupReq = (DEV_CON_GROUP_REQ_S *)in_buff;
			switch(conGroupReq->plan){
				case 1:
					GROUP_PRO_FAILED;
					break;
				case 2:
					GROUP_PRO_SUCCEED;
					break;
				case 3:
					GROUP_PRO_RFID;
					break;
				case 4:
					GROUP_PRO_FINGER;
					break;
				case 5:
					GROUP_PRO_BTN;
					break;
				case 6:
					GROUP_PRO_NET_FAILED;
					break;
				case 7:
					GROUP_PRO_NET_SUCCEED;
					break;
			}
		}

		*out_len = ModelMakeConGroupAck((char *)out_buff);
	}
	
	//播放录音
	else if (header->type == 57)
	{
	  if(in_len >= sizeof(DEV_VOICE_REQ_S))
		{
			//DEV_VOICE_REQ_S *voice = (DEV_VOICE_REQ_S *)in_buff;
			//Voice_Show((int)voice->num);
		}
		*out_len = ModelMakeHeader((char *)out_buff, 58, 0);
		
	}
	
	//显示
	else if ((header->type >= 59 && header->type <= 65) || header->type == 69 || header->type == 71)
	{
		tmp_num_32 = 0;
		tmp_ret = show_net_work(header, (char *)in_buff, in_len, &tmp_num_32);
		
		//返回显示结果
		*out_len = ModelMakeHeader((char *)out_buff, header->type + 1, 5);
		*((unsigned char *)(out_buff + *out_len)) = tmp_ret;
		*((unsigned int *)(out_buff + *out_len + 1)) = tmp_num_32;
		*out_len += 5;
	}
	
	//同步力量器械状态
	else if (header->type == 73)
	{
		eg_strength_sync_status(content_len >= 1 ? content_buff[0] : 0, 
		content_len >= 5 ? *(unsigned int *)(content_buff + 1) : 0, out_buff, out_len);
	}
	
	//光感力量器械同步状态
	else if (header->type == 75)
	{
		int code = 0;
		if(in_len >= sizeof(DEV_STRENGTH_PL_REQ_S))
		{
			//DEV_STRENGTH_PL_REQ_S *info = (DEV_STRENGTH_PL_REQ_S *)in_buff;
			//code = eg_strength_lp_net_set_status(info->status, info->space_time, info->one_time, info->beep);
		}
		*out_len = ModelMakeCodeAck((char *)out_buff, 76, code);
	}
	
	//设置计数器灵敏度
	else if (header->type == 77)
	{
		int code = 0;
		if(content_buff != 0 && content_len >= 2)
		{
			unsigned short limit = *(unsigned short *)content_buff;
			if(limit > 0 && limit < 1000) 
			{
				g_btn1_limit_time = limit;
				code = 1;
			}
		}
		*out_len = ModelMakeCodeAck((char *)out_buff, 78, code);
	}
	
	

	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//解析指纹相关指令
	else if(eg_finger_net_comment(header->type, (unsigned char *)content_buff, content_len, out_buff, out_len, ip, port) == 1)
	{
		//解析指纹数据
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//RFID刷卡推送返回结果
	else if(header->type == 152)
	{
		if(header->len >= sizeof(MODEL_CODE_S))
		{
			MODEL_CODE_S *model_code = (MODEL_CODE_S *)in_buff;
			if(model_code->code == 0)
			{
				GROUP_PRO_FAILED;
				REALY0_OFF;
				SHOW_RFID_ERROR;
			}
			else if(model_code->code == 1)
			{
				GROUP_PRO_SUCCEED;
				REALY0_ON;
				SHOW_SUCCEED;
			}
			else if(model_code->code == 2)
			{
				GROUP_PRO_NET_FAILED;
				SHOW_RFID_ERROR;
			}
			else if(model_code->code == 3)
			{
				GROUP_PRO_NET_SUCCEED;
				SHOW_SUCCEED;
			}
			else if(model_code->code == 4)
			{
				GROUP_PRO_NET_FAILED;
				SHOW_NET_ERROR;
			}
			else
			{
				GROUP_PRO_FAILED;
				REALY0_OFF;
				REALY1_OFF;
				SHOW_RFID_ERROR;
			}
			
			if(g_user_config.type == 1)
				g_replay_time = 10;
		}
		*out_len  = 0;
	}
	
	//指纹网络验证结果
	else if(header->type == 154)
	{
		if(header->len >= sizeof(MODEL_CODE_S))
		{
			MODEL_CODE_S *model_code = (MODEL_CODE_S *)in_buff;
			if(model_code->code == 0)
			{
				GROUP_PRO_FAILED;
				REALY0_OFF;
				SHOW_FINGER_ERROR;
			}
			else if(model_code->code == 1)
			{
				GROUP_PRO_SUCCEED;
				REALY0_ON;
				SHOW_SUCCEED;
			}
			else if(model_code->code == 2)
			{
				GROUP_PRO_NET_FAILED;
				SHOW_FINGER_ERROR;
			}
			else if(model_code->code == 3)
			{
				GROUP_PRO_NET_SUCCEED;
				SHOW_SUCCEED;
			}
			else if(model_code->code == 4)
			{
				GROUP_PRO_NET_FAILED;
				SHOW_NET_ERROR;
			}
			else
			{
				GROUP_PRO_FAILED;
				REALY0_OFF;
				REALY1_OFF;
				SHOW_FINGER_ERROR;
			}
			if(g_user_config.type == 1)
				g_replay_time = 10;
		}
		*out_len  = 0;
	}

	//TTL串口透传
	else if (header->type == 251)
	{
		sendDatatoTTL(content_buff, content_len);
		*out_len = ModelMakeExtAck((char *)out_buff);
	}
	
	//232串口透传
	else if (header->type == 253)
	{
		if(g_user_config.type == 2)		//无线衣柜这狗逼，这里处理得有点垃圾了
		{
			REALY0_ON;
			g_replay_time = 300;
			delay_ms(100);
			sendDatatoTTL(content_buff, content_len);
		}
		else
		{
			sendDatatoRS232(content_buff, content_len);
		}
		*out_len = ModelMakeExtAck((char *)out_buff);
	}
	
	return 1;
}
