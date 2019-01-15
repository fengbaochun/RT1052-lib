#include "FBC_rt1052_gpt.h"

/*
	API：

		void Gpt_Init(GPT_Type *GPT_x,int channel,uint32_t gpt_inter_time,uint32_t mask,uint32_t prep,uint32_t subp)
		@例：
			Gpt_Init(GPT_Type *GPT_x,int channel,uint32_t gpt_inter_time,uint32_t mask,uint32_t prep,uint32_t subp);
			默认为 通道1 并且定时1000000 us,也就是1秒钟  使能中断模式 后两位参数为优先级设置
			
		
		中断模式
		
		
		//kGPT_OutputCompare1InterruptEnable  输出比较Channel1中断使能
		//kGPT_OutputCompare2InterruptEnable  输出比较Channel2中断使能
		//kGPT_OutputCompare3InterruptEnable  输出比较Channel3中断使能
		//kGPT_InputCapture1InterruptEnable   输入捕获通道1中断使能	
		//kGPT_InputCapture2InterruptEnable   输入捕获通道2中断使能	
		//kGPT_RollOverFlagInterruptEnable 	  计数器翻转中断启用		
		
*/


volatile int GPT1_test_num=0;
volatile int GPT2_test_num=0;
 
//函数名称：Gpt中断函数
//参    数：
 void GPT1_IRQHandler(void)
{
    /* 清除中断标志.*/
	if(GPT_GetStatusFlags(GPT1,kGPT_OutputCompare1Flag))
	{
		GPT_ClearStatusFlags(GPT1, kGPT_OutputCompare1Flag);
		GPT1_test_num++;
	}

    /* 添加为ARM勘误表838869，影响Cortex-M4，Cortex-M4F，Cortex-M7，
	Cortex-M7F存储立即重叠异常返回操作可能会导致错误的中断 */
#if defined __CORTEX_M && (__CORTEX_M == 4U || __CORTEX_M == 7U)
    __DSB();
#endif
}


//函数名称：Gpt中断函数
//参    数：

void GPT2_IRQHandler(void)
{
    /* 清除中断标志.*/
	
	if(GPT_GetStatusFlags(GPT2,kGPT_OutputCompare1Flag))
	{
		GPT_ClearStatusFlags(GPT2, kGPT_OutputCompare1Flag);
		GPT2_test_num++;
	}
	
    /* 添加为ARM勘误表838869，影响Cortex-M4，Cortex-M4F，Cortex-M7，
	Cortex-M7F存储立即重叠异常返回操作可能会导致错误的中断 */
#if defined __CORTEX_M && (__CORTEX_M == 4U || __CORTEX_M == 7U)
    __DSB();
#endif
}

//函数名称：中断选择
//参    数：中断模块号

IRQn_Type GPT_IRQN_Chose(GPT_Type *GPT_x)
{
	IRQn_Type temp_IRQn_Type;
	
	if(GPT_x==GPT1)
	{
		temp_IRQn_Type=GPT1_IRQn;
	}
	else if(GPT_x==GPT2)
	{
		temp_IRQn_Type=GPT2_IRQn;
	}
	
	return temp_IRQn_Type;
}


//函数名称：通道选择
//参    数：通道
gpt_output_compare_channel_t GPT_Channel_Chose(int channel_num)
{
	gpt_output_compare_channel_t temp_channel;
	switch(channel_num)
	{
		case 1:temp_channel=kGPT_OutputCompare_Channel1;break;
		case 2:temp_channel=kGPT_OutputCompare_Channel2;break;
		case 3:temp_channel=kGPT_OutputCompare_Channel3;break;
	}
	return temp_channel;
}


//函数名称：Gpt初始化
//参    数：Gpt模块	编号  通道	中断定时时间	中断模式使能 抢占优先级,子优先级
void Gpt_Init(GPT_Type *GPT_x,int channel,uint32_t gpt_inter_time,uint32_t mask,uint32_t prep,uint32_t subp)
{
	uint32_t gptFreq;
	uint32_t  inter_timer;//单位中断时间
	gpt_config_t gptConfig;
		
	 /*GPT的时钟设置*/
    CLOCK_SetMux(kCLOCK_PerclkMux, 0U);
    CLOCK_SetDiv(kCLOCK_PerclkDiv, 0U);

    GPT_GetDefaultConfig(&gptConfig);
    /* 初始化GPT模块 */
    GPT_Init(GPT_x, &gptConfig);
    /* 在GPT模块内将GPT时钟源频率除以3 */
    GPT_SetClockDivider(GPT_x, 3);
    /* 获取GPT时钟频率 */
    gptFreq = CLOCK_GetFreq(kCLOCK_IpgClk) ;
    /* 内部模块的GPT频率除以3 */
    gptFreq /= 3;
	/* 1us的计时时间 */
	inter_timer=gptFreq/1000000;
    /* 设置GPT输出比较数值 */
    GPT_SetOutputCompareValue(GPT_x, GPT_Channel_Chose(channel), inter_timer*gpt_inter_time);
    /* 启用GPT输出Compare1中断 */
    GPT_EnableInterrupts(GPT_x, mask);//中断模式可选择
    /* 在中断时启用 */
    EnableIRQ(GPT_IRQN_Chose(GPT_x));

	/* 设置中断的优先级 */
	uint32_t prioritygroup = 0x00;	  
	prioritygroup=NVIC_GetPriorityGrouping();
	NVIC_SetPriority(PIT_IRQn,NVIC_EncodePriority(prioritygroup,prep,subp));    
    /* 启动计时器 */
    GPT_StartTimer(GPT_x);

}



//log:
//version:1.0
//data:2019.1.9
//by:疯小疯



