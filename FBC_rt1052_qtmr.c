#include "FBC_rt1052_qtmr.h"
/*
	API：

		void Qtmr_Init(TMR_Type *base,uint16_t ticks,int channel_1,int channel_2,uint32_t prep,uint32_t subp)
		@例：
			Qtmr_Init(TMR1,1000,0,1,6,0);//默认为 通道3, 1000 ms也就是1秒钟,通道联级的两个通道， 后两位参数为优先级设置
		
		
		注：
			一共4个定时器
			每个定时器4个通道

			其中 channel_1需要小于channel_2
			
			可级联，组成32/48/64位计数器；
		
*/

volatile int TMR1_num0=0;
volatile int TMR1_num1=0;
volatile int TMR1_num2=0;
volatile int TMR1_num3=0;

//函数名称：中断函数
//参    数：
void TMR1_IRQHandler(void)
{    
    if((QTMR_GetStatus(TMR1,kQTMR_Channel_0)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR1,kQTMR_Channel_0,kQTMR_CompareFlag); //清除中断标志位 
		TMR1_num0++;//用计数方式在这里测试，应用函数或者标志可以写在这里
    }
    if((QTMR_GetStatus(TMR1,kQTMR_Channel_1)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR1,kQTMR_Channel_1,kQTMR_CompareFlag); //清除中断标志位 
		TMR1_num1++;
    }
	
	if((QTMR_GetStatus(TMR1,kQTMR_Channel_2)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR1,kQTMR_Channel_2,kQTMR_CompareFlag); //清除中断标志位 
		TMR1_num2++;
    }	

    if((QTMR_GetStatus(TMR1,kQTMR_Channel_3)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR1,kQTMR_Channel_3,kQTMR_CompareFlag); //清除中断标志位 
		TMR1_num3++;
    }

    /* 添加为ARM勘误表838869，影响Cortex-M4，Cortex-M4F存储立即重叠
		异常返回操作可能会导致错误的中断 */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

volatile int TMR2_num0=0;
volatile int TMR2_num1=0;
volatile int TMR2_num2=0;
volatile int TMR2_num3=0;

void TMR2_IRQHandler(void)
{    
    if((QTMR_GetStatus(TMR2,kQTMR_Channel_0)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR2,kQTMR_Channel_0,kQTMR_CompareFlag); //清除中断标志位 
		TMR2_num0++;
    }
    if((QTMR_GetStatus(TMR2,kQTMR_Channel_1)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR2,kQTMR_Channel_1,kQTMR_CompareFlag); //清除中断标志位 
		TMR2_num1++;
    }
	
	if((QTMR_GetStatus(TMR2,kQTMR_Channel_2)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR2,kQTMR_Channel_2,kQTMR_CompareFlag); //清除中断标志位 
		TMR2_num2++;
    }	

    if((QTMR_GetStatus(TMR2,kQTMR_Channel_3)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR2,kQTMR_Channel_3,kQTMR_CompareFlag); //清除中断标志位 
		TMR2_num3++;
    }

    /* 添加为ARM勘误表838869，影响Cortex-M4，Cortex-M4F存储立即重叠
		异常返回操作可能会导致错误的中断 */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}



volatile int TMR3_num0=0;
volatile int TMR3_num1=0;
volatile int TMR3_num2=0;
volatile int TMR3_num3=0;

void TMR3_IRQHandler(void)
{  
	
    if((QTMR_GetStatus(TMR3,kQTMR_Channel_0)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR3,kQTMR_Channel_0,kQTMR_CompareFlag); //清除中断标志位 
		TMR3_num0++;
    }
    if((QTMR_GetStatus(TMR3,kQTMR_Channel_1)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR3,kQTMR_Channel_1,kQTMR_CompareFlag); //清除中断标志位 
		TMR3_num1++;
    }
    if((QTMR_GetStatus(TMR3,kQTMR_Channel_2)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR3,kQTMR_Channel_2,kQTMR_CompareFlag); //清除中断标志位 
		TMR3_num2++;
    }
    if((QTMR_GetStatus(TMR3,kQTMR_Channel_3)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR3,kQTMR_Channel_3,kQTMR_CompareFlag); //清除中断标志位 
		TMR3_num3++;
    }
	
	
    /* 添加为ARM勘误表838869，影响Cortex-M4，Cortex-M4F存储立即重叠
		异常返回操作可能会导致错误的中断 */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}



volatile int TMR4_num0=0;
volatile int TMR4_num1=0;
volatile int TMR4_num2=0;
volatile int TMR4_num3=0;

void TMR4_IRQHandler(void)
{  
	
    if((QTMR_GetStatus(TMR4,kQTMR_Channel_0)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR4,kQTMR_Channel_0,kQTMR_CompareFlag); //清除中断标志位 
		TMR4_num0++;
    }
    if((QTMR_GetStatus(TMR4,kQTMR_Channel_1)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR4,kQTMR_Channel_1,kQTMR_CompareFlag); //清除中断标志位 
		TMR4_num1++;
    }
    if((QTMR_GetStatus(TMR4,kQTMR_Channel_2)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR4,kQTMR_Channel_2,kQTMR_CompareFlag); //清除中断标志位 
		TMR4_num2++;
    }
    if((QTMR_GetStatus(TMR4,kQTMR_Channel_3)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR4,kQTMR_Channel_3,kQTMR_CompareFlag); //清除中断标志位 
		TMR4_num3++;
    }
    /* 添加为ARM勘误表838869，影响Cortex-M4，Cortex-M4F存储立即重叠
		异常返回操作可能会导致错误的中断 */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}




//函数名称：中断选择
//参    数：中断模块号

IRQn_Type  Qtmr_IRQN_Chose(TMR_Type *base)
{
	IRQn_Type temp_IRQn_Type;
	
	if(base==TMR1)
	{
		temp_IRQn_Type=TMR1_IRQn;
	}
	else if(base==TMR2)
	{
		temp_IRQn_Type=TMR2_IRQn;
	}
	else if(base==TMR3)
	{
		temp_IRQn_Type=TMR3_IRQn;
	}
	else if(base==TMR4)
	{
		temp_IRQn_Type=TMR4_IRQn;
	}
	
	return temp_IRQn_Type;
}


//函数名称：通道选择
//参    数：通道
qtmr_channel_selection_t Qtmr_Channel_Chose(int channel_num)
{
	qtmr_channel_selection_t temp_channel;
	switch(channel_num)
	{
		case 0:temp_channel=kQTMR_Channel_0;break;
		case 1:temp_channel=kQTMR_Channel_1;break;
		case 2:temp_channel=kQTMR_Channel_2;break;
		case 3:temp_channel=kQTMR_Channel_3;break;
	}
	return temp_channel;
}



//函数名称：Qtmr定时器初始化
//参    数：通道号， 定时时间 单位 ms	， 联级通道， 抢占优先级,子优先级
//注：初始化采用两个通道
	//联级定时器通道初始化
//
//void Qtmr_Init(TMR_Type *base,)
void Qtmr_Init(TMR_Type *base,uint16_t ticks,int channel_1,int channel_2,uint32_t prep,uint32_t subp)
{
    qtmr_config_t qtmrConfig;

    QTMR_GetDefaultConfig(&qtmrConfig);//
    /* 使用IP总线时钟div 128 */
    qtmrConfig.primarySource = kQTMR_ClockDivide_128;//

    QTMR_Init(base, Qtmr_Channel_Chose(channel_2), &qtmrConfig);

    /* 将定时器周期设置为50毫秒 Set timer period to be 50 millisecond */
    QTMR_SetTimerPeriod(base, Qtmr_Channel_Chose(channel_2), MSEC_TO_COUNT(50U, (QTMR_SOURCE_CLOCK / 128)));

    /* 在NVIC启用 */
    EnableIRQ(Qtmr_IRQN_Chose(base));

	/* 设置中断的优先级 */
	uint32_t prioritygroup = 0x00;	  
	prioritygroup=NVIC_GetPriorityGrouping();
	NVIC_SetPriority(Qtmr_IRQN_Chose(base),NVIC_EncodePriority(prioritygroup,prep,subp));      
    /* 启用定时器比较中断 */
    QTMR_EnableInterrupts(base, Qtmr_Channel_Chose(channel_2), kQTMR_CompareInterruptEnable);

    /* 启动第二个通道以计入主源时钟的上升沿 */
    QTMR_StartTimer(base, Qtmr_Channel_Chose(channel_2), kQTMR_PriSrcRiseEdge);
    QTMR_Deinit(base, Qtmr_Channel_Chose(channel_2));

    /* 启动第一个使用IP总线时钟div 128的通道 */
    qtmrConfig.primarySource = kQTMR_ClockDivide_128;
    QTMR_Init(base, Qtmr_Channel_Chose(channel_1), &qtmrConfig);

    /* 当我们链接第一个通道和第二个通道时，启动第二个通道以使用第一个通道的输出 */
    qtmrConfig.primarySource = kQTMR_ClockCounter0Output;
    QTMR_Init(base, Qtmr_Channel_Chose(channel_2), &qtmrConfig);
   
    /* 将第一个通道周期设置为1毫秒 */
   QTMR_SetTimerPeriod(base, Qtmr_Channel_Chose(channel_1), MSEC_TO_COUNT(1U, (QTMR_SOURCE_CLOCK / 128)));

    /* 设置第二个通道计数，每毫秒增加一次，将比较事件设置为 ticks ms */
    QTMR_SetTimerPeriod(base, Qtmr_Channel_Chose(channel_2), ticks);

    /* 启用第二个通道比较中断 */
    QTMR_EnableInterrupts(base, Qtmr_Channel_Chose(channel_2), kQTMR_CompareInterruptEnable);

    /* 以级联模式启动第二个通道，通过主要源选择链接到先前设置的第一个通道 */
    QTMR_StartTimer(base, Qtmr_Channel_Chose(channel_2), kQTMR_CascadeCount);

    /* 启动第一个通道以计入主源clockv的上升沿 */
    QTMR_StartTimer(base, Qtmr_Channel_Chose(channel_1), kQTMR_PriSrcRiseEdge);

}
//log:
//version:1.0
//data:2019.1.10
//by:疯小疯

