#include "model.h"

const unsigned char MODEL_TOKEN[5] = { 0xFE, 0x23,0xE9,0x01,0x94 };
char g_model_id[12];

void ModelInit(char *id)
{
	memcpy(g_model_id, id, 12);
}

MODEL_HEADER_S  *ModelCheckBuff(char *buff, int len, char **contentBuff, int *contentLen)
{
	MODEL_HEADER_S *header = 0;

	//数据太短就抛弃掉
	if (len < 20)
		return 0;

	//包头验证
	if (memcmp(buff, MODEL_TOKEN, 5) != 0)
		return 0;

	//获取协议头信息
	header = (MODEL_HEADER_S *)buff;
	if (header->len > len)
	{
		*contentLen = -1;
		return header;
	}

	//复制内容长度
	*contentBuff = buff + 20;
	*contentLen = header->len - 20;

	return header;
}

int ModelMakeHeader(char *buff, long type, int contentLen)
{
	unsigned short len;
	unsigned char typeT;

	memset(buff, 0, 20);

	memcpy(buff, MODEL_TOKEN, 5);

	len = 20 + contentLen;
	memcpy(buff + 5, &len, 2);

	typeT = type;
	memcpy(buff + 7, &typeT, 1);

	memcpy(buff + 8, g_model_id, 12);

	return 20;
}

int ModelMakeCodeAck(char *buff, long type, char code)
{
	int headerLen = ModelMakeHeader(buff, type, 1);
	memcpy(buff + headerLen, &code, 1);
	return headerLen + 1;
}



long ModelMakeDevIdAck(char *retBuff, char *name, char *secret, char isFinger, char type)
{
	int headerLen = ModelMakeHeader(retBuff, 2, 52);

	memset(retBuff + headerLen, 0, 52);
	strncpy(retBuff + headerLen, name, 19);
	strncpy(retBuff + headerLen + 20, secret, 29);
	memcpy(retBuff + headerLen + 50, &isFinger, 1);
	memcpy(retBuff + headerLen + 51, &type, 1);
	
	return headerLen + 52;
}

long ModelMakeInfoExtAck(char *retBuff, char *ext_buff, int ext_buff_len)
{
	int headerLen = ModelMakeHeader(retBuff, 4, ext_buff_len);
	
	if (ext_buff != 0)
		memcpy(retBuff + headerLen, ext_buff, ext_buff_len > 1500 ? 1500 : ext_buff_len);
	
	return headerLen + ext_buff_len;
}

long ModelMakeInfoAck(char *retBuff, DEV_INFO_ACK_S *info)
{
	int headerLen = ModelMakeHeader(retBuff, 6, sizeof(DEV_INFO_ACK_S));
	memcpy(retBuff + headerLen, info, sizeof(DEV_INFO_ACK_S));
	return headerLen + sizeof(DEV_INFO_ACK_S);
}

long ModelMakeFingerTmpAck(char *retBuff, char *tmp, int dataLen)
{
	int headerLen = ModelMakeHeader(retBuff, 108, dataLen);
	memset(retBuff + headerLen, 0, dataLen + 1);
	memcpy(retBuff + headerLen, tmp, dataLen);
	return headerLen + dataLen;
}

long ModelMakeConRelayReq(char *buff, unsigned char	relayId, unsigned char  control, unsigned int duration)
{
	int headerLen = ModelMakeHeader(buff, 51, 2);

	DEV_CON_RELAY_REQ_S *req = (DEV_CON_RELAY_REQ_S *)buff;
	req->relayId = relayId;
	req->control = control;
	req->duration = duration;

	return sizeof(DEV_CON_RELAY_REQ_S);
}

long ModelMakeConRelayAck(char *retBuff)
{
	int headerLen = ModelMakeHeader(retBuff, 52, 0);
	return headerLen;
}


long ModelMakeConBuzzerAck(char *retBuff)
{
	int headerLen = ModelMakeHeader(retBuff, 54, 0);
	return headerLen;
}

long ModelMakeConGroupReq(char *retBuff, unsigned char plan)
{
	int headerLen = ModelMakeHeader(retBuff, 55, 1);
	DEV_CON_GROUP_REQ_S *req = (DEV_CON_GROUP_REQ_S *)retBuff;
	req->plan = plan;
	return sizeof(DEV_CON_GROUP_REQ_S);
}

