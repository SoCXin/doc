/******************** (C) COPYRIGHT  QITAS ********************************
 * 文件名  ：SPI.c
 * 描述    ：SPI 
 * 作者    ：QITAS
 * 硬件连接: SCLK--PA5;MISO---PA6;MOSI--PA7;SCS---PA4
 * 调试方式：J-Link-OB
****************************************************************************/	

#include "SPIx.h"

 /**
  * @file   WIZ_SPI_Init
  * @brief  SPI1初始化  
  * @param  无
  * @retval 无
  */
void WIZ_SPI_Init(void)
{
	SPI_InitTypeDef   SPI_InitStructure;

	RCC_APB1PeriphClockCmd(WIZ_SPI_RCC , ENABLE);
  /* SPI Config -------------------------------------------------------------*/
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI2, &SPI_InitStructure);
  /* Enable SPI */
  SPI_Cmd(WIZ_SPI, ENABLE);
}


 /**
  * @file   SPIX_SendByte
  * @brief  通过外设SPIx发送一个数据
  * @param  uint8_t byte
  * @retval 通过外设SPIx发送一个数据
  */
uint8_t SPIX_SendByte(uint8_t byte)
{
		
	while (SPI_I2S_GetFlagStatus(WIZ_SPI, SPI_I2S_FLAG_TXE) == RESET); //检查指定的SPI标志位设置与否:发送缓存空标志位
	  

	SPI_I2S_SendData(WIZ_SPI, byte); //通过外设SPIx发送一个数据
	while (SPI_I2S_GetFlagStatus(WIZ_SPI, SPI_I2S_FLAG_RXNE) == RESET); //检查指定的SPI标志位设置与否:接受缓存非空标志位
							
	return SPI_I2S_ReceiveData(WIZ_SPI); //返回通过SPIx最近接收的数据	
	
}
