/******************** (C) COPYRIGHT  源地工作室 ********************************
 * 文件名  ：Relay.c
 * 描述    ：继电器GPIO引脚配置   
 * 作者    ：zhuoyingxingyu
 * 淘宝    ：源地工作室http://vcc-gnd.taobao.com/
 * 论坛地址：极客园地-嵌入式开发论坛http://vcc-gnd.com/
 * 版本更新: 2015-10-20
 * 硬件连接: Relay_GPIO-->PB3
 * 调试方式：J-Link-OB
**********************************************************************************/	

//头文件
#include "Relay.h"
#include "user_config.h"

 /**
  * @file   LED_GPIO_Config
  * @brief  LED灯引脚配置
  * @param  无
  * @retval 无
  */
void Relay_GPIO_Config(void)
{	
    //定义一个GPIO_InitTypeDef 类型的结构体
		GPIO_InitTypeDef  GPIO_InitStructure;	
		/*PB3为jtag接口，在没有关闭jtag功能之前，在程序中无法配置成普通IO口模式，需要配置这个引脚
		首先要开启AFIO时钟，然后在AFIO的设置中，释放这个引脚*/
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO  | RCC_APB2Periph_GPIOB , ENABLE);
		GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
		RCC_APB2PeriphClockCmd(Relay_GPIO_RCC | Relay_GPIO_RCC_1,ENABLE);//使能GPIO的外设时钟

	
		/*Relay 0*/
		GPIO_InitStructure.GPIO_Pin = Relay_GPIO_PIN;//选择要用的GPIO引脚
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //设置引脚模式为推免输出模式						 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//设置引脚速度为50MHZ         
		GPIO_Init(Relay_GPIO_PORT, &GPIO_InitStructure);//调用库函数，初始化GPIO
		REALY0_OFF;
		
		/*Relay 1*/
		GPIO_InitStructure.GPIO_Pin = Relay_GPIO_PIN_1;//选择要用的GPIO引脚
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //设置引脚模式为推免输出模式						 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//设置引脚速度为50MHZ         
		GPIO_Init(Relay_GPIO_PORT_1, &GPIO_InitStructure);//调用库函数，初始化GPIO
		REALY1_OFF;
}

void Relay_Switch(char id, char on)
{
	//如果是广州有线版取反
	if(g_user_config.hd_version == HD_VERSION_GZ)
		on = !on;
	
	if(id == 1)
	{
		if(on == 1)
			GPIO_SetBits(Relay_GPIO_PORT, Relay_GPIO_PIN);
		else
			GPIO_ResetBits(Relay_GPIO_PORT, Relay_GPIO_PIN);
	}
	else if(id == 2)
	{
		if(on == 1)
			GPIO_SetBits(Relay_GPIO_PORT_1, Relay_GPIO_PIN_1);
		else
			GPIO_ResetBits(Relay_GPIO_PORT_1, Relay_GPIO_PIN_1);
	}
}

char Relay_Status(char id)
{
	char ret = 0;
	
	if(id == 1)
	{
		ret = GPIO_ReadOutputDataBit(Relay_GPIO_PORT, Relay_GPIO_PIN);
	}
	else if(id == 2)
	{
		ret = GPIO_ReadOutputDataBit(Relay_GPIO_PORT_1, Relay_GPIO_PIN_1);
	}
	
	//广州版返回的取反
	if(g_user_config.hd_version == HD_VERSION_GZ)
		ret = !ret;
	
	return ret;
}


