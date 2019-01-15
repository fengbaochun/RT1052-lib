#include "FBC_rt1052_pit.h"


/*
	API��

		void Pit_Init(int channel,uint64_t time_us,int prep,int subp)
		@����
			Pit_Init(0,1000000U,6,0);//Ĭ��Ϊ ͨ��0 ���Ҷ�ʱ1000000 us,Ҳ����1���� ����λ����Ϊ���ȼ�����
		
		
		ע��
			ͨ��һ��4�����ж��Ѿ�ȫ��������ֻ��Ҫ��ʼ����صĺ궨��ͳ�ʼ������			
		
*/

/* �궨���жϿ��� */
#define PIT_IRQ_CHNL_0	1
#define PIT_IRQ_CHNL_1	0
#define PIT_IRQ_CHNL_2	0
#define PIT_IRQ_CHNL_3	0

volatile int a=0;
volatile int b=0;
volatile int c=0;
volatile int d=0;

//�������ƣ�PIT�жϺ���
//��    ����
void PIT_IRQHandler(void)
{  
	
#if PIT_IRQ_CHNL_0
	if((PIT_GetStatusFlags(PIT,kPIT_Chnl_0)&kPIT_TimerFlag)==kPIT_TimerFlag)
	{
		/* ����жϱ�־λ */
		PIT_ClearStatusFlags(PIT,kPIT_Chnl_0,kPIT_TimerFlag);
		a++;//�������ڲ���
	}
#endif
#if PIT_IRQ_CHNL_1
	if((PIT_GetStatusFlags(PIT,kPIT_Chnl_1)&kPIT_TimerFlag)==kPIT_TimerFlag)
	{
		/* ����жϱ�־λ */
		PIT_ClearStatusFlags(PIT,kPIT_Chnl_1,kPIT_TimerFlag);
		b++;
	}
#endif
#if PIT_IRQ_CHNL_2
	if((PIT_GetStatusFlags(PIT,kPIT_Chnl_2)&kPIT_TimerFlag)==kPIT_TimerFlag)
	{
		/* ����жϱ�־λ */
		PIT_ClearStatusFlags(PIT,kPIT_Chnl_2,kPIT_TimerFlag);
		c++;
	}
#endif
#if PIT_IRQ_CHNL_3
	if((PIT_GetStatusFlags(PIT,kPIT_Chnl_3)&kPIT_TimerFlag)==kPIT_TimerFlag)
	{
		/* ����жϱ�־λ */
		PIT_ClearStatusFlags(PIT,kPIT_Chnl_3,kPIT_TimerFlag);
		d++;
	}
#endif
			
}



//
//�������ƣ�ͨ��ѡ��
//��    ����ͨ��
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

//�������ƣ����ڳ�ʼ��
//��    ����ͨ������ʱʱ��,��ռ���ȼ�,�����ȼ�
void Pit_Init(int channel,uint64_t time_us,int prep,int subp)
{
	/* ���ݱ�Ż�ȡͨ���� */
	pit_chnl_t 	temp_channel=Channel_Chose(channel);
	/* ��ʼ��PIT�Ľṹ */
	pit_config_t pitConfig;
	/* ����GPIO1��ʱ�� */
	CLOCK_EnableClock(kCLOCK_Gpio1);
	/* ��PERCLK_CLKԴ����ΪOSC_CLK*/
	CLOCK_SetMux(kCLOCK_PerclkMux, 1U);
	/* ��PERCLK_CLK��Ƶ������Ϊ1 */
	CLOCK_SetDiv(kCLOCK_PerclkDiv, 0U);
	/*ʹ��Ĭ���������PIT���ýṹ��*/
	PIT_GetDefaultConfig(&pitConfig);
	/* ��ʼ��PITģ�� */
	PIT_Init(PIT, &pitConfig);
	/* ����ͨ��temp_channel�Ķ�ʱ������*/
	PIT_SetTimerPeriod(PIT, temp_channel, USEC_TO_COUNT(time_us, CLOCK_GetFreq(kCLOCK_OscClk)));
	/* ����ͨ��temp_channel�Ķ�ʱ���ж� */
	PIT_EnableInterrupts(PIT, temp_channel, kPIT_TimerInterruptEnable);
	/* ��NVIC���� */
	EnableIRQ(PIT_IRQn);
	
	/* �����жϵ����ȼ� */
	uint32_t prioritygroup = 0x00;	  
	prioritygroup=NVIC_GetPriorityGrouping();
	NVIC_SetPriority(PIT_IRQn,NVIC_EncodePriority(prioritygroup,prep,subp));

	/*����ͨ��temp_channel */
	PIT_StartTimer(PIT, temp_channel);
	

}

//log:
//version:1.0
//data:2019.1.8
//by:��С��

