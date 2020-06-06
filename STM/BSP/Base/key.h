#ifndef __KEY_H
#define	__KEY_H

#include "stm32f10x.h"

#define KEY1_BUTTON_PIN                   GPIO_Pin_13
#define KEY1_BUTTON_GPIO_PORT             GPIOC
#define KEY1_BUTTON_GPIO_RCC              RCC_APB2Periph_GPIOC
#define KEY1_Status_Read()								GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)

#define KEY2_BUTTON_PIN                   GPIO_Pin_14
#define KEY2_BUTTON_GPIO_PORT             GPIOC
#define KEY2_BUTTON_GPIO_RCC              RCC_APB2Periph_GPIOC
#define KEY2_Status_Read()								GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_14)

#define KEY3_BUTTON_PIN                   GPIO_Pin_15
#define KEY3_BUTTON_GPIO_PORT             GPIOC
#define KEY3_BUTTON_GPIO_RCC              RCC_APB2Periph_GPIOC
#define KEY3_Status_Read()								GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15)

#define KEY4_BUTTON_PIN                   GPIO_Pin_15
#define KEY4_BUTTON_GPIO_PORT             GPIOA
#define KEY4_BUTTON_GPIO_RCC              RCC_APB2Periph_GPIOA
#define KEY4_Status_Read()								GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)


void KEY_GPIO_Config(void);

#endif
