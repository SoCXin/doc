/******************** (C) COPYRIGHT  QITAS ********************************
 * 文件名  ：systick.c
 * 描述    ：嘀嗒定时器实现ms延时，us延时   
 * 作者    ：QITAS
 * 调试方式：J-Link-OB
****************************************************************************/	

#include "SYSTICK.h"

extern u16 nTime;

 /**
  * @file   SYSTICK_Init
  * @brief  初始化SYSTICK，1us中断1次
  * @param  无
  * @retval 无
  */
void SYSTICK_Init(void)
{	
/*SystemCoreClock/ 1000000：1us中断1次；SystemCoreClock/ 1000：1ms中断一次*/	
  while (SysTick_Config(SystemCoreClock/1000));
}

 /**
  * @file   delay_us
  * @brief  微妙延时
  * @param  延时时间
  * @retval 无
  */
//void delay_us(u16 nus)
//{
//  nTime=nus;
//  while(nTime);
//}

 /**
  * @file   delay_ms
  * @brief  毫秒延时
  * @param  延时时间
  * @retval 无
  */
void delay_ms(u16 nms)
{
	nTime=nms;
	while(nTime);
	
//  while(nms--)
//  delay_us(1000);
}

