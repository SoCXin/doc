#include "adc.h"

u32 g_adc1_value=0;
void dma_config()
{
    DMA_InitTypeDef t_dma;
    //开启DMA1时钟
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
    //DMA设备基地址为((u32)0x40012400+0x4c)，也可以写作(u32)(&(ADC1->DR))
    t_dma.DMA_PeripheralBaseAddr=(u32)(&(ADC1->DR));
    //DMA内存基地址为&g_value
    t_dma.DMA_MemoryBaseAddr=(u32)&g_adc1_value;
    //DMA传输方向为设备到内存
    t_dma.DMA_DIR=DMA_DIR_PeripheralSRC;
    //DMA缓冲区大小为1
    t_dma.DMA_BufferSize=1;
    //DMA设备地址不递增，内存地址不递增
    t_dma.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
    t_dma.DMA_MemoryInc=DMA_MemoryInc_Disable;
    //DMA设备数据单位为半字、内存数据单位为半字，即每次传输16位
    t_dma.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;
    t_dma.DMA_MemoryDataSize=DMA_MemoryDataSize_HalfWord;
    //DMA模式为循环，即传完一轮就进行下一轮
    t_dma.DMA_Mode=DMA_Mode_Circular;
    //DMA优先级为中
    t_dma.DMA_Priority=DMA_Priority_Medium;
    //DMA禁止内存到内存
    t_dma.DMA_M2M=DMA_M2M_Disable;
    DMA_Init(DMA1_Channel1,&t_dma);
    //启用DMA1的通道1
    DMA_Cmd(DMA1_Channel1,ENABLE);
    //启动DMA搬运ADC数值
    ADC_DMACmd(ADC1,ENABLE);
}

void adc_init_gpio()
{
	GPIO_InitTypeDef GPIO_InitStructure;                                                  
	//结构体_引脚基础-声明   
	RCC_APB2PeriphClockCmd(ADC_GPIO_RCC | RCC_APB2Periph_ADC1, ENABLE);           
	//时钟开启_GPIOA,ADC1
	GPIO_InitStructure.GPIO_Pin = ADC_GPIO_PIN;                                             
	//结构体_引脚-PA1
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                                     
	//结构体_引脚-引脚频率_50Mhz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;                                         
	//结构体_引脚-引脚模式_模拟输入
	GPIO_Init(ADC_GPIO_PORT, &GPIO_InitStructure);                                                
	//结构体_引脚_结束配置
}

void adc_init(void)
{
	//初始化ADC
	ADC_InitTypeDef t_adc;
	//开启ADC1的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	//ADC使用独立模式
	t_adc.ADC_Mode=ADC_Mode_Independent;
	//禁用扫描模式
	t_adc.ADC_ScanConvMode=DISABLE;
	//启用连续转换，即转换完一次后继续转换
	t_adc.ADC_ContinuousConvMode=ENABLE;
	//不使用外部触发
	t_adc.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
	//数据右对齐
	t_adc.ADC_DataAlign=ADC_DataAlign_Right;
	//要转换的通道数为1
	t_adc.ADC_NbrOfChannel=1;
	//初始化ADC1
	ADC_Init(ADC1,&t_adc);
	//配置ADC的时钟为PCLK2的8分频
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	//设置ADC1的通道0的转换周期为71.5个采样周期
	ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_71Cycles5);
	//使能ADC1
	ADC_Cmd(ADC1,ENABLE);
	//使能软件触发
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);   
	
	//初始化GPIO
	adc_init_gpio();
	
	//DMA读取
	dma_config();
}


uint16_t adc_read_data()
{                                                                                                                                                                                                                                                                                                                                                 
    u16 t_value;
    //等待ADC1转换完成
    while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC)==RESET);
    //获取ADC1的值
    t_value=ADC_GetConversionValue(ADC1);
    //清除转换完成标志
    ADC_ClearFlag(ADC1,ADC_FLAG_EOC);
    //t_value中就是ADC的值  
		return t_value;
}
