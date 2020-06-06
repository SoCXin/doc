#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define LED1                     1
#define LED2                     2
#define LED3                     3

//ÂÌÉ«
#define LED1_GPIO_RCC           RCC_APB2Periph_GPIOB
#define LED1_GPIO_PORT          GPIOB
#define LED1_GPIO_PIN      			GPIO_Pin_7
#define LED1_ONOFF(x)     			GPIO_WriteBit(LED1_GPIO_PORT,LED1_GPIO_PIN,x);
//À¶É«
#define LED2_GPIO_RCC           RCC_APB2Periph_GPIOB
#define LED2_GPIO_PORT          GPIOB
#define LED2_GPIO_PIN      			GPIO_Pin_5
#define LED2_ONOFF(x)     			GPIO_WriteBit(LED2_GPIO_PORT,LED2_GPIO_PIN,x);
//ºìÉ«
#define LED3_GPIO_RCC           RCC_APB2Periph_GPIOB
#define LED3_GPIO_PORT          GPIOB
#define LED3_GPIO_PIN      			GPIO_Pin_6
#define LED3_ONOFF(x)      			GPIO_WriteBit(LED3_GPIO_PORT,LED3_GPIO_PIN,x);


void LED_GPIO_Config(void);	
void LEDXToggle(uint8_t ledx);
#endif




