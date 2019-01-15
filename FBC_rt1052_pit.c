#include "FBC_rt1052_pit.h"


/*
	API：

		void Pit_Init(int channel,uint64_t time_us,int prep,int subp)
		@例：
			Pit_Init(0,1000000U,6,0);//默认为 通道0 并且定时1000000 us,也就是1秒钟 后两位参数为优先级设置
		
		
		注：
			通道一共4个，中断已经全部给出，只需要初始化相关的宏定义和初始化函数			
		
*/

/* 宏定义中断开关 */
#define PIT_IRQ_CHNL_0	1
#define PIT_IRQ_CHNL_1	0
#define PIT_IRQ_CHNL_2	0
#define PIT_IRQ_CHNL_3	0

volatile int a=0;
volatile int b=0;
volatile int c=0;
volatile int d=0;

//函数名称：PIT中断函数
//参    数：
void PIT_IRQHandler(void)
{  
	
#if PIT_IRQ_CHNL_0
	if((PIT_GetStatusFlags(PIT,kPIT_Chnl_0)&kPIT_TimerFlag)==kPIT_TimerFlag)
	{
		/* 清除中断标志位 */
		PIT_ClearStatusFlags(PIT,kPIT_Chnl_0,kPIT_TimerFlag);
		a++;//变量用于测试
	}
#endif
#if PIT_IRQ_CHNL_1
	if((PIT_GetStatusFlags(PIT,kPIT_Chnl_1)&kPIT_TimerFlag)==kPIT_TimerFlag)
	{
		/* 清除中断标志位 */
		PIT_ClearStatusFlags(PIT,kPIT_Chnl_1,kPIT_TimerFlag);
		b++;
	}
#endif
#if PIT_IRQ_CHNL_2
	if((PIT_GetStatusFlags(PIT,kPIT_Chnl_2)&kPIT_TimerFlag)==kPIT_TimerFlag)
	{
		/* 清除中断标志位 */
		PIT_ClearStatusFlags(PIT,kPIT_Chnl_2,kPIT_TimerFlag);
		c++;
	}
#endif
#if PIT_IRQ_CHNL_3
	if((PIT_GetStatusFlags(PIT,kPIT_Chnl_3)&kPIT_TimerFlag)==kPIT_TimerFlag)
	{
		/* 清除中断标志位 */
		PIT_ClearStatusFlags(PIT,kPIT_Chnl_3,kPIT_TimerFlag);
		d++;
	}
#endif
			
}



//
//函数名称：通道选择
//参    数：通道
pit_chnl_t Channel_Chose(int channel_num)
{
	pit_chnl_t 	temp_channel;
	
	switch(channel_num)
	{
		case 0:temp_channel=kPIT_Chnl_0;break;
		case 1:temp_channel=kPIT_Chnl_1;break;
		case 2:temp_channel=kPIT_Chnl_2;break;
		case 3:temp_channel=kPIT_Chnl_3;break;	
	}
	
	return temp_channel;
}

//函数名称：串口初始化
//参    数：通道，定时时间,抢占优先级,子优先级
void Pit_Init(int channel,uint64_t time_us,int prep,int subp)
{
	/* 根据编号获取通道号 */
	pit_chnl_t 	temp_channel=Channel_Chose(channel);
	/* 初始化PIT的结构 */
	pit_config_t pitConfig;
	/* 启用GPIO1的时钟 */
	CLOCK_EnableClock(kCLOCK_Gpio1);
	/* 将PERCLK_CLK源设置为OSC_CLK*/
	CLOCK_SetMux(kCLOCK_PerclkMux, 1U);
	/* 将PERCLK_CLK分频器设置为1 */
	CLOCK_SetDiv(kCLOCK_PerclkDiv, 0U);
	/*使用默认设置填充PIT配置结构。*/
	PIT_GetDefaultConfig(&pitConfig);
	/* 初始化PIT模块 */
	PIT_Init(PIT, &pitConfig);
	/* 设置通道temp_channel的定时器周期*/
	PIT_SetTimerPeriod(PIT, temp_channel, USEC_TO_COUNT(time_us, CLOCK_GetFreq(kCLOCK_OscClk)));
	/* 启用通道temp_channel的定时器中断 */
	PIT_EnableInterrupts(PIT, temp_channel, kPIT_TimerInterruptEnable);
	/* 在NVIC启用 */
	EnableIRQ(PIT_IRQn);
	
	/* 设置中断的优先级 */
	uint32_t prioritygroup = 0x00;	  
	prioritygroup=NVIC_GetPriorityGrouping();
	NVIC_SetPriority(PIT_IRQn,NVIC_EncodePriority(prioritygroup,prep,subp));

	/*启动通道temp_channel */
	PIT_StartTimer(PIT, temp_channel);
	

}

//log:
//version:1.0
//data:2019.1.8
//by:疯小疯

