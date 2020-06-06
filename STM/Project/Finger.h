
#include "stm32f10x.h"

#define FINGER_START		0x70
#define FINGER_END			0x0A

//系统状态
#define FINGER_SYS_STATUS						0x14
//主动按指纹了
#define FINGER_IDENTIFY_FREE				0x2F

extern int g_finger_ing;

//协议头
#pragma pack(1)
typedef struct Finger_Header
{
	unsigned char 	start_code;
	unsigned char		command;			//协议编号
	uint32_t				param;				//系统参数
	uint32_t				size;					//包总大小
	unsigned char		flag;					//标志
}FINGER_HEADER_S;
FINGER_HEADER_S *FingerCheckBuff(const unsigned char *buff,const  int len, char **contentBuff, int *contentLen, int package_num, char ext);

//创建发送协议包
long FingerMakeBuff(unsigned  char *buff,unsigned char command, char *param, uint32_t size, unsigned char flag);

//扩展协议包
#pragma pack(1)
typedef struct Finger_Ext_Header
{
	char  	startcode;
	char  	command;
	short 	packetNum;
	short 	index;
	int 		size;
	char  	flag;
	char  	checkSum;
	char  	endCode;
} FINGER_EXT_HEADER_S;
//创建发送协议包
long FingerExtMakeBuff(unsigned  char *buff, unsigned char command, unsigned char flag, short packetNum, short index);

//发送扩展协议 继续获取更多的包
void FingerCheckMore(unsigned char command, short num, short index);

//校验指纹模板数据
int FingerCheckTmp(unsigned char *buff,  long len);
