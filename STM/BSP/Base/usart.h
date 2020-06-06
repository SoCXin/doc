#ifndef __USART_H
#define __USART_H

#include "stm32f10x.h"
#include <stdio.h>


#define USART_TTL              	 USART1
#define USART_RCC_TTL         	 RCC_APB2Periph_USART1
#define USART_TX_TTL		         GPIO_Pin_9	// out
#define USART_RX_TTL		         GPIO_Pin_10	// in 

#define USART_232              	 USART2
#define USART_RCC_232         	 RCC_APB1Periph_USART2
#define USART_TX_232		         GPIO_Pin_2	// out
#define USART_RX_232		         GPIO_Pin_3	// in 


#define USART_GPIO_RCC    		RCC_APB2Periph_GPIOA
#define USART_GPIO_PORT    		GPIOA   


void USART1_Config_ttl(uint32_t BaudRate);
void NVIC1_Configuration_ttl(void);
void sendDatatoTTL(char *buff, int reqLen);

void USART2_Config_232(uint32_t BaudRate);
void NVIC2_Configuration_232(void);
void sendDatatoRS232(char *buff, int reqLen);

#endif
