#include "rc522.h"
#include "GPIOLIKE51.h"
#include "SYSTICK.h"

u8 RFID_UID[5];
u8 RFID_Buffer[18];
u8 RFID_Password_Buffer[6]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

//
void delay_ns(u32 ns)
{
  u32 i;
  for(i=0;i<ns;i++)
  {
    __nop();
    __nop();
    __nop();
  }
}


//以下是SPI模块的初始化代码，配置成主机模式，访问MFRC522	
//MFRC522 支持10Mbit/S的SPI模式、作从机下降沿传递数据、高位在前
//SPI口初始化
//这里针是对SPI2的初始化

//SPI2_SCK 					PA5
//SPI2_MISO					PA6
//SPI2_MOSI 				PA7
//RCC522_NSS(SDA）			PA4
//RCC522_RST(CE)  			PA8
//RCC522_IRQ 		  		空没接

/***************************************************************************
    - 功能描述：STM32f103 SPI接口配置的初始化函数
    - 隶属模块：STM32 SPI操作
  - 函数属性：外部，使用户使用
  - 参数说明：无
  - 返回说明：无
    - 函数实现步骤：
   (1)SPI2在没有重映射的条件下NSS->PA4、SCK->PA5、MISO->PA6、MOSI->PA7，由于STM32要处于主机模式且用软件模式，所以NSS不用
   (2)初始化GPIO管脚和SPI的参数设置：建立SPI和GPIO的初始化结构体
   (3)在配置GPIO的PB13、PB14、PB15时将其配置为复用输出,在复用功能下面,输入输出的方向,完全由内部控制.不需要程序处理.
   (4)配置FLASH的片选信号线PB2，并设为高电平，也就是不选中FLASH
   (5)打开GPIO和SPI2的时钟 
   (6)配置SPI1的参数SPI的方向、工作模式、数据帧格式、CPOL、CPHA、NSS软件还是硬件、SPI时钟、数据的传输位、以及CRC
   (7)利用SPI结构体初始化函数初始化SPI结构体、并使能SPI1
   (8)最后启动传输发送一个0xff，其实也可以不发
    以下是SPI2模块的初始化代码，配置成主机模式，访问SD Card/W25X16/24L01/JF24C 
***************************************************************************/
void SPI2_Init(void)
{
	SPI_InitTypeDef SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_SPI1, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;								//RESET
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High; 
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge; 
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft ;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI1, &SPI_InitStructure);

  SPI_Cmd(SPI1, ENABLE);
	
	PAout(4)=0;
 	SPI1s_ReadWriteByte(0xaa);//启动传输	
	PAout(4)=1;
}




/***************************************************************************
    - 功能描述：STM32f103 SPI读写字节函数
    - 隶属模块：STM32 SPI操作
  - 函数属性：外部，使用户使用
  - 参数说明：TxData:要写入的字节
  - 返回说明：读取到的字节 
 - 函数说明：由于主机SPI通信时，在发送和接受时是同时进行的,即发送完了一个字节的数据后，也应当接受到一个字节的数据
   （1）stm32先等待已发送的数据是否发送完成，如果没有发送完成，并且进入循环200次，则表示发送错误，返回收到的值为0;
   （2）如果发送完成，stm32从SPI1总线发送TxData
   （3）stm32再等待接收的数据是否接收完成，如果没有接收完成，并且进入循环200次，则表示接收错误，则返回值0
   （4）如果接收完成了，则返回STm32读取的最新的数据  
   
   stm32
   ------->等待已发送的数据是否完成
   OK
   ------->  
   stm32发送数据
   ------->等待待接收的数据是否完成
   OK
   ------->
   stm32读取数据

//SPIx 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
***************************************************************************/

u8 SPI1s_ReadWriteByte(u8 TxData)
{		
	u8 retry=0;				 	
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) //检查指定的SPI标志位设置与否:发送缓存空标志位
	{
 		retry++;
 		if(retry>200)return 0;
	}			  
	SPI_I2S_SendData(SPI1, TxData); 																//通过外设SPIx发送一个数据
// 	PBout(10)=!PBout(10);
	retry=0;

	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) //检查指定的SPI标志位设置与否:接受缓存非空标志位
	{
 		retry++;
 		if(retry>200)return 0;
	}	
	return SPI_I2S_ReceiveData(SPI1); 															//返回通过SPIx最近接收的数据			
}


//******************************************************************/
//功    能：读RC522寄存器
//参数说明：Address[IN]:寄存器地址
//返    回：读出的值
//******************************************************************/
unsigned char ReadRawRC(unsigned char Address)
{
		u8 i=0;
		//delay_us(10);
	  PAout(4)=0;
    SPI1s_ReadWriteByte(((Address<<1)&0x7E)|0x80);
		i=SPI1s_ReadWriteByte(0);	
		SPI_I2S_ClearFlag(SPI1, SPI_I2S_FLAG_TXE);	
		//delay_us((u16)10);
		PAout(4)=1;			
		return i;	
}

//******************************************************************/
//功    能：写RC522寄存器
//参数说明：Address[IN]:寄存器地址
//          value[IN]:写入的值
//******************************************************************/
void WriteRawRC(unsigned char Address, unsigned char value)
{
	PAout(4)=0;	
	//delay_us(10);
	SPI1s_ReadWriteByte((Address<<1)&0x7E);
	//delay_us(10);
	SPI1s_ReadWriteByte(value);
	//delay_us(10);

	SPI_I2S_ClearFlag(SPI1,SPI_I2S_FLAG_TXE);	
	//delay_us((u16)10);
	PAout(4)=1;				
}

//******************************************************************/
//功    能：置RC522寄存器位
//参数说明：reg[IN]:寄存器地址
//          mask[IN]:置位值
//******************************************************************/
void SetBitMask(unsigned char reg,unsigned char mask)  
{
  char tmp = 0x0            ;
  tmp = ReadRawRC(reg)| mask;
  WriteRawRC(reg,tmp | mask);  // set bit mask
}

//******************************************************************/
//功    能：清RC522寄存器位
//参数说明：reg[IN]:寄存器地址
//          mask[IN]:清位值
//******************************************************************/
void ClearBitMask(unsigned char reg,unsigned char mask)  
{
  char tmp = 0x0              ;
  tmp = ReadRawRC(reg)&(~mask);
  WriteRawRC(reg, tmp)        ;  // clear bit mask
} 

//******************************************************************/
//功    能：复位RC522
//返    回: 成功返回MI_OK
//******************************************************************/
char PcdReset()
{
  RC522_RST=1;                             ;
  delay_ns(1000)                             ;
  RC522_RST=0;                             ;
  delay_ns(1000)                             ;
  RC522_RST=1;                             ;
  delay_ns(1000)                           ;
  WriteRawRC(CommandReg,PCD_RESETPHASE);
  delay_ns(1000)                             ;
  WriteRawRC(ModeReg,0x3D)             ;//定义发送和接收常用模式 和Mifare卡通讯，CRC初始值0x6363
  WriteRawRC(TReloadRegL,30)           ;//16位定时器低位 30
  WriteRawRC(TReloadRegH,0)            ;//16位定时器高位
  WriteRawRC(TModeReg,0x8D)            ;//定义内部定时器的设置
  WriteRawRC(TPrescalerReg,0x3E)       ;//设置定时器分频系数  
  WriteRawRC(TxASKReg,0x40)            ;//调制发送信号为100%ASK
  return MI_OK                         ; 
}
////////////////////////////////////////////////////////////////////// 
//设置RC522的工作方式   
//////////////////////////////////////////////////////////////////////
char MF522PcdConfigISOType(unsigned char  type)
{
	if (type == 'A')	//ISO14443_A
		{
			ClearBitMask(Status2Reg,0x08);	//状态2寄存器         
			WriteRawRC(ModeReg,0x3D);	//3F  //和Mifare卡通讯，CRC初始值0x6363         
			WriteRawRC(RxSelReg,0x86);	//84   选择内部接收器设置，内部模拟部分调制信号，发送数据后，延迟6个位时钟，接收         
			WriteRawRC(RFCfgReg,0x7F);	//4F  配置接收器  48dB最大增益         
			WriteRawRC(TReloadRegL,30);	//tmoLength);TReloadVal = 'h6a =tmoLength(dec)      
			WriteRawRC(TReloadRegH,0);	//实际值是OXD3E 这部分主要是设置定时器寄存器       
			WriteRawRC(TModeReg,0x8D);
			WriteRawRC(TPrescalerReg,0x3E);
			delay_ns(1000);
			PcdAntennaOn();
		}     
	else {return 0xFE;}  
	return MI_OK; 
}  

//******************************************************************/
//开启天线发射  
//每次启动或关闭天险发射之间应至少有1ms的间隔
//******************************************************************/
unsigned char PcdAntennaOn(void)
{
  unsigned char i;
  WriteRawRC(TxASKReg,0x40)       ;
  delay_us((u16)10)                       ;
  i = ReadRawRC(TxControlReg)     ;
  if(!(i&0x03))
    SetBitMask(TxControlReg, 0x03);
  i = ReadRawRC(TxASKReg);
	return i;
}


//******************************************************************/
//关闭天线发射
//******************************************************************/
void PcdAntennaOff()
{
  ClearBitMask(TxControlReg, 0x03);
}

//******************************************************************/
//功    能：通过RC522和ISO14443卡通讯
//参数说明：Command[IN]:RC522命令字
//          pInData[IN]:通过RC522发送到卡片的数据
//          InLenByte[IN]:发送数据的字节长度
//          pOutData[OUT]:接收到的卡片返回数据
//          *pOutLenBit[OUT]:返回数据的位长度
//******************************************************************/
char PcdComMF522(unsigned char Command  ,unsigned char *pInData , 
                 unsigned char InLenByte,unsigned char *pOutData, 
                 unsigned int  *pOutLenBit                       )
{
  char status = MI_ERR                          ;
  unsigned char irqEn   = 0x00                  ;
  unsigned char waitFor = 0x00                  ;
  unsigned char lastBits                        ;
  unsigned char n                               ;
  unsigned int  i                               ;
  switch (Command)
  {
    case PCD_AUTHENT:
      irqEn   = 0x12                            ;
      waitFor = 0x10                            ;
      break                                     ;
    case PCD_TRANSCEIVE:
      irqEn   = 0x77                            ;
      waitFor = 0x30                            ;
      break                                     ;
    default:
      break                                     ;
  }
  WriteRawRC(ComIEnReg,irqEn|0x80)              ; //
  ClearBitMask(ComIrqReg,0x80)                  ;
  WriteRawRC(CommandReg,PCD_IDLE)               ;
  SetBitMask(FIFOLevelReg,0x80)                 ; // 清空FIFO 
  for(i=0; i<InLenByte; i++)
    WriteRawRC(FIFODataReg,pInData[i])          ; // 数据写入FIFO 
  WriteRawRC(CommandReg, Command)               ; // 命令写入命令寄存器
  if(Command == PCD_TRANSCEIVE)
    SetBitMask(BitFramingReg,0x80)              ; // 开始发送     
  i = 6000                                      ; //根据时钟频率调整，操作M1卡最大等待时间25ms
  do 
  {
    n = ReadRawRC(ComIrqReg)                    ;
    i--                                         ;
  }
  while((i!=0)&&!(n&0x01)&&!(n&waitFor))        ;
  ClearBitMask(BitFramingReg,0x80)              ;
  if(i!=0)
  {
    if(!(ReadRawRC(ErrorReg)&0x1B))
    {
      status = MI_OK                            ;
      if (n&irqEn&0x01)
        status = MI_NOTAGERR                    ;
      if(Command==PCD_TRANSCEIVE)
      {
        n = ReadRawRC(FIFOLevelReg)             ;
        lastBits = ReadRawRC(ControlReg)&0x07   ;
        if(lastBits)
          *pOutLenBit = (n-1)*8 + lastBits      ;
        else
          *pOutLenBit = n*8                     ;
        if(n==0)
          n = 1                                 ;
        if(n>MAXRLEN)
          n = MAXRLEN                           ;
        for (i=0; i<n; i++)
          pOutData[i] = ReadRawRC(FIFODataReg)  ; 
      }
    }
    else
      status = MI_ERR                           ;        
  }
  SetBitMask(ControlReg,0x80)                   ;// stop timer now
  WriteRawRC(CommandReg,PCD_IDLE)               ; 
  return status;
}

