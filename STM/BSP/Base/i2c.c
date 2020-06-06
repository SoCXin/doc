/******************** (C) COPYRIGHT  源地工作室 ********************************
 * 文件名  ：i2c.c
 * 描述    ：初始化IIC及一些基本的操作 
 * 作者    ：zhuoyingxingyu
 * 淘宝    ：源地工作室http://vcc-gnd.taobao.com/
 * 论坛地址：极客园地-嵌入式开发论坛http://vcc-gnd.com/
 * 版本更新: 2017-07-14
 * 硬件连接: PB6-I2C1_SCL、PB7-I2C1_SDA
 * 调试方式：J-Link-OB
**********************************************************************************/

//头文件
#include "i2c.h"
#include "usart.h"
#include "string.h"

 /**
  * @file   I2C_Configuration
  * @brief  EEPROM管脚配置
  * @param  无
  * @retval 无
  */
void I2C_Configuration(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure; 
  /* Configure I2C2 pins: PB6->SCL and PB7->SDA */
  RCC_APB2PeriphClockCmd(EEPROM_I2C_SCL_GPIO_RCC|EEPROM_I2C_SDA_GPIO_RCC, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin =  EEPROM_I2C_SCL_PIN ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  
	GPIO_Init(EEPROM_I2C_SCL_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin =  EEPROM_I2C_SDA_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  
	GPIO_Init(EEPROM_I2C_SDA_GPIO_PORT, &GPIO_InitStructure);
}

 /**
  * @file   I2C_delay
  * @brief  延迟时间
  * @param  无
  * @retval 无
  */
static void I2C_delay(void)
{	
   uint8_t i=50;
   while(i) 
   { 
     i--; 
   } 
}

 /**
  * @file   I2C_Start
  * @brief  起始信号
  * @param  无
  * @retval 无
  */
static FunctionalState I2C_Start(void)
{
	SDA_H;
	SCL_H;
	I2C_delay();
	if(!SDA_read)return DISABLE;	/* SDA线为低电平则总线忙,退出 */
	SDA_L;
	I2C_delay();
	if(SDA_read) return DISABLE;	/* SDA线为高电平则总线出错,退出 */
	SDA_L;
	I2C_delay();
	return ENABLE;
}

 /**
  * @file   I2C_Stop
  * @brief  停止信号
  * @param  无
  * @retval 无
  */
static void I2C_Stop(void)
{
	SCL_L;
	I2C_delay();
	SDA_L;
	I2C_delay();
	SCL_H;
	I2C_delay();
	SDA_H;
	I2C_delay();
}

 /**
  * @file   I2C_Ack
  * @brief  应答信号
  * @param  无
  * @retval 无
  */
static void I2C_Ack(void)
{	
	SCL_L;
	I2C_delay();
	SDA_L;
	I2C_delay();
	SCL_H;
	I2C_delay();
	SCL_L;
	I2C_delay();
}

 /**
  * @file   I2C_NoAck
  * @brief  无应答信号
  * @param  无
  * @retval 无
  */
static void I2C_NoAck(void)
{	
	SCL_L;
	I2C_delay();
	SDA_H;
	I2C_delay();
	SCL_H;
	I2C_delay();
	SCL_L;
	I2C_delay();
}

 /**
  * @file   I2C_WaitAck
  * @brief  等待Ack
  * @param  无
  * @retval 返回为:=1有ACK,=0无ACK
  */
static FunctionalState I2C_WaitAck(void) 	
{
	SCL_L;
	I2C_delay();
	SDA_H;			
	I2C_delay();
	SCL_H;
	I2C_delay();
	if(SDA_read)
	{
      SCL_L;
      return DISABLE;
	}
	SCL_L;
	return ENABLE;
}

 /**
  * @file   I2C_SendByte
  * @brief  数据从高位到低位
  * @param  - SendByte: 发送的数据
  * @retval 无
  */
static void I2C_SendByte(uint8_t SendByte) 
{
    uint8_t i=8;
    while(i--)
    {
			SCL_L;
			I2C_delay();
			if(SendByte&0x80)
			SDA_H;  
			else 
			SDA_L;   
			SendByte<<=1;
			I2C_delay();
			SCL_H;
			I2C_delay();
    }
    SCL_L;
}


 /**
  * @file   I2C_ReceiveByte
  * @brief  数据从高位到低位
  * @param  无
  * @retval I2C总线返回的数据
  */
static uint8_t I2C_ReceiveByte(void)  
{ 
    uint8_t i=8;
    uint8_t ReceiveByte=0;

    SDA_H;				
    while(i--)
    {
			ReceiveByte<<=1;      
			SCL_L;
			I2C_delay();
			SCL_H;
			I2C_delay();	
			if(SDA_read)
			{
			ReceiveByte|=0x01;
			}
    }
    SCL_L;
    return ReceiveByte;
}
   
 /**
  * @file   I2C_WriteByte
  * @brief  写一字节数据
  * @param  
	*          - SendByte: 待写入数据
	*          - WriteAddress: 待写入地址
	*          - DeviceAddress: 器件类型(24c08)
  * @retval 返回为:=1成功写入,=0失败
  */
FunctionalState I2C_WriteOneByte(uint8_t SendByte, uint16_t WriteAddress, uint8_t DeviceAddress)
{		
    if(!I2C_Start())return DISABLE;
    I2C_SendByte((((WriteAddress & 0x0700) >>7) | DeviceAddress) & 0xFFFE); /*设置高起始地址+器件地址 */
    if(!I2C_WaitAck()){I2C_Stop(); return DISABLE;}
    I2C_SendByte((uint8_t)(WriteAddress & 0x00FF));   /* 设置低起始地址 */      
    I2C_WaitAck();	
    I2C_SendByte(SendByte);
    I2C_WaitAck();   
    I2C_Stop(); 
    return ENABLE;
}									 

 /**
  * @file   I2C_ReadBytes
  * @brief  读取一串数据
  * @param  
	*					- pBuffer: 存放读出数据
	*     	  - length: 待读出长度
	*         - ReadAddress: 待读出地址
	*         - DeviceAddress: 器件类型(24c08)
  * @retval 返回为:=1成功读入,=0失败
  */
FunctionalState I2C_ReadBytes(uint8_t* pBuffer,   uint16_t length,   uint16_t ReadAddress,  uint8_t DeviceAddress)
{		
    if(!I2C_Start())return DISABLE;
    I2C_SendByte((((ReadAddress & 0x0700) >>7) | DeviceAddress) & 0xFFFE); /* 设置高起始地址+器件地址 */ 
    if(!I2C_WaitAck()){I2C_Stop(); return DISABLE;}
    I2C_SendByte((uint8_t)(ReadAddress & 0x00FF));   /* 设置低起始地址 */      
    I2C_WaitAck();
    I2C_Start();
    I2C_SendByte(((ReadAddress & 0x0700) >>7) | DeviceAddress | 0x0001);
    I2C_WaitAck();
    while(length)
    {
      *pBuffer = I2C_ReceiveByte();
      if(length == 1)I2C_NoAck();
      else I2C_Ack(); 
      pBuffer++;
      length--;
    }
    I2C_Stop();
    return ENABLE;
}
/**
  * @file   I2c_WriteBytes
  * @brief  写多个字节数据
  * @param  
	*          - buff: 待写入数据
	*          - WriteAddr: 待写入地址
*          - length: 待写数据长度
* @retval 返回为
  */
void I2C_WriteBytes(uint8_t* buff, uint8_t WriteAddr, uint16_t length)
{
	uint16_t t;
	for(t=0; t<length; t++)
	{
		while( !I2C_WriteOneByte(buff[t],WriteAddr+t,ADDR_24C08));
	}
}

/**
  * @file   I2C_Test
  * @brief  I2C(AT24C08)读写测试。
  * @param  无
  * @retval 无
  */
void I2C_Test(void)
{
		uint16_t Addr;
		uint8_t WriteBuffer[256],ReadBuffer[256];
		for(Addr=0; Addr<256; Addr++)
	  {
			WriteBuffer[Addr]=255;	 /* 填充WriteBuffer */
			printf("0x%02x ",WriteBuffer[Addr]);
				if(Addr%16 == 15)    
		printf("\n\r");
		
    }
		/* 开始向EEPROM写数据 */
		printf("\r\n EEPROM 24C08 Write Test \r\n");
		I2C_WriteBytes(WriteBuffer,0,256);
//		for(Addr=0; Addr<256; Addr++)
//		while( !I2C_WriteOneByte(WriteBuffer[Addr], Addr,  ADDR_24C08) );
		printf("\r\n EEPROM Write Test OK \r\n");

		/* EEPROM读数据 */
		printf("\r\n EEPROM 24C08 Read Test \r\n");
		I2C_ReadBytes(ReadBuffer, sizeof(WriteBuffer),0, ADDR_24C08);
    for(Addr=0; Addr<256; Addr++)
		{
		   printf("0x%02x ",ReadBuffer[Addr]);
				if(Addr%16 == 15)    
		printf("\n\r");
		}

		if(memcmp(WriteBuffer,ReadBuffer,sizeof(WriteBuffer)) == 0 ) /* 匹配数据 */
		printf("\r\n EEPROM 24C08 Read Test OK\r\n");
		else
		printf("\r\n EEPROM 24C08 Read Test False\r\n");
}



/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
