/******************** (C) COPYRIGHT  源地工作室 ********************************
 * 文件名  ：key.c
 * 描述    ：按键引脚配置
 * 作者    ：zhuoyingxingyu
 * 淘宝    ：源地工作室http://vcc-gnd.taobao.com/
 * 论坛地址：极客园地-嵌入式开发论坛http://vcc-gnd.com/
 * 版本更新: 2015-10-20
 * 硬件连接  :S1->PB14;S2->PB15;S3->PB5
 * 调试方式：J-Link-OB
**********************************************************************************/

// 头文件
#include "key.h"

 /**
  * @file   KEY_GPIO_Config
  * @brief  按键引脚配置
  * @param  无
  * @retval 无
  */
void KEY_GPIO_Config(void)
{	
	//定义一个GPIO_InitTypeDef 类型的结构体
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(KEY1_BUTTON_GPIO_RCC,ENABLE);//开启GPIOC的外设时钟
	RCC_APB2PeriphClockCmd(KEY2_BUTTON_GPIO_RCC,ENABLE);//开启GPIOC的外设时钟
	RCC_APB2PeriphClockCmd(KEY3_BUTTON_GPIO_RCC,ENABLE);//开启GPIOC的外设时钟
	RCC_APB2PeriphClockCmd(KEY4_BUTTON_GPIO_RCC,ENABLE);//开启GPIOA的外设时钟
	
	GPIO_InitStructure.GPIO_Pin = KEY1_BUTTON_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//GPIO_Mode_IN_FLOATING; 			 
	GPIO_Init(KEY1_BUTTON_GPIO_PORT, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = KEY2_BUTTON_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//GPIO_Mode_IN_FLOATING; 			 
	GPIO_Init(KEY2_BUTTON_GPIO_PORT, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = KEY3_BUTTON_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//GPIO_Mode_IN_FLOATING; 			 
	GPIO_Init(KEY3_BUTTON_GPIO_PORT, &GPIO_InitStructure); 
	
	GPIO_InitStructure.GPIO_Pin = KEY4_BUTTON_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//GPIO_Mode_IN_FLOATING; 			 
	GPIO_Init(KEY4_BUTTON_GPIO_PORT, &GPIO_InitStructure); 
}