//******************************************************************/
//功    能：寻卡                                                    /
//参数说明: req_code[IN]:寻卡方式                                   /
//                0x52 = 寻感应区内所有符合14443A标准的卡           /
//                0x26 = 寻未进入休眠状态的卡                       /
//                pTagType[OUT]：卡片类型代码                       /
//                0x4400 = Mifare_UltraLight                        /
//                0x0400 = Mifare_One(S50)                          /
//                0x0200 = Mifare_One(S70)                          /
//                0x0800 = Mifare_Pro(X)                            /
//                0x4403 = Mifare_DESFire                           /
//返    回: 成功返回MI_OK                                           /
//******************************************************************/
char PcdRequest(unsigned char req_code,unsigned char *pTagType)
{
  char status                                        ;  
  unsigned int  unLen                                ;
  unsigned char ucComMF522Buf[MAXRLEN]               ; 

  ClearBitMask(Status2Reg,0x08)                      ;//清除MRCrypto1on，要用软件清零
  WriteRawRC(BitFramingReg,0x07)                     ;//startsend=0,rxalign=0,在FIFO中存放的位置，TXlastbit=7
  SetBitMask(TxControlReg,0x03)                      ;//TX2rfen=1,TX1RFen=1,传递调制的13.56MHZ的载波信号
 
  ucComMF522Buf[0] = req_code                        ;

  status = PcdComMF522(PCD_TRANSCEIVE, ucComMF522Buf,1, ucComMF522Buf, &unLen);
  if ((status == MI_OK) && (unLen == 0x10))
  {    
    *pTagType     = ucComMF522Buf[0]                 ;
    *(pTagType+1) = ucComMF522Buf[1]                 ;
  }
  else
    status = MI_ERR                                  ;
  return status                                      ;
}

//******************************************************************/
//功    能：防冲撞                                                  /
//参数说明: pSnr[OUT]:卡片序列号，4字节                             /
//返    回: 成功返回MI_OK                                           /
//******************************************************************/
char PcdAnticoll(unsigned char *pSnr)
{
    char status;
    unsigned char i,snr_check=0;
    unsigned int  unLen;
    unsigned char ucComMF522Buf[MAXRLEN]; 
    
    ClearBitMask(Status2Reg,0x08);//清除MRCrypto1on，要用软件清零
    WriteRawRC(BitFramingReg,0x00);//表示最后一个字节所有位都发送
    ClearBitMask(CollReg,0x80);//CollRegCollReg0冲突结束后冲突位被置零
 
    ucComMF522Buf[0] = PICC_ANTICOLL1;
    ucComMF522Buf[1] = 0x20;

    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,2,ucComMF522Buf,&unLen);

    if (status == MI_OK)
    {
    	 for (i=0; i<4; i++)
         {   
             *(pSnr+i)  = ucComMF522Buf[i];
             snr_check ^= ucComMF522Buf[i];
         }
         if (snr_check != ucComMF522Buf[i])
         {   status = MI_ERR;    }
    }
    
    SetBitMask(CollReg,0x80);//CollRegCollReg 在106kbps良好的防冲突情况下该位置1
    return status;
}

/////////////////////////////////////////////////////////////////////
//功    能：选定卡片
//参数说明: pSnr[IN]:卡片序列号，4字节
//返    回: 成功返回MI_OK
/////////////////////////////////////////////////////////////////////
char PcdSelect(unsigned char *pSnr)
{
    char status;
    unsigned char i;
    unsigned int  unLen;
    unsigned char ucComMF522Buf[MAXRLEN]; 
    
    ucComMF522Buf[0] = PICC_ANTICOLL1;
    ucComMF522Buf[1] = 0x70;
    ucComMF522Buf[6] = 0;
    for (i=0; i<4; i++)
    {
    	ucComMF522Buf[i+2] = *(pSnr+i);
    	ucComMF522Buf[6]  ^= *(pSnr+i);
    }
    CalulateCRC(ucComMF522Buf,7,&ucComMF522Buf[7]);
  
    ClearBitMask(Status2Reg,0x08);//清零MFcryon

    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,9,ucComMF522Buf,&unLen);
    
    if ((status == MI_OK) && (unLen == 0x18))
    {   status = MI_OK;  }
    else
    {   status = MI_ERR;    }

    return status;
}

//******************************************************************/
//功    能：验证卡片密码
//参数说明: auth_mode[IN]: 密码验证模式
//                 0x60 = 验证A密钥
//                 0x61 = 验证B密钥 
//          addr[IN]：块地址
//          pKey[IN]：密码
//          pSnr[IN]：卡片序列号，4字节
//返    回: 成功返回MI_OK
//******************************************************************/
char PcdAuthState(unsigned char auth_mode,unsigned char addr,
                  unsigned char *pKey,unsigned char *pSnr    )
{
    char status;
    unsigned int  unLen;
    unsigned char i,ucComMF522Buf[MAXRLEN]; 

    ucComMF522Buf[0] = auth_mode;//验证A密钥
    ucComMF522Buf[1] = addr;//addr[IN]：块地址
    for (i=0; i<6; i++)
    {    ucComMF522Buf[i+2] = *(pKey+i);   }
    for (i=0; i<6; i++)
    {    ucComMF522Buf[i+8] = *(pSnr+i);   }
    
    status = PcdComMF522(PCD_AUTHENT,ucComMF522Buf,12,ucComMF522Buf,&unLen);
    if ((status != MI_OK) || (!(ReadRawRC(Status2Reg) & 0x08)))
    {   status = MI_ERR;   }
    
    return status;
}

//******************************************************************/
//功    能：读取M1卡一块数据
//参数说明: addr[IN]：块地址
//          pData[OUT]：读出的数据，16字节
//返    回: 成功返回MI_OK
//******************************************************************/
char PcdRead(unsigned char addr,unsigned char *pData)
{
    char status                                          ;
    unsigned int  unLen                                  ;
    unsigned char i,ucComMF522Buf[MAXRLEN]               ; 

    ucComMF522Buf[0] = PICC_READ                         ;
    ucComMF522Buf[1] = addr                              ;
    CalulateCRC(ucComMF522Buf,2,&ucComMF522Buf[2])       ;   
    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,4,
                         ucComMF522Buf,&unLen           );
    if ((status == MI_OK) && (unLen == 0x90))
    {
        for (i=0; i<16; i++)
            *(pData+i) = ucComMF522Buf[i];   
    }
    else
      status = MI_ERR;       
    return status;
}

//******************************************************************/
//功    能：读取M1卡一块数据
//参数说明: addr[IN]：块地址
//          pData[OUT]：读出的数据，16字节
//返    回: 成功返回MI_OK
//******************************************************************/
char Read_Block(unsigned char Block,unsigned char *Buf)
{
  char result                                             ;
  result = PcdAuthState(0x60,Block,RFID_Password_Buffer,RFID_UID)   ;
  if(result!=MI_OK)
    return result                                         ;
  result = PcdRead(Block,Buf)                             ;
//  return result; // 2011.01.03
  
  if(result!=MI_OK)     return   result                   ;
  if(Block!=0x00&&des_on)
  {
//     Des_Decrypt((char *)Buf    ,KK,(char *)Buf    )       ;
//     Des_Decrypt((char *)&Buf[8],KK,(char *)&Buf[8])       ;  
  }
  return SUCCESS                                          ; 
}

