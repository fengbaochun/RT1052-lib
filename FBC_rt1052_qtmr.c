#include "FBC_rt1052_qtmr.h"
/*
	API��

		void Qtmr_Init(TMR_Type *base,uint16_t ticks,int channel_1,int channel_2,uint32_t prep,uint32_t subp)
		@����
			Qtmr_Init(TMR1,1000,0,1,6,0);//Ĭ��Ϊ ͨ��3, 1000 msҲ����1����,ͨ������������ͨ���� ����λ����Ϊ���ȼ�����
		
		
		ע��
			һ��4����ʱ��
			ÿ����ʱ��4��ͨ��

			���� channel_1��ҪС��channel_2
			
			�ɼ��������32/48/64λ��������
		
*/

volatile int TMR1_num0=0;
volatile int TMR1_num1=0;
volatile int TMR1_num2=0;
volatile int TMR1_num3=0;

//�������ƣ��жϺ���
//��    ����
void TMR1_IRQHandler(void)
{    
    if((QTMR_GetStatus(TMR1,kQTMR_Channel_0)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR1,kQTMR_Channel_0,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR1_num0++;//�ü�����ʽ��������ԣ�Ӧ�ú������߱�־����д������
    }
    if((QTMR_GetStatus(TMR1,kQTMR_Channel_1)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR1,kQTMR_Channel_1,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR1_num1++;
    }
	
	if((QTMR_GetStatus(TMR1,kQTMR_Channel_2)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR1,kQTMR_Channel_2,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR1_num2++;
    }	

    if((QTMR_GetStatus(TMR1,kQTMR_Channel_3)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR1,kQTMR_Channel_3,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR1_num3++;
    }

    /* ���ΪARM�����838869��Ӱ��Cortex-M4��Cortex-M4F�洢�����ص�
		�쳣���ز������ܻᵼ�´�����ж� */
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
        QTMR_ClearStatusFlags(TMR2,kQTMR_Channel_0,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR2_num0++;
    }
    if((QTMR_GetStatus(TMR2,kQTMR_Channel_1)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR2,kQTMR_Channel_1,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR2_num1++;
    }
	
	if((QTMR_GetStatus(TMR2,kQTMR_Channel_2)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR2,kQTMR_Channel_2,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR2_num2++;
    }	

    if((QTMR_GetStatus(TMR2,kQTMR_Channel_3)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR2,kQTMR_Channel_3,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR2_num3++;
    }

    /* ���ΪARM�����838869��Ӱ��Cortex-M4��Cortex-M4F�洢�����ص�
		�쳣���ز������ܻᵼ�´�����ж� */
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
        QTMR_ClearStatusFlags(TMR3,kQTMR_Channel_0,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR3_num0++;
    }
    if((QTMR_GetStatus(TMR3,kQTMR_Channel_1)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR3,kQTMR_Channel_1,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR3_num1++;
    }
    if((QTMR_GetStatus(TMR3,kQTMR_Channel_2)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR3,kQTMR_Channel_2,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR3_num2++;
    }
    if((QTMR_GetStatus(TMR3,kQTMR_Channel_3)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR3,kQTMR_Channel_3,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR3_num3++;
    }
	
	
    /* ���ΪARM�����838869��Ӱ��Cortex-M4��Cortex-M4F�洢�����ص�
		�쳣���ز������ܻᵼ�´�����ж� */
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
        QTMR_ClearStatusFlags(TMR4,kQTMR_Channel_0,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR4_num0++;
    }
    if((QTMR_GetStatus(TMR4,kQTMR_Channel_1)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR4,kQTMR_Channel_1,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR4_num1++;
    }
    if((QTMR_GetStatus(TMR4,kQTMR_Channel_2)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR4,kQTMR_Channel_2,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR4_num2++;
    }
    if((QTMR_GetStatus(TMR4,kQTMR_Channel_3)&kQTMR_CompareFlag)==kQTMR_CompareFlag)
    {
        QTMR_ClearStatusFlags(TMR4,kQTMR_Channel_3,kQTMR_CompareFlag); //����жϱ�־λ 
		TMR4_num3++;
    }
    /* ���ΪARM�����838869��Ӱ��Cortex-M4��Cortex-M4F�洢�����ص�
		�쳣���ز������ܻᵼ�´�����ж� */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}




//�������ƣ��ж�ѡ��
//��    �����ж�ģ���

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


//�������ƣ�ͨ��ѡ��
//��    ����ͨ��
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



//�������ƣ�Qtmr��ʱ����ʼ��
//��    ����ͨ���ţ� ��ʱʱ�� ��λ ms	�� ����ͨ���� ��ռ���ȼ�,�����ȼ�
//ע����ʼ����������ͨ��
	//������ʱ��ͨ����ʼ��
//
//void Qtmr_Init(TMR_Type *base,)
void Qtmr_Init(TMR_Type *base,uint16_t ticks,int channel_1,int channel_2,uint32_t prep,uint32_t subp)
{
    qtmr_config_t qtmrConfig;

    QTMR_GetDefaultConfig(&qtmrConfig);//
    /* ʹ��IP����ʱ��div 128 */
    qtmrConfig.primarySource = kQTMR_ClockDivide_128;//

    QTMR_Init(base, Qtmr_Channel_Chose(channel_2), &qtmrConfig);

    /* ����ʱ����������Ϊ50���� Set timer period to be 50 millisecond */
    QTMR_SetTimerPeriod(base, Qtmr_Channel_Chose(channel_2), MSEC_TO_COUNT(50U, (QTMR_SOURCE_CLOCK / 128)));

    /* ��NVIC���� */
    EnableIRQ(Qtmr_IRQN_Chose(base));

	/* �����жϵ����ȼ� */
	uint32_t prioritygroup = 0x00;	  
	prioritygroup=NVIC_GetPriorityGrouping();
	NVIC_SetPriority(Qtmr_IRQN_Chose(base),NVIC_EncodePriority(prioritygroup,prep,subp));      
    /* ���ö�ʱ���Ƚ��ж� */
    QTMR_EnableInterrupts(base, Qtmr_Channel_Chose(channel_2), kQTMR_CompareInterruptEnable);

    /* �����ڶ���ͨ���Լ�����Դʱ�ӵ������� */
    QTMR_StartTimer(base, Qtmr_Channel_Chose(channel_2), kQTMR_PriSrcRiseEdge);
    QTMR_Deinit(base, Qtmr_Channel_Chose(channel_2));

    /* ������һ��ʹ��IP����ʱ��div 128��ͨ�� */
    qtmrConfig.primarySource = kQTMR_ClockDivide_128;
    QTMR_Init(base, Qtmr_Channel_Chose(channel_1), &qtmrConfig);

    /* ���������ӵ�һ��ͨ���͵ڶ���ͨ��ʱ�������ڶ���ͨ����ʹ�õ�һ��ͨ������� */
    qtmrConfig.primarySource = kQTMR_ClockCounter0Output;
    QTMR_Init(base, Qtmr_Channel_Chose(channel_2), &qtmrConfig);
   
    /* ����һ��ͨ����������Ϊ1���� */
   QTMR_SetTimerPeriod(base, Qtmr_Channel_Chose(channel_1), MSEC_TO_COUNT(1U, (QTMR_SOURCE_CLOCK / 128)));

    /* ���õڶ���ͨ��������ÿ��������һ�Σ����Ƚ��¼�����Ϊ ticks ms */
    QTMR_SetTimerPeriod(base, Qtmr_Channel_Chose(channel_2), ticks);

    /* ���õڶ���ͨ���Ƚ��ж� */
    QTMR_EnableInterrupts(base, Qtmr_Channel_Chose(channel_2), kQTMR_CompareInterruptEnable);

    /* �Լ���ģʽ�����ڶ���ͨ����ͨ����ҪԴѡ�����ӵ���ǰ���õĵ�һ��ͨ�� */
    QTMR_StartTimer(base, Qtmr_Channel_Chose(channel_2), kQTMR_CascadeCount);

    /* ������һ��ͨ���Լ�����Դclockv�������� */
    QTMR_StartTimer(base, Qtmr_Channel_Chose(channel_1), kQTMR_PriSrcRiseEdge);

}
//log:
//version:1.0
//data:2019.1.10
//by:��С��

