#ifndef __RELAY_H
#define __RELAY_H

#include "stm32f10x.h"


//¼ÌµçÆ÷0
#define Relay_GPIO_RCC          	RCC_APB2Periph_GPIOB
#define Relay_GPIO_PORT         	GPIOB
#define Relay_GPIO_PIN      			GPIO_Pin_3
#define REALY0_ON								Relay_Switch(1, 1);
#define REALY0_OFF								Relay_Switch(1, 0);

//¼ÌµçÆ÷1
#define Relay_GPIO_RCC_1          RCC_APB2Periph_GPIOB
#define Relay_GPIO_PORT_1         GPIOB
#define Relay_GPIO_PIN_1      		GPIO_Pin_4
#define REALY1_ON								Relay_Switch(2, 1);
#define REALY1_OFF								Relay_Switch(2, 0);

void Relay_GPIO_Config(void);	
void Relay_Switch(char id, char on);
char Relay_Status(char id);

#endif
