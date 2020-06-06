#include "beep.h"
#include "user_config.h"

void eg_beep_GPIO_config(void)
{
	//定义一个GPIO_InitTypeDef 类型的结构体
	GPIO_InitTypeDef  GPIO_InitStructure;	
	/*PB3为jtag接口，在没有关闭jtag功能之前，在程序中无法配置成普通IO口模式，需要配置这个引脚
	首先要开启AFIO时钟，然后在AFIO的设置中，释放这个引脚*/
	RCC_APB2PeriphClockCmd(BEEP_GPIO_RCC , ENABLE); //使能GPIO的外设时钟

	//////////////////////////////////
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	//很关键要关掉JTAG功能 应为PA15被占用了 
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	//////////////////////////////////

	/*蜂鸣器 0*/
	GPIO_InitStructure.GPIO_Pin = BEEP_GPIO_PIN;//选择要用的GPIO引脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //设置引脚模式为推免输出模式						 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//设置引脚速度为50MHZ         
	GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStructure);//调用库函数，初始化GPIO
	
	//默认会打开 要关掉
	BEEP_OFF;
}

//static char g_beep_status = 0;

//void eg_beep_switch(char on)
//{
//	if(g_user_config.hd_version == HD_VERSION_GZ)
//	{
//		if(on)
//			GPIO_SetBits(BEEP_GPIO_PORT, BEEP_GPIO_PIN);
//		else
//			GPIO_ResetBits(BEEP_GPIO_PORT, BEEP_GPIO_PIN);
//	}
//	else
//	{
//		if(on)
//		{
//			if(g_beep_status == 0){TIM_Cmd(TIM2, ENABLE);g_beep_status = 1;}
//		}
//		else
//		{
//			if(g_beep_status == 1){TIM_Cmd(TIM2, DISABLE);g_beep_status = 0;}
//		}	
//	}
//}

//char eg_beep_status(void)
//{
//	if(g_user_config.hd_version == HD_VERSION_GZ)
//	{
//		return GPIO_ReadOutputDataBit(BEEP_GPIO_PORT, BEEP_GPIO_PIN) == 0;
//	}
//	else
//	{
//		return g_beep_status;
//	}
//}

char eg_beep_status(void)
{
	return GPIO_ReadOutputDataBit(BEEP_GPIO_PORT, BEEP_GPIO_PIN) == 0;
}
