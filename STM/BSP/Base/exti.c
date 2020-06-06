/******************** (C) COPYRIGHT  源地工作室 ********************************
 * 文件名  ：exti.c
 * 描述    ：按键引脚配置
 * 作者    ：zhuoyingxingyu
 * 淘宝    ：源地工作室http://vcc-gnd.taobao.com/
 * 论坛地址：极客园地-嵌入式开发论坛http://vcc-gnd.com/
 * 版本更新: 2017-05-12
 * 硬件连接: 无
 * 调试方式：J-Link-OB
**********************************************************************************/
//头文件  
#include "exti.h"
#include "led.h"
#include "Relay.h"
#include "key.h"
#include "user_config.h"
#include <stm32f10x.h>
#include <stdlib.h>
#include "strength_lp.h"

//3号按钮
//u8 	g_btn3_count = 0;

//函数声明
void Delay(u32 n);

 /**
  * @file   Exti_Config
  * @brief  调用函数库，初始化中断配置
  * @param  无
  * @retval 无
  */
void Exti_Config(void)
{	
	/*查看外部中断/事件线路映像
  PA0、PB0、PC0、PD0、PE0、PF0、PG0 ————>映像于 EXTI0
  PA1、PB1、PC1、PD1、PE1、PF1、PG1 ————>映像于 EXTI1
  PA2、PB2、PC2、PD2、PE2、PF2、PG2 ————>映像于 EXTI2
  PA3、PB3、PC3、PD3、PE3、PF3、PG3 ————>映像于 EXTI3
  .......依次类推，每个外部中断都有一个事件线路映射*/
  //定义一个EXTI_InitTypeDef 类型的结构体
  EXTI_InitTypeDef EXTI_InitStructure;
  //使能AFIO功能的时钟
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE); 
	
		//////////////////////////////////////////////////////////////////////////
	
	if(g_user_config.type != 0)
	{
		EXTI_ClearITPendingBit(KEY1_BUTTON_EXTI_LINE);

		//设置PC14,作为中断线路
		GPIO_EXTILineConfig(KEY1_BUTTON_EXTI_PORT_SOURCE, KEY1_BUTTON_EXTI_PIN_SOURCE);
		//选择中断线路,
		EXTI_InitStructure.EXTI_Line = KEY1_BUTTON_EXTI_LINE; 
		//设置为中断请求触发模式
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
		//设置为下降沿触发
		EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
		//设置为使能中断线
		EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		//调用库函数，初始化中断
		EXTI_Init(&EXTI_InitStructure);
	}
	
	//////////////////////////////////////////////////////////////////////////
	
	EXTI_ClearITPendingBit(KEY2_BUTTON_EXTI_LINE);

  //设置PC14,作为中断线路
  GPIO_EXTILineConfig(KEY2_BUTTON_EXTI_PORT_SOURCE, KEY2_BUTTON_EXTI_PIN_SOURCE);
  //选择中断线路,
  EXTI_InitStructure.EXTI_Line = KEY2_BUTTON_EXTI_LINE; 
  //设置为中断请求触发模式
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  //设置为下降沿触发
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
  //设置为使能中断线
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  //调用库函数，初始化中断
  EXTI_Init(&EXTI_InitStructure);
	
		
	//////////////////////////////////////////////////////////////////////////
	EXTI_ClearITPendingBit(KEY3_BUTTON_EXTI_LINE);
	//设置PC15,作为中断线路
  GPIO_EXTILineConfig(KEY3_BUTTON_EXTI_PORT_SOURCE, KEY3_BUTTON_EXTI_PIN_SOURCE);
  //选择中断线路,
  EXTI_InitStructure.EXTI_Line = KEY3_BUTTON_EXTI_LINE; 
  //设置为中断请求触发模式
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  //设置为下降沿触发
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
  //设置为使能中断线
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  //调用库函数，初始化中断
  EXTI_Init(&EXTI_InitStructure);
	
	
	Nvic_Config();
}
/**
  * @file   nvic_config
  * @brief  调用库函数，初始化中断向量
  * @param  无
  * @retval 无
  */
void Nvic_Config()
{
 
  NVIC_InitTypeDef NVIC_InitStructure; //定义一个NVIC_InitTypeDef 类型的结构体
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0); //选择中断分组0	
	
  NVIC_InitStructure.NVIC_IRQChannel = KEY_BUTTON_EXTI_IRQn;//配置选中的中断向量,指定中断源
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =1; //配置抢占优先级:抢占式中断优先级设置为0
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; //配置响应优先级:响应式中断优先级设置为0
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //使能中断向量
  NVIC_Init(&NVIC_InitStructure);  //初始化NVIC
}

/**
  * @file   EXTI15_10_IRQHandler
  * @brief  中断处理函数
  * @param  无
  * @retval 无
  */

static unsigned int key1_limit = 0;
static unsigned int key2_limit = 0;
static unsigned int key3_limit = 0;
void EXTI15_10_IRQHandler(void)
{   
	
	if (EXTI_GetITStatus(KEY1_BUTTON_EXTI_LINE) != RESET)
  { 
    /*清除EXTI线路挂起位*/
    EXTI_ClearITPendingBit(KEY1_BUTTON_EXTI_LINE);
		
		eg_strength_lp_btn(g_time_now_ms - key1_limit, 1);
		key1_limit = g_time_now_ms;
  }
	
	else if (EXTI_GetITStatus(KEY2_BUTTON_EXTI_LINE) != RESET)
  { 
    /*清除EXTI线路挂起位*/
    EXTI_ClearITPendingBit(KEY2_BUTTON_EXTI_LINE);
		
		eg_strength_lp_btn(g_time_now_ms - key2_limit, 2);
		key2_limit = g_time_now_ms;
  }
	
	else if (EXTI_GetITStatus(KEY3_BUTTON_EXTI_LINE) != RESET)      //次数
  { 
		/*清除EXTI线路挂起位*/
    EXTI_ClearITPendingBit(KEY3_BUTTON_EXTI_LINE);
		
		if((unsigned int)(g_time_now_ms - key3_limit) > 300) 
		{
			//g_btn3_count++;
			key3_limit = g_time_now_ms;
		}
  }
}
