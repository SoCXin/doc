/******************** (C) COPYRIGHT  ********************************
 * 文件名  ：w5500_conf.c
 * 描述    ：配置MCU，移植W5500程序需要修改的文件，配置W5500的MAC和IP地址
 * 作者    ：WIZnet Software Team
 * 版本    ：V1.0
**********************************************************************************/
#include "w5500_conf.h"
#include "i2c.h"
#include "SPIx.h"
#include "timer.h"
#include "w5500.h"
#include "dhcp.h"
#include "SYSTICK.h"

CONFIG_MSG  ConfigMsg;																	/*配置结构体*/
EEPROM_MSG_STR EEPROM_MSG;															/*EEPROM存储信息结构体*/

/*定义MAC地址,如果多块W5500网络适配板在同一现场工作，请使用不同的MAC地址*/
uint8 mac[6]={0x31,0x37,0x47,0x35,0x16,0x1f};

/*定义默认IP信息*/
uint8 local_ip[4]={10,0,1,75};												/*定义W5500默认IP地址*/
uint8 local_ip_str[20]={0};	
uint8 subnet[4]={255,255,252,0};											/*定义W5500默认子网掩码*/
uint8 gateway[4]={10,0,0,1};													/*定义W5500默认网关*/
uint8 dns_server[4]={114,114,114,114};									/*定义W5500默认DNS*/

uint16 local_port=5000;	                       					/*定义本地端口*/

/*定义远端IP信息*/
uint8  remote_ip[4]={192,168,1,151};											/*远端IP地址*/
uint16 remote_port=5000;																/*远端端口号*/

uint8 	dhcp_ok=0;																			/*dhcp成功获取IP*/
uint32	ms=0;																						/*毫秒计数*/
uint32	dhcp_time= 0;																		/*DHCP运行计数*/
vu8			ntptimer = 0;																		/*NPT秒计数*/

/**
*@brief		配置W5500的IP地址
*@param		无
*@return	无
*/
void set_w5500_ip(uint8_t ip_from)
{	
 /*复制定义的配置信息到配置结构体*/
	memcpy(ConfigMsg.mac, mac, 6);
	memcpy(ConfigMsg.lip,local_ip,4);
	memcpy(ConfigMsg.sub,subnet,4);
	memcpy(ConfigMsg.gw,gateway,4);
	memcpy(ConfigMsg.dns,dns_server,4);
	
	if(ip_from==IP_FROM_DEFINE)	
		printf(" 使用定义的IP信息配置W5500\r\n");
	
	/*使用EEPROM存储的IP参数*/	
	if(ip_from==IP_FROM_EEPROM)
	{
		/*从EEPROM中读取IP配置信息*/
		read_config_from_eeprom();		
		
		/*如果读取EEPROM中MAC信息,如果已配置，则可使用*/		
		if( *(EEPROM_MSG.mac)==0x00&& *(EEPROM_MSG.mac+1)==0x08&&*(EEPROM_MSG.mac+2)==0xdc)		
		{
			printf(" IP from EEPROM\r\n");
			/*复制EEPROM配置信息到配置的结构体变量*/
			memcpy(ConfigMsg.lip,EEPROM_MSG.lip, 4);				
			memcpy(ConfigMsg.sub,EEPROM_MSG.sub, 4);
			memcpy(ConfigMsg.gw, EEPROM_MSG.gw, 4);
		}
		else
		{
			printf(" EEPROM未配置,使用定义的IP信息配置W5500,并写入EEPROM\r\n");
			write_config_to_eeprom();	/*使用默认的IP信息，并初始化EEPROM中数据*/
		}			
	}

	/*使用DHCP获取IP参数，需调用DHCP子函数*/		
	if(ip_from==IP_FROM_DHCP)								
	{
		/*复制DHCP获取的配置信息到配置结构体*/
		if(dhcp_ok==1)
		{
			printf(" IP from DHCP\r\n");		 
			memcpy(ConfigMsg.lip,DHCP_GET.lip, 4);
			memcpy(ConfigMsg.sub,DHCP_GET.sub, 4);
			memcpy(ConfigMsg.gw,DHCP_GET.gw, 4);
			memcpy(ConfigMsg.dns,DHCP_GET.dns,4);
		}
		else
		{
			printf(" DHCP子程序未运行,或者不成功\r\n");
			printf(" 使用定义的IP信息配置W5500\r\n");
		}
	}
		
	/*以下配置信息，根据需要选用*/	
	ConfigMsg.sw_ver[0]=FW_VER_HIGH;
	ConfigMsg.sw_ver[1]=FW_VER_LOW;	

	/*将IP配置信息写入W5500相应寄存器*/	
	setSUBR(ConfigMsg.sub);
	setGAR(ConfigMsg.gw);
	setSIPR(ConfigMsg.lip);
	getSIPR (local_ip);			
	printf(" W5500 IP地址   : %d.%d.%d.%d\r\n", local_ip[0],local_ip[1],local_ip[2],local_ip[3]);
	getSUBR(subnet);
	printf(" W5500 子网掩码 : %d.%d.%d.%d\r\n", subnet[0],subnet[1],subnet[2],subnet[3]);
	getGAR(gateway);
	printf(" W5500 网关     : %d.%d.%d.%d\r\n", gateway[0],gateway[1],gateway[2],gateway[3]);
}

