#ifndef WORK_NET_H
#define WORK_NET_H

#include "Types.h"

int eg_net_loop(void);

int eg_work_net(uint8 *in_buff, uint16 in_len, uint8 *out_buff, uint16 *out_len, uint8 *ip, uint16 port);

#endif
