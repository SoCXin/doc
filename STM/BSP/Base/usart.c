/******************** (C) COPYRIGHT  源地工作室 ********************************
 * 文件名  ：usart.c
 * 描述    ：将printf函数重定向到USART1。这样就可以用printf函数将单片机的数据打
 *           印到PC上的超级终端或串口调试助手。     
 * 作者    ：zhuoyingxingyu
 * 淘宝    ：源地工作室http://vcc-gnd.taobao.com/
 * 论坛地址：极客园地-嵌入式开发论坛http://vcc-gnd.com/
 * 版本更新: 2015-11-11
 * 硬件连接: TX->PA9;RX->PA10
 * 调试方式：J-Link-OB
**********************************************************************************/	

//头文件
#include "usart.h"
#include "user_config.h"

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */


 /**
  * @file   USART1_Config
  * @brief  USART1 GPIO 配置,工作模式配置。9600-8-N-1
  * @param  无
  * @retval 无
  */
void USART1_Config_ttl(uint32_t BaudRate)
{	
    GPIO_InitTypeDef GPIO_InitStructure;	
    USART_InitTypeDef USART_InitStructure;  //定义串口初始化结构体
	
    RCC_APB2PeriphClockCmd( USART_RCC_TTL | USART_GPIO_RCC,ENABLE);

    /*USART1_TX ->PA9*/			
    GPIO_InitStructure.GPIO_Pin = USART_TX_TTL;	       //选中串口默认输出管脚         
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //定义输出最大速率 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//定义管脚9的模式  
    GPIO_Init(USART_GPIO_PORT, &GPIO_InitStructure);           //调用函数，把结构体参数输入进行初始化		   
    /*USART1_RX ->PA10*/
    GPIO_InitStructure.GPIO_Pin = USART_RX_TTL;	        
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_Init(USART_GPIO_PORT, &GPIO_InitStructure);
    /*串口通讯参数设置*/
    USART_InitStructure.USART_BaudRate = BaudRate; //波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位8位
    USART_InitStructure.USART_StopBits = USART_StopBits_1;	//停止位1位
    USART_InitStructure.USART_Parity = USART_Parity_No;		//校验位 无
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无流控制
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;		//使能接收和发送引脚

    USART_Init(USART_TTL, &USART_InitStructure);
		USART_ClearFlag(USART_TTL,USART_FLAG_TC);
		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    USART_Cmd(USART_TTL, ENABLE);
		
		NVIC1_Configuration_ttl();
}

void NVIC1_Configuration_ttl(void)
{
  NVIC_InitTypeDef NVIC_InitStructure; 
  /* Configure the NVIC Preemption Priority Bits */  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
  
  /* Enable the USARTy Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}


void USART2_Config_232(uint32_t BaudRate)
{	
  GPIO_InitTypeDef GPIO_InitStructure;	
  USART_InitTypeDef USART_InitStructure;  //定义串口初始化结构体
  RCC_APB2PeriphClockCmd(USART_GPIO_RCC,ENABLE);	
  RCC_APB1PeriphClockCmd(USART_RCC_232,ENABLE);
 
  /*USART2_TX ->PA2*/			
  GPIO_InitStructure.GPIO_Pin = USART_TX_232;	       //选中串口默认输出管脚         
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //定义输出最大速率 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//定义管脚2的模式  
  GPIO_Init(USART_GPIO_PORT, &GPIO_InitStructure);           //调用函数，把结构体参数输入进行初始化		   
  /*USART2_RX ->PA3*/
  GPIO_InitStructure.GPIO_Pin = USART_RX_232;	        
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
  GPIO_Init(USART_GPIO_PORT, &GPIO_InitStructure);
  /*串口通讯参数设置*/
  USART_InitStructure.USART_BaudRate = BaudRate; //波特率
  USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位8位
  USART_InitStructure.USART_StopBits = USART_StopBits_1;	//停止位1位
  USART_InitStructure.USART_Parity = USART_Parity_No;		//校验位 无
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无流控制
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;		//使能接收和发送引脚
   /*将以上赋完值的结构体带入库函数USART_Init进行初始化*/
  USART_Init(USART_232, &USART_InitStructure); 
	USART_ITConfig(USART_232,USART_IT_RXNE,ENABLE);//使能串口中断接收
  USART_Cmd(USART_232, ENABLE);//开启USART2
		
	NVIC2_Configuration_232();
}

void NVIC2_Configuration_232(void)
{
  NVIC_InitTypeDef NVIC_InitStructure; 
  /* Configure the NVIC Preemption Priority Bits */  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
  
  /* Enable the USARTy Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;	 
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

void sendDatatoTTL(char *buff, int reqLen)
{
	int i;
	USART_GetFlagStatus(USART_TTL, USART_FLAG_TC);
	for(i = 0; i< reqLen; i++)
	{
		USART_SendData(USART_TTL, (uint8_t) buff[i]);
		while (USART_GetFlagStatus(USART_TTL, USART_FLAG_TC) == RESET);
	}
}

void sendDatatoRS232(char *buff, int reqLen)
{
	int i;
	
	///////////////////////////////过滤发送的协议，本来应该放到232的
	if(g_user_config.pass_232_len != 0xFFFFFFFF  && g_user_config.pass_232_len != 0 && g_user_config.pass_232_len < 0xFFFF)
	{
		if(reqLen != g_user_config.pass_232_len || 
			buff[0] != g_user_config.pass_232_start || 
			buff[reqLen-1] != g_user_config.pass_232_end)
			return;
	}
	///////////////////////////
	
	USART_GetFlagStatus(USART_232, USART_FLAG_TC);
	for(i = 0; i< reqLen; i++)
	{
		USART_SendData(USART_232, (uint8_t) buff[i]);
		while (USART_GetFlagStatus(USART_232, USART_FLAG_TC) == RESET);
	}
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
	if(g_show_printf)
	{
		/* Place your implementation of fputc here */
		/* e.g. write a character to the USART */
		USART_SendData(PRINT_USART, (uint8_t) ch);
		/* Loop until the end of transmission */
		while (USART_GetFlagStatus(PRINT_USART, USART_FLAG_TC) == RESET)
		{}
	}
  return ch;
}
