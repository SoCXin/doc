#ifndef FINGER_PARSE_H
#define FINGER_PARSE_H

//初始化指纹模块
void eg_finger_init(void);

//解析指纹模块返回的数据
int eg_finger_parse(void);

//网络指令
int eg_finger_net_comment(unsigned char type, unsigned char *content_buff, 
	int content_len, unsigned char *out_buff, unsigned short *out_len, unsigned char *ip, unsigned short port);

#endif
