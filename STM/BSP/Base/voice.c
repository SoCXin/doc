
#include "voice.h"
#include "SYSTICK.h"

//void Voice_GPIO_Config(void)
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
//	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE);

//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);

//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_14 | GPIO_Pin_15;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
//	GPIO_Init(GPIOC, &GPIO_InitStructure);
//}

//void  Delay_Me (uint32_t nCount)
//{
//  for(; nCount != 0; nCount--);
//}

void Voice_Show(int in_addr)
{
//	int i=0;
//	int addr = in_addr;
//	
//	//¹Ø±Õ×ÜÖÐ¶Ï
//	__disable_irq();
//	
//	GPIO_WriteBit(GPIOC, GPIO_Pin_15, Bit_RESET);
//	Delay_Me(0xafff);
//	for(i=0;i<8;i++)
//	{
//		if(addr&0x01)   
//			GPIO_WriteBit(GPIOC, GPIO_Pin_14, Bit_SET);
//		else
//			GPIO_WriteBit(GPIOC, GPIO_Pin_14, Bit_RESET);
//		
//		GPIO_WriteBit(GPIOC, GPIO_Pin_15, Bit_RESET);
//		Delay_Me(0xaff);
//		GPIO_WriteBit(GPIOC, GPIO_Pin_15, Bit_SET);
//		Delay_Me(0xaff);
//		addr >>= 1;	
//	}
//	GPIO_WriteBit(GPIOC, GPIO_Pin_14, Bit_SET);
//	
//	Delay_Me(0xffff);
//	__enable_irq();
}