//******************************************************************/
//功    能：写数据到M1卡一块
//参数说明: addr[IN]：块地址
//          pData[IN]：写入的数据，16字节
//返    回: 成功返回MI_OK
//******************************************************************/
char PcdWrite(unsigned char addr,unsigned char *pData)
{
  char status                                             ;
  unsigned int  unLen                                     ;
  unsigned char i,ucComMF522Buf[MAXRLEN]                  ; 
    
  ucComMF522Buf[0] = PICC_WRITE                           ;
  ucComMF522Buf[1] = addr                                 ;
  CalulateCRC(ucComMF522Buf,2,&ucComMF522Buf[2])          ;
  status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,4,
                       ucComMF522Buf,&unLen          )    ;
  if(  ( status != MI_OK)||(unLen != 4)
     ||((ucComMF522Buf[0]&0x0F)!= 0x0A))
    status = MI_ERR                                       ;           
  if (status == MI_OK)
  {
    for (i=0; i<16; i++)
      ucComMF522Buf[i] = *(pData+i)                       ;  
    CalulateCRC(ucComMF522Buf,16,&ucComMF522Buf[16])      ;
    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,
                         18,ucComMF522Buf,&unLen     )    ;
    if(  (status != MI_OK)||(unLen != 4 )
       ||((ucComMF522Buf[0]&0x0F)!= 0x0A))
      status = MI_ERR                                     ;   
  }
  return status                                           ;
}
//******************************************************************/
//功    能：写数据到M1卡一块
//参数说明: addr[IN]：块地址
//          pData[IN]：写入的数据，16字节
//返    回: 成功返回MI_OK
//******************************************************************/

char Write_Block(unsigned char Block)
{
  char result                                             ;
  if(des_on)
  {
//     Des_Encrypt((char *)RF_Buffer    ,KK,   (char *)RF_Buffer )                ;// for debug
//     Des_Encrypt((char *)&RF_Buffer[8],KK,   (char *)&RF_Buffer[8]  )                ;// for debug  
  }
  result = PcdAuthState(0x60,Block,RFID_Password_Buffer,RFID_UID)   ;
  if(result!=MI_OK)
    return result                                         ;  
  result = PcdWrite(Block,RFID_Buffer)                      ;
  return result                                           ;  
}

//******************************************************************/
//功    能：扣款和充值
//参数说明: dd_mode[IN]：命令字
//               0xC0 = 扣款
//               0xC1 = 充值
//          addr[IN]：钱包地址
//          pValue[IN]：4字节增(减)值，低位在前
//返    回: 成功返回MI_OK
//******************************************************************/
char PcdValue(unsigned char dd_mode,unsigned char addr,unsigned char *pValue)
{
    u8 status;
    unsigned int  unLen;
    unsigned char i,ucComMF522Buf[MAXRLEN]; 
    
    ucComMF522Buf[0] = dd_mode;
    ucComMF522Buf[1] = addr;
    CalulateCRC(ucComMF522Buf,2,&ucComMF522Buf[2]);
 
    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,4,ucComMF522Buf,&unLen);

    if ((status != MI_OK) || (unLen != 4) || ((ucComMF522Buf[0] & 0x0F) != 0x0A))
    {   status = MI_ERR;   }
        
    if (status == MI_OK)
    {
        for (i=0; i<16; i++)
        {    ucComMF522Buf[i] = *(pValue+i);   }
        CalulateCRC(ucComMF522Buf,4,&ucComMF522Buf[4]);
        unLen = 0;
        status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,6,ucComMF522Buf,&unLen);
        if (status != MI_ERR)
        {    status = MI_OK;    }
    }
    
    if (status == MI_OK)
    {
        ucComMF522Buf[0] = PICC_TRANSFER;
        ucComMF522Buf[1] = addr;
        CalulateCRC(ucComMF522Buf,2,&ucComMF522Buf[2]); 
   
        status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,4,ucComMF522Buf,&unLen);

        if ((status != MI_OK) || (unLen != 4) || ((ucComMF522Buf[0] & 0x0F) != 0x0A))
        {   status = MI_ERR;   }
    }
    return status;
}