char *get_w5500_ip(void)
{
	memset(local_ip_str, 0, sizeof(local_ip_str));
	sprintf((char *)local_ip_str, "%d.%d.%d.%d", local_ip[0],local_ip[1],local_ip[2],local_ip[3]);
	return (char *)local_ip_str;
}

/**
*@brief		配置W5500的MAC地址
*@param		无
*@return	无
*/
void set_w5500_mac(void)
{
	memcpy(ConfigMsg.mac, mac, 6);
	setSHAR(ConfigMsg.mac);	/**/
	memcpy(DHCP_GET.mac, mac, 6);
}

/**
*@brief		配置W5500的GPIO接口
*@param		无
*@return	无
*/
void gpio_for_w5500_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	 /*初始化STM32 SPI2接口*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	/* Configure SPIy pins: SCK(PB13) MISO(PB14) and MOSI(PB15)*/
	GPIO_InitStructure.GPIO_Pin   = WIZ_SCLK|WIZ_MISO|WIZ_MOSI;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* Configure SPIy pins: WIZ_SCS(PB12) */
	GPIO_InitStructure.GPIO_Pin   = WIZ_SCS;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB, WIZ_SCS);
	                                                                                                         
	/* Configure SPIy pins: WIZ_RESET(PB11) */
	GPIO_InitStructure.GPIO_Pin   = WIZ_RESET;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB, WIZ_RESET);
	
	/* Configure SPIy pins: WIZ_INT(PB10) */
	GPIO_InitStructure.GPIO_Pin   = WIZ_INT;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	WIZ_SPI_Init();		
}

 /**
  * @file   W5500片选信号设置函数
  * @brief  val: 为“0”表示片选端口为低，为“1”表示片选端口为高
  * @param  无
  * @retval 无
  */
void wiz_cs(uint8_t val)
{
	if (val == LOW)
	{
    GPIO_ResetBits(WIZ_SCS_GPIO_PORT, WIZ_SCS); 
  }
	else if (val == HIGH)
	{
    GPIO_SetBits(WIZ_SCS_GPIO_PORT, WIZ_SCS); 
  }
}


/**
*@brief		设置W5500的片选端口SCSn为低
*@param		无
*@return	无
*/
void iinchip_csoff(void)
{
	wiz_cs(LOW);
}

/**
*@brief		设置W5500的片选端口SCSn为高
*@param		无
*@return	无
*/
void iinchip_cson(void)
{	
   wiz_cs(HIGH);
}

/**
*@brief		W5500复位设置函数
*@param		无
*@return	无
*/
void reset_w5500(void)
{	
    GPIO_ResetBits(WIZ_RESET_GPIO_PORT, WIZ_RESET);
		delay_ms(1);
    GPIO_SetBits(WIZ_RESET_GPIO_PORT, WIZ_RESET);
    delay_ms(200);	
}

/**
*@brief		STM32 SPI2读写8位数据
*@param		dat：写入的8位数据
*@return	无
*/
uint8  IINCHIP_SpiSendData(uint8 dat)
{
   return(SPIX_SendByte(dat));
}

/**
*@brief		写入一个8位数据到W5500
*@param		addrbsb: 写入数据的地址
*@param   data：写入的8位数据
*@return	无
*/
void IINCHIP_WRITE( uint32 addrbsb,  uint8 data)
{
   iinchip_csoff();                              		
   IINCHIP_SpiSendData( (addrbsb & 0x00FF0000)>>16);	
   IINCHIP_SpiSendData( (addrbsb & 0x0000FF00)>> 8);
   IINCHIP_SpiSendData( (addrbsb & 0x000000F8) + 4);  
   IINCHIP_SpiSendData(data);                   
   iinchip_cson();                            
}

