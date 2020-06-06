#include "work_rfid.h"
#include "SYSTICK.H"
#include "usart.h"
#include "Types.h"
#include "user_config.h"
#include "led_beep.h"
#include "model.h"


// RFID_UID[0], RFID_UID[1], RFID_UID[2], RFID_UID[3]
void eg_rfid_work(unsigned char *buff)
{
	char rfid_x16[10];

	//GROUP_PRO_RFID;
	
	sprintf(rfid_x16, "%02X%02X%02X%02X", buff[0], buff[1], buff[2], buff[3]);
	
	g_send_len = ModelMakeRfidReq((char *)g_send_buff, (char *)rfid_x16);
	UDP_PUSH;
}

int eg_rfid_7941D3_ttl_read(unsigned char *buff, int len)
{
	int i = 0;
	unsigned char code = 0;
	unsigned char num_code[4];
	
	if(len != 9 && len != 10)
		return 0;
	if(buff[0] != 0x02 || buff[len - 1] != 0x03)
		return 0;
	
	//校验数据
	for(i=1; i < len - 2; i++)
		code ^= buff[i];
	if(code != buff[len - 2])
		return 1;
	
	//反序
	num_code[0] = buff[len - 6 + 3];
	num_code[1] = buff[len - 6 + 2];
	num_code[2] = buff[len - 6 + 1];
	num_code[3] = buff[len - 6 + 0];
	
	//RFID提示
	GROUP_PRO_RFID;
	
	//发送到网络
	eg_rfid_work(num_code);
	return 1;
}
