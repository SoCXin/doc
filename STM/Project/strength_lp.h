#ifndef STRENGTH_LP_H
#define STRENGTH_LP_H 

//网络同步状态
int eg_strength_lp_net_set_status(unsigned int status, unsigned int space_time, unsigned int one_time, unsigned char beep);

//////////////////////////////////////////////////////////////////////////////////////////////////////////

//处理数据变化
int eg_strength_lp_loop(void);

//传感器触发
void eg_strength_lp_btn(unsigned int interval, char btn_key);


#endif