//******************************************************************/
//功    能：备份钱包
//参数说明: sourceaddr[IN]：源地址
//          goaladdr[IN]：目标地址
//返    回: 成功返回MI_OK
//******************************************************************/
char PcdBakValue(unsigned char sourceaddr, unsigned char goaladdr)
{
    u8 status;
    unsigned int  unLen;
    unsigned char ucComMF522Buf[MAXRLEN]; 

    ucComMF522Buf[0] = PICC_RESTORE;
    ucComMF522Buf[1] = sourceaddr;
    CalulateCRC(ucComMF522Buf,2,&ucComMF522Buf[2]);
 
    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,4,ucComMF522Buf,&unLen);

    if ((status != MI_OK) || (unLen != 4) || ((ucComMF522Buf[0] & 0x0F) != 0x0A))
    {   status = MI_ERR;   }
    
    if (status == MI_OK)
    {
        ucComMF522Buf[0] = 0;
        ucComMF522Buf[1] = 0;
        ucComMF522Buf[2] = 0;
        ucComMF522Buf[3] = 0;
        CalulateCRC(ucComMF522Buf,4,&ucComMF522Buf[4]);
 
        status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,6,ucComMF522Buf,&unLen);
        if (status != MI_ERR)
        {    status = MI_OK;    }
    }
    
    if (status != MI_OK)
    {    return MI_ERR;   }
    
    ucComMF522Buf[0] = PICC_TRANSFER;
    ucComMF522Buf[1] = goaladdr;

    CalulateCRC(ucComMF522Buf,2,&ucComMF522Buf[2]);
 
    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,4,ucComMF522Buf,&unLen);

    if ((status != MI_OK) || (unLen != 4) || ((ucComMF522Buf[0] & 0x0F) != 0x0A))
    {   status = MI_ERR;   }

    return status;
}


//******************************************************************/
//功    能：命令卡片进入休眠状态
//返    回: 成功返回MI_OK
//******************************************************************/
char PcdHalt(void)
{
    char status;
    unsigned int  unLen;
    unsigned char ucComMF522Buf[MAXRLEN]; 

    ucComMF522Buf[0] = PICC_HALT;
    ucComMF522Buf[1] = 0;
    CalulateCRC(ucComMF522Buf,2,&ucComMF522Buf[2]);
 
    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,4,ucComMF522Buf,&unLen);
    return status;
}

//******************************************************************/
//功    能：命令卡片进入休眠状态
//返    回: 成功返回MI_OK
//******************************************************************/
char MIF_Halt(void)
{
    char status;
    unsigned int  unLen;
    unsigned char ucComMF522Buf[MAXRLEN]; 

    ucComMF522Buf[0] = PICC_HALT;
    ucComMF522Buf[1] = 0;
    CalulateCRC(ucComMF522Buf,2,&ucComMF522Buf[2]);
 
    status = PcdComMF522(PCD_TRANSCEIVE,ucComMF522Buf,4,ucComMF522Buf,&unLen);
    return status ;  
}



//******************************************************************/
//用MF522计算CRC16函数
//******************************************************************/
void CalulateCRC(unsigned char *pIndata,unsigned char len,unsigned char *pOutData)
{
    unsigned char i,n;
    ClearBitMask(DivIrqReg,0x04);
    WriteRawRC(CommandReg,PCD_IDLE);//取消当前命令
    SetBitMask(FIFOLevelReg,0x80);//FlushBuffer 清除ErrReg 的标志位
    for (i=0; i<len; i++)
    {   WriteRawRC(FIFODataReg, *(pIndata+i));   }
    WriteRawRC(CommandReg, PCD_CALCCRC);
    i = 0xFF;
    do 
    {
        n = ReadRawRC(DivIrqReg);
        i--;
    }
    while ((i!=0) && !(n&0x04));//当CRCIRq所有数据被处理完毕该位置位
    pOutData[0] = ReadRawRC(CRCResultRegL);//显示计算出来的CRC值
    pOutData[1] = ReadRawRC(CRCResultRegM);
}