long ModelMakeConGroupAck(char *retBuff)
{
	int headerLen = ModelMakeHeader(retBuff, 56, 0);
	return headerLen;
}

long ModelMakeVoiceAck(char *retBuff)
{
	int headerLen = ModelMakeHeader(retBuff, 60, 0);
	return headerLen;
}


long ModelMakeExtAck(char *retBuff)
{
	int headerLen = ModelMakeHeader(retBuff, 254, 0);
	return headerLen;
}

long ModelMakeRfidReq(char *retBuff, char *rfid)
{
	int headerLen = ModelMakeHeader(retBuff, 151, 8);

	memcpy(retBuff + headerLen, rfid, 8);

	return headerLen + 8;
}

long ModelMakeFingerReq(char *retBuff, short userID)
{
	int headerLen = ModelMakeHeader(retBuff, 153, 18);

	memset(retBuff + headerLen, 0, 18);
	memcpy(retBuff + headerLen, &userID, 2);

	return headerLen + 18;
}


long ModelMakeBtnReq(char *retBuff, char btnId, int num, unsigned int spend)
{
	int headerLen = ModelMakeHeader(retBuff, 155, 9);
	memcpy(retBuff + headerLen, &btnId, 1);
	memcpy(retBuff + headerLen + 1, &num, 4);
	memcpy(retBuff + headerLen + 5, &spend, 4);
	return headerLen + 9;
}

long ModelMakeStrengthReq(char *retBuff, unsigned int value1, unsigned int value2, unsigned int value3, char *btn1, char *btn2)
{
	int headerLen = ModelMakeHeader(retBuff, 157, 12 + 100);
	memcpy(retBuff + headerLen + 0, &value1, 4);
	memcpy(retBuff + headerLen + 4, &value2, 4);
	memcpy(retBuff + headerLen + 8, &value3, 4);
	
	//复制所有的光感数据
	if(btn1 != 0)
		memcpy(retBuff + headerLen + 12, btn1, 50);
	if(btn2 != 0)
		memcpy(retBuff + headerLen + 62, btn2, 50);
	
	return headerLen + 12 + 100;
}

long ModelMakeUserPushReq(char *retBuff, char *user_info, int len)
{
	int headerLen = ModelMakeHeader(retBuff, 191, len);
	memcpy(retBuff + headerLen, user_info, len);
	return headerLen + len;
}


long ModelMakeFingerScanReq(char *retBuff, unsigned short user_id, unsigned char  status)
{
	int headerLen = ModelMakeHeader(retBuff, 159, 3);

	memcpy(retBuff + headerLen, &user_id, 2);
	memcpy(retBuff + headerLen + 2, &status, 1);

	return headerLen + 3;
}

long ModelMakePush232ExtReq(char *retBuff, char *user_info, int len)
{
	int headerLen = ModelMakeHeader(retBuff, 193, len);
	memcpy(retBuff + headerLen, user_info, len);
	return headerLen + len;
}

long ModelMakePushTTLExtReq(char *retBuff, char *user_info, int len)
{
	int headerLen = ModelMakeHeader(retBuff, 195, len);
	memcpy(retBuff + headerLen, user_info, len);
	return headerLen + len;
}

long ModelMakeInStandbyReq(char *retBuff, unsigned int show_index)
{
	int headerLen = ModelMakeHeader(retBuff, 163, 4);
	memcpy(retBuff + headerLen, &show_index, 4);
	return headerLen + 4;
}

long ModelMakeStrengthStatusAck(char *retBuff, unsigned char code, 
	unsigned int update_time, unsigned int show_index, unsigned int strength_count, unsigned char status)
{
	int headerLen = ModelMakeHeader(retBuff, 74, 14);
	*(unsigned char *)(retBuff + headerLen + 0) = code;
	*(unsigned int *)(retBuff + headerLen + 1) = update_time;
	*(unsigned int *)(retBuff + headerLen + 5) = show_index;
	*(unsigned int *)(retBuff + headerLen + 9) = strength_count;
	*(unsigned char *)(retBuff + headerLen + 13) = status;
	return headerLen + 14;
}
