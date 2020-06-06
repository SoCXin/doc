#ifndef __SPIX_H
#define __SPIX_H

#include "stm32f10x.h"

#define HIGH		1
#define LOW		0

#define RFID_SPI                        SPI1
#define RFID_SPI_RCC                    RCC_APB2Periph_SPI1

#define WIZ_SPI                         SPI2
#define WIZ_SPI_RCC                     RCC_APB1Periph_SPI2



void WIZ_SPI_Init(void);
void WIZ_CS(uint8_t val);
uint8_t SPIX_SendByte(uint8_t byte);


#endif

