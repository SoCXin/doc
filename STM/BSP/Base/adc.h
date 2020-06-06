#ifndef __ADC_H
#define __ADC_H

#include "stm32f10x.h"


#define ADC_GPIO_PIN              GPIO_Pin_0
#define ADC_GPIO_PORT             GPIOA
#define ADC_GPIO_RCC              RCC_APB2Periph_GPIOA


extern u32 g_adc1_value;
void adc_init(void);

#endif