/**
*@brief		从W5500读出一个8位数据
*@param		addrbsb: 写入数据的地址
*@param   data：从写入的地址处读取到的8位数据
*@return	无
*/
uint8 IINCHIP_READ(uint32 addrbsb)
{
   uint8 data = 0;
   iinchip_csoff();                            
   IINCHIP_SpiSendData( (addrbsb & 0x00FF0000)>>16);
   IINCHIP_SpiSendData( (addrbsb & 0x0000FF00)>> 8);
   IINCHIP_SpiSendData( (addrbsb & 0x000000F8))    ;
   data = IINCHIP_SpiSendData(0x00);            
   iinchip_cson();                               
   return data;    
}

/**
*@brief		向W5500写入len字节数据
*@param		addrbsb: 写入数据的地址
*@param   buf：写入字符串
*@param   len：字符串长度
*@return	len：返回字符串长度
*/
uint16 wiz_write_buf(uint32 addrbsb,uint8* buf,uint16 len)
{
   uint16 idx = 0;
   if(len == 0) printf("Unexpected2 length 0\r\n");
   iinchip_csoff();                               
   IINCHIP_SpiSendData( (addrbsb & 0x00FF0000)>>16);
   IINCHIP_SpiSendData( (addrbsb & 0x0000FF00)>> 8);
   IINCHIP_SpiSendData( (addrbsb & 0x000000F8) + 4); 
   for(idx = 0; idx < len; idx++)
   {
     IINCHIP_SpiSendData(buf[idx]);
   }
   iinchip_cson();                           
   return len;  
}

/**
*@brief		从W5500读出len字节数据
*@param		addrbsb: 读取数据的地址
*@param 	buf：存放读取数据
*@param		len：字符串长度
*@return	len：返回字符串长度
*/
uint16 wiz_read_buf(uint32 addrbsb, uint8* buf,uint16 len)
{
  uint16 idx = 0;
  if(len == 0)
  {
    printf("Unexpected2 length 0\r\n");
  }
  iinchip_csoff();                                
  IINCHIP_SpiSendData( (addrbsb & 0x00FF0000)>>16);
  IINCHIP_SpiSendData( (addrbsb & 0x0000FF00)>> 8);
  IINCHIP_SpiSendData( (addrbsb & 0x000000F8));    
  for(idx = 0; idx < len; idx++)                   
  {
    buf[idx] = IINCHIP_SpiSendData(0x00);
  }
  iinchip_cson();                                  
  return len;
}

/**
*@brief		写配置信息到EEPROM
*@param		无
*@return	无
*/
void write_config_to_eeprom(void)
{
	uint16 dAddr=0;
	I2C_WriteBytes(ConfigMsg.mac,dAddr,(uint8)EEPROM_MSG_LEN);				
	delay_ms(10);																							
}

/**
*@brief		从EEPROM读配置信息
*@param		无
*@return	无
*/
void read_config_from_eeprom(void)
{
	I2C_ReadBytes(EEPROM_MSG.mac,EEPROM_MSG_LEN,0,ADDR_24C08);
	delay_ms(1);
	//delay_us(10);
}

void  WizW5500_Init(uint8_t ipflag)
{
	uint8_t 		ipfrom;
	__IO u8		 *uid;

	//初始化MAC地址
	uid = (__IO u8*)(0X1FFFF7E8);
	memcpy(mac, (char *)(uid + 6), 6);
	//很关键第4-8位必须是偶数-(第一个字节必须是偶数)
	mac[0] &= 0xfe;
	printf("mac:%02x%02x%02x%02x%02x%02x\r\n", mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);

	
	ipfrom=ipflag;
	gpio_for_w5500_config();						/*初始化MCU相关引脚*/
	reset_w5500();									/*硬复位W5500*/

	
	set_w5500_mac();										/*配置MAC地址*/
	if (ipfrom==IP_FROM_DEFINE||ipfrom==IP_FROM_EEPROM)
	{
		set_w5500_ip(ipfrom);				/*配置IP地址*/
	}
	socket_buf_init(txsize, rxsize);		/*初始化8个Socket的发送接收缓存大小*/

}


/**
*@brief		STM32定时器2初始化
*@param		无
*@return	无
*/
//void timer3_init(void)
//{													
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , ENABLE);		/* TIM3 重新开时钟，开始计时 */
//}

/**
*@brief		dhcp用到的定时器初始化
*@param		无
*@return	无
*/
void dhcp_timer_init(void)
{
	static u8 t3_is_init = 0;
	if(t3_is_init != 0)
		return;
	t3_is_init = 1;
	
	TIM3_Config();/* TIM3 定时配置 */																
}

/**
*@brief		定时器2中断函数
*@param		无
*@return	无
*/
void timer3_isr(void)
{
	ms++;	
  if(ms>=1000)
  {  
    ms=0;
    dhcp_time++;																					/*DHCP定时加1S*/
  }

}


