#include "FBC_rt1052_gpt.h"

/*
	API��

		void Gpt_Init(GPT_Type *GPT_x,int channel,uint32_t gpt_inter_time,uint32_t mask,uint32_t prep,uint32_t subp)
		@����
			Gpt_Init(GPT_Type *GPT_x,int channel,uint32_t gpt_inter_time,uint32_t mask,uint32_t prep,uint32_t subp);
			Ĭ��Ϊ ͨ��1 ���Ҷ�ʱ1000000 us,Ҳ����1����  ʹ���ж�ģʽ ����λ����Ϊ���ȼ�����
			
		
		�ж�ģʽ
		
		
		//kGPT_OutputCompare1InterruptEnable  ����Ƚ�Channel1�ж�ʹ��
		//kGPT_OutputCompare2InterruptEnable  ����Ƚ�Channel2�ж�ʹ��
		//kGPT_OutputCompare3InterruptEnable  ����Ƚ�Channel3�ж�ʹ��
		//kGPT_InputCapture1InterruptEnable   ���벶��ͨ��1�ж�ʹ��	
		//kGPT_InputCapture2InterruptEnable   ���벶��ͨ��2�ж�ʹ��	
		//kGPT_RollOverFlagInterruptEnable 	  ��������ת�ж�����		
		
*/


volatile int GPT1_test_num=0;
volatile int GPT2_test_num=0;
 
//�������ƣ�Gpt�жϺ���
//��    ����
 void GPT1_IRQHandler(void)
{
    /* ����жϱ�־.*/
	if(GPT_GetStatusFlags(GPT1,kGPT_OutputCompare1Flag))
	{
		GPT_ClearStatusFlags(GPT1, kGPT_OutputCompare1Flag);
		GPT1_test_num++;
	}

    /* ���ΪARM�����838869��Ӱ��Cortex-M4��Cortex-M4F��Cortex-M7��
	Cortex-M7F�洢�����ص��쳣���ز������ܻᵼ�´�����ж� */
#if defined __CORTEX_M && (__CORTEX_M == 4U || __CORTEX_M == 7U)
    __DSB();
#endif
}


//�������ƣ�Gpt�жϺ���
//��    ����

void GPT2_IRQHandler(void)
{
    /* ����жϱ�־.*/
	
	if(GPT_GetStatusFlags(GPT2,kGPT_OutputCompare1Flag))
	{
		GPT_ClearStatusFlags(GPT2, kGPT_OutputCompare1Flag);
		GPT2_test_num++;
	}
	
    /* ���ΪARM�����838869��Ӱ��Cortex-M4��Cortex-M4F��Cortex-M7��
	Cortex-M7F�洢�����ص��쳣���ز������ܻᵼ�´�����ж� */
#if defined __CORTEX_M && (__CORTEX_M == 4U || __CORTEX_M == 7U)
    __DSB();
#endif
}

//�������ƣ��ж�ѡ��
//��    �����ж�ģ���

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


//�������ƣ�ͨ��ѡ��
//��    ����ͨ��
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


//�������ƣ�Gpt��ʼ��
//��    ����Gptģ��	���  ͨ��	�ж϶�ʱʱ��	�ж�ģʽʹ�� ��ռ���ȼ�,�����ȼ�
void Gpt_Init(GPT_Type *GPT_x,int channel,uint32_t gpt_inter_time,uint32_t mask,uint32_t prep,uint32_t subp)
{
	uint32_t gptFreq;
	uint32_t  inter_timer;//��λ�ж�ʱ��
	gpt_config_t gptConfig;
		
	 /*GPT��ʱ������*/
    CLOCK_SetMux(kCLOCK_PerclkMux, 0U);
    CLOCK_SetDiv(kCLOCK_PerclkDiv, 0U);

    GPT_GetDefaultConfig(&gptConfig);
    /* ��ʼ��GPTģ�� */
    GPT_Init(GPT_x, &gptConfig);
    /* ��GPTģ���ڽ�GPTʱ��ԴƵ�ʳ���3 */
    GPT_SetClockDivider(GPT_x, 3);
    /* ��ȡGPTʱ��Ƶ�� */
    gptFreq = CLOCK_GetFreq(kCLOCK_IpgClk) ;
    /* �ڲ�ģ���GPTƵ�ʳ���3 */
    gptFreq /= 3;
	/* 1us�ļ�ʱʱ�� */
	inter_timer=gptFreq/1000000;
    /* ����GPT����Ƚ���ֵ */
    GPT_SetOutputCompareValue(GPT_x, GPT_Channel_Chose(channel), inter_timer*gpt_inter_time);
    /* ����GPT���Compare1�ж� */
    GPT_EnableInterrupts(GPT_x, mask);//�ж�ģʽ��ѡ��
    /* ���ж�ʱ���� */
    EnableIRQ(GPT_IRQN_Chose(GPT_x));

	/* �����жϵ����ȼ� */
	uint32_t prioritygroup = 0x00;	  
	prioritygroup=NVIC_GetPriorityGrouping();
	NVIC_SetPriority(PIT_IRQn,NVIC_EncodePriority(prioritygroup,prep,subp));    
    /* ������ʱ�� */
    GPT_StartTimer(GPT_x);

}



//log:
//version:1.0
//data:2019.1.9
//by:��С��



