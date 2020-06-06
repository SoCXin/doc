#include "Finger.h"
#include "usart.h"
#include <string.h>
#include "user_config.h"

#define MD_EXT_DATA					0x80
#define MD_DATA_ERROR				0x82
#define MD_DATA_OK					0x83

int g_package_num = 0;
int g_finger_ing = 0;

FINGER_HEADER_S *FingerCheckBuff(const unsigned char *buff, const int len, char **contentBuff, int *contentLen, int package_num, char ext)
{
	
	int i=0;
	unsigned char check_c = 0;
	FINGER_HEADER_S *header = 0;
	
	if(len < 13)
		return 0;
	
	if(buff[0] != FINGER_START)
		return 0;
	
	if(buff[12] != 0x00 && buff[12] != FINGER_END)
		return 0;
	
	//校验
	for(i=0; i<11; i++)
		check_c += buff[i];
	if(check_c != buff[11])
		return 0;
	
	header = (FINGER_HEADER_S*)buff;
	if(header->flag == 0x61 || header->flag == 0x0) 
	{
		//模板需要附加数据处理
		if(buff[1] == 0x89)
		{
			if(g_package_num != package_num)
			{
			  g_package_num = package_num;
				FingerCheckMore(buff[1], 1, 0);
			}
			
			//数据包不完整
			if(len-13 < (header->param & 0xFFFF) + 17) //为啥是17，因为有他妈4字节的校验位不计算在长度里面
				*contentLen = -1;
		}
		
		//获取所有用户也需要附加数据处理
		else if(buff[1] == 0xA0)
		{
			if(header->param <= 0)
				return header;
		
			*contentLen = -1;
			
			if(ext == 1) //妈卖批的第一次获取到的包有个头，多13字节
			{
				if(len >= 26)
				{
					header = (FINGER_HEADER_S*)(buff + 13);
					if(len-26 >= header->size)
					{
						*contentBuff = (char *)(buff + 13);
						*contentLen = header->size + 13;
					}
				}
			}
			else if(len-13 >= header->size)
			{
				*contentBuff = (char *)buff;
				*contentLen = header->size + 13;
			}
		}
	}
	
	return header;
}

void FingerCheckMore(unsigned char command, short num, short index)
{
	
	FINGER_EXT_HEADER_S finger_ext;
	int len = 0;
	static uint32_t last_post_error = 0;
	
	if(num <= 0 || num > 20 || index < 0 || index >= num )
	{
		if(g_time_now - last_post_error < 50)
			return;
		len = FingerExtMakeBuff((unsigned char *)&finger_ext, command, MD_DATA_ERROR, num, index);
		last_post_error = g_time_now;
	}
	else
	{
		len = FingerExtMakeBuff((unsigned char *)&finger_ext, command, MD_DATA_OK, num, index);
	}
	
	sendDatatoTTL((char *)&finger_ext, len);
}

long FingerMakeBuff(unsigned char *buff, unsigned char command, char *param, uint32_t size, unsigned char flag)
{
	int i = 0;
	
	memset(buff, 0, 13);
	buff[0] = FINGER_START;
	buff[1] = command;
	if(param != 0)
		memcpy(buff+2, param, 4);
	memcpy(buff+6, &size, 4);
	buff[10] = flag;
	
	for(i=0; i<11; i++)
		buff[11] += buff[i];
	
	buff[12] = FINGER_END;
	
	return 13;
}

long FingerExtMakeBuff(unsigned  char *buff, unsigned char command, unsigned char flag, short packetNum, short index)
{
	int i = 0;

	FINGER_EXT_HEADER_S *header = (FINGER_EXT_HEADER_S *)buff;
	memset(buff, 0, 13);
	
	header->startcode = FINGER_START;
	header->command = command;
	header->flag = flag;
	header->packetNum = packetNum;
	header->index = index;
	header->endCode = FINGER_END;
	
	for(i=0; i<11; i++)
		buff[11] += buff[i];

	return 13;
}

int FingerCheckTmp(unsigned char *buff,  long len)
{
	int i = 0;
	unsigned long check = 0;
	unsigned long checkBuff = 0;

	if (len <= 4 || buff == 0)
		return 0;

	checkBuff = *(unsigned long *)(buff + len - 4);
	if (checkBuff == 0)
		return 0;

	for (i = 0; i < len - 4; i++)
		check += buff[i];
	return checkBuff == check ? 1 : 0;
}
