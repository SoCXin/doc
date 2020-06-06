/******************** (C) COPYRIGHT  QITAS ********************************
 * 文件名  ：timer.c
 * 描述    ：初始化通用定时器TIM3，实现TIM3定时功能    
 * 作者    ：QITAS
 * 调试方式：J-Link-OB
****************************************************************************/	

#include "timer.h"

//变量定义
uint16_t TIM_Count;	//定时器计数
void TimerNvic_Config(void);

 /**
  * @file   TimerNvic_Config
  * @brief  系统中断配置
  * @param  无
  * @retval 无
  */
void TimerNvic_Config(void)
{ 	
	NVIC_InitTypeDef	NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0); 		//设置中断组为2
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn; 		//中断事件为TIM3
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 	//抢占优先级0   
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;      //响应优先级1 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;         //允许中断 
	NVIC_Init(&NVIC_InitStructure);                         //根据指定参数初始化中断寄存器
}

 /**
  * @file   TIM3_Config
  * @brief  调用函数库，初始化定时器2的配置
  * @param  无
  * @retval 无
  */
void TIM3_Config(void)
{
	//定时器定时时间T计算公式：T=(TIM_Period+1)*(TIM_Prescaler+1)/TIMxCLK
	TIM_TimeBaseInitTypeDef	 TIM_BaseInitStructure;			//定义一个定时器结构体变量
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);   	//使能定时器2
	TIM_DeInit( TIM3);//将IM2定时器初始化位复位值
	TIM_InternalClockConfig(TIM3);//配置 TIM3 内部时钟
	TIM_BaseInitStructure.TIM_Period = 1000;//设置自动重载寄存器值为最大值	0~65535之间  1000000/1000=1000us=1ms													
	//TIM_Period（TIM1_ARR）=1000，计数器向上计数到1000后产生更新事件，计数值归零 也就是 1MS产生更新事件一次
	TIM_BaseInitStructure.TIM_Prescaler = 71;//自定义预分频系数，提供给定时器的时钟	0~65535之间
													//设置预分频器分频系数71，即CK_INT=72M, TIM1_CLK=72/72=1MHz 
	TIM_BaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; //时钟分割为0
	TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   
													//TIM向上计数模式 从0开始向上计数，计数到1000后产生更新事件
	TIM_TimeBaseInit(TIM3, &TIM_BaseInitStructure); //根据指定参数初始化TIM时间基数寄存器
	TIM_ClearFlag(TIM3, TIM_FLAG_Update);//清中断，以免一启用中断后立即产生中断 
	TIM_ARRPreloadConfig(TIM3, DISABLE);//禁止ARR 预装载缓冲器
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);//使能TIM3中断源 
	TIM_Cmd(TIM3, ENABLE);//TIM3总开关：开启
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , ENABLE);		/*先关闭等待使用*/
  	TimerNvic_Config();
}



void TimerNvic_TIM4_Config(void)
{ 	
	NVIC_InitTypeDef	NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0); 		//设置中断组为2
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn; 		//中断事件为TIM4
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 	//抢占优先级0   
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;      //响应优先级1 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;         //允许中断 
	NVIC_Init(&NVIC_InitStructure);                         //根据指定参数初始化中断寄存器
}

 /**
  * @file   TIM4_Config
  * @brief  调用函数库，初始化定时器2的配置
  * @param  无
  * @retval 无
  */
void TIM4_Start(void)
{
	//定时器定时时间T计算公式：T=(TIM_Period+1)*(TIM_Prescaler+1)/TIMxCLK
	TIM_TimeBaseInitTypeDef	 TIM_BaseInitStructure;			//定义一个定时器结构体变量
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);   	//使能定时器4
	TIM_DeInit( TIM4);//将IM2定时器初始化位复位值
	TIM_InternalClockConfig(TIM4);//配置 TIM4 内部时钟
	TIM_BaseInitStructure.TIM_Period = 5000-1;//设置自动重载寄存器值为最大值	0~65535之间  1000000/1000=1000us=1ms													
	//TIM_Period（TIM1_ARR）=1000，计数器向上计数到1000后产生更新事件，计数值归零 也就是 1MS产生更新事件一次
	TIM_BaseInitStructure.TIM_Prescaler = 144 - 1;//自定义预分频系数，提供给定时器的时钟	0~65535之间
													//设置预分频器分频系数71，即CK_INT=72M, TIM1_CLK=72/72=1MHz 
	TIM_BaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1; //时钟分割为0
	TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   
													//TIM向上计数模式 从0开始向上计数，计数到1000后产生更新事件
	TIM_TimeBaseInit(TIM4, &TIM_BaseInitStructure); //根据指定参数初始化TIM时间基数寄存器
	TIM_ClearFlag(TIM4, TIM_FLAG_Update);//清中断，以免一启用中断后立即产生中断 
	TIM_ARRPreloadConfig(TIM4, DISABLE);//禁止ARR 预装载缓冲器
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);//使能TIM4中断源 
	TIM_Cmd(TIM4, ENABLE);//TIM4总开关：开启
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4 , ENABLE);
  TimerNvic_TIM4_Config();
}

