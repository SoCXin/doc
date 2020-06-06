#ifndef STRENGTH_H
#define STRENGTH_H 

//同步状态
int eg_strength_sync_status(unsigned char staus, unsigned int index, unsigned char *out_buff, unsigned short *out_len);

//处理数据变化
int eg_strength_loop(void);

////////////////////////////////////////////////////////////////

//接收力量器械的数据
int eg_strength_add_data(unsigned char data);


#endif
