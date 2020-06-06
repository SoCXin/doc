#ifndef __EXTI_H
#define __EXTI_H


#include "stm32f10x.h"

#define KEY1_BUTTON_EXTI_PORT_SOURCE      GPIO_PortSourceGPIOC
#define KEY1_BUTTON_EXTI_PIN_SOURCE       GPIO_PinSource13
#define KEY1_BUTTON_EXTI_LINE             EXTI_Line13

#define KEY2_BUTTON_EXTI_PORT_SOURCE      GPIO_PortSourceGPIOC
#define KEY2_BUTTON_EXTI_PIN_SOURCE       GPIO_PinSource14
#define KEY2_BUTTON_EXTI_LINE             EXTI_Line14

#define KEY3_BUTTON_EXTI_PORT_SOURCE      GPIO_PortSourceGPIOC
#define KEY3_BUTTON_EXTI_PIN_SOURCE       GPIO_PinSource15
#define KEY3_BUTTON_EXTI_LINE             EXTI_Line15

#define KEY_BUTTON_EXTI_IRQn             	EXTI15_10_IRQn

void Exti_Config(void);
void Nvic_Config(void);
void EXTI9_5_IRQHandler(void);
void EXTI15_10_IRQHandler(void);


//°´Å¥3
//extern u8 	g_btn3_count;

#endif



