#include "fsl_iomuxc.h"
#include "fsl_lpuart.h"  
#include "pad_config.h"  
#include "FBC_rt1052_uart.h"
#include "board.h"


/*
	API��
		Lpuart_Init(LPUART_Type* LPUART_x,uint32_t Baud_Rate,int LPUART_Map,uint32_t prep,uint32_t subp)��
		@����
			Lpuart_Init(LPUART3,115200U,2,6,0);	Ĭ�϶��ǿ����жϣ�������8λ���� 1λֹͣλ ����żУ�� �ж����ȼ�����

		LPUART_WriteByte(LPUART_Type *base, uint8_t data)��
		@����	
			LPUART_WriteByte(LPUART3, data);//д�������ݣ�һ���ֽڣ�

		LPUART_ReadByte(LPUART_Type *base)��
		@���� 
			data = LPUART_ReadByte(LPUART1);//��һ���ֽ�

		LPUART_WriteBlocking(LPUART:Type *base, const uint8_t *data, size_t length);
		@��:
			uint8_t g_tipString[]=
			
			"Lpuart init ok";
	
			LPUART_WriteBlocking(LPUART_x, g_tipString, sizeof(g_tipString) / sizeof(g_tipString[0]));

		
		
		�������ŷֲ����
		
		LPUART_x	LPUART_Map			TX			RX
		____________________________________________________
		lpuart1			1			GPIO1_IO12	GPIO1_IO13
		____________________________________________________
		lpuart2	        1   	    GPIO1_IO18	GPIO1_IO19
		____________________________________________________

		lpuart3			1			GPIO2_IO08 	GPIO2_IO09
						2			GPIO4_IO13 	GPIO4_IO14
						3			GPIO1_IO22 	GPIO1_IO23
		____________________________________________________

		lpuart4	      	1			GPIO2_IO16 	GPIO2_IO17
						2			GPIO4_IO19 	GPIO4_IO20
						3			GPIO3_IO00 	GPIO3_IO01
		____________________________________________________
			
		lpuart5			1			GPIO2_IO28 	GPIO2_IO29
						2			GPIO4_IO23 	GPIO4_IO24		
		____________________________________________________
			

		lpuart6			1			GPIO1_IO2  	GPIO1_IO3
						2			GPIO4_IO25 	GPIO4_IO26
		____________________________________________________
			
		lpuart7			1			GPIO3_IO08 	GPIO3_IO09
						2			GPIO4_IO31 	GPIO3_IO18
		____________________________________________________
			
		lpuart8	        1			GPIO1_IO26 	GPIO1_IO27
						2			GPIO3_IO24 	GPIO3_IO25
						3			GPIO3_IO16 	GPIO3_IO17
		____________________________________________________
	
		
*/

void LPUART_WriteBytes(LPUART_Type* LPUART_x,uint8_t *data,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		LPUART_WriteByte(LPUART_x, *data++);
	}
}


//����1�ж�
void LPUART1_IRQHandler(void)
{
   volatile  uint8_t data;

    /* ��������ݵ���. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART1))
    {
        data = LPUART_ReadByte(LPUART1);

    }
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}


void LPUART2_IRQHandler(void)
{
    volatile uint8_t data;

    /* ��������ݵ���. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART2))
    {
        data = LPUART_ReadByte(LPUART2);

    }
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif

}



//����3�ж�
void LPUART3_IRQHandler(void)
{
    volatile uint8_t data;

    /* ��������ݵ���. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART3))
    {
        data = LPUART_ReadByte(LPUART3);
        LPUART_WriteByte(LPUART3, data);
    }
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

//����4�ж�
void LPUART4_IRQHandler(void)
{
    volatile uint8_t data;

    //* ��������ݵ���. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART4))
    {
        data = LPUART_ReadByte(LPUART4);

    }
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

//����5�ж�
void LPUART5_IRQHandler(void)
{
	volatile uint8_t data;

   /* ��������ݵ���. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART5))
    {
        data = LPUART_ReadByte(LPUART5);

    }
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

//����6�ж�
void LPUART6_IRQHandler(void)
{
    volatile uint8_t data;

    /* ��������ݵ���. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART6))
    {
        data = LPUART_ReadByte(LPUART6);
		LPUART_WriteByte(LPUART6, data);

    }
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

//����7�ж�
void LPUART7_IRQHandler(void)
{
    volatile uint8_t data;

    /* ��������ݵ���. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART7))
    {
        data = LPUART_ReadByte(LPUART7);
		LPUART_WriteByte(LPUART7, data);

    }
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

//����8�ж�
void LPUART8_IRQHandler(void)
{
    volatile uint8_t data;

    /* ��������ݵ���. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(LPUART8))
    {
        data = LPUART_ReadByte(LPUART8);
		LPUART_WriteByte(LPUART8, data);
	
    }
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}



//�������Ÿ��á�����
void Lpuart_IOMUXC_SetPin(LPUART_Type* LPUART_x,int map)
{
	if(LPUART_x ==	LPUART1)//ok
	{
		if(map==1)//ӳ����
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_LPUART1_TX,0U);//GPIO1_IO12				 
			IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_LPUART1_RX,0U);//GPIO1_IO13				 
			IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_12_LPUART1_TX,0x10B0u);		 
			IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_13_LPUART1_RX,0x10B0u);  
		}
  
	}
	else if(LPUART_x ==	LPUART2)//����ȥ�ж�
	{
		if(map==1)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_02_LPUART2_TX,0U);  //GPIO1_IO18                             
			IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_03_LPUART2_RX,0U);  //GPIO1_IO19                  
			IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_02_LPUART2_TX,0x10B0u);                          
			IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_03_LPUART2_RX,0x10B0u);		
		}

	}
	else if(LPUART_x ==	LPUART3)//ok
	{
		if(map==1)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_B0_08_LPUART3_TX,0U);//GPIO2_IO08       
			IOMUXC_SetPinMux(IOMUXC_GPIO_B0_09_LPUART3_RX,0U);//GPIO2_IO09           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_B0_08_LPUART3_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_B0_09_LPUART3_RX,0x10B0u);			
		}
		else if(map==2)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_13_LPUART3_TX,0U);//GPIO4_IO13       
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_14_LPUART3_RX,0U);//GPIO4_IO14           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_13_LPUART3_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_14_LPUART3_RX,0x10B0u);					
		}
		else if(map==3)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_06_LPUART3_TX,0U);//GPIO1_IO22       
			IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_07_LPUART3_RX,0U);//GPIO1_IO23           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_06_LPUART3_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_07_LPUART3_RX,0x10B0u);					
		}		

	}
	else if(LPUART_x ==	LPUART4)//ok
	{
		if(map==1)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_B1_00_LPUART4_TX,0U);//GPIO2_IO16           
			IOMUXC_SetPinMux(IOMUXC_GPIO_B1_01_LPUART4_RX,0U);//GPIO2_IO17           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_00_LPUART4_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_01_LPUART4_RX,0x10B0u);		
		}
		else if(map==2)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_19_LPUART4_TX,0U);//GPIO4_IO19           
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_20_LPUART4_RX,0U);//GPIO4_IO20           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_19_LPUART4_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_20_LPUART4_RX,0x10B0u);			
		}
		else if(map==3)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_00_LPUART4_TX,0U);//GPIO3_IO00           
			IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_01_LPUART4_RX,0U);//GPIO3_IO01           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_00_LPUART4_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_01_LPUART4_RX,0x10B0u);	
		}
		
	}
	else if(LPUART_x ==	LPUART5)//ok
	{
		if(map==1)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_B1_12_LPUART5_TX,0U);//GPIO2_IO28           
			IOMUXC_SetPinMux(IOMUXC_GPIO_B1_13_LPUART5_RX,0U);//GPIO2_IO29           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_12_LPUART5_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_B1_13_LPUART5_RX,0x10B0u);		
		}
		else if(map==2)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_23_LPUART5_TX,0U);//GPIO4_IO23           
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_24_LPUART5_RX,0U);//GPIO4_IO24           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_23_LPUART5_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_24_LPUART5_RX,0x10B0u);			
		}

	}
	else if(LPUART_x ==	LPUART6)//ok
	{
		if(map==1)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_02_LPUART6_TX,0U);//GPIO1_IO2           
			IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_03_LPUART6_RX,0U);//GPIO1_IO3           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_02_LPUART6_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B0_03_LPUART6_RX,0x10B0u);			
		}
		else if(map==2)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_25_LPUART6_TX,0U);//GPIO4_IO25           
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_26_LPUART6_RX,0U);//GPIO4_IO26           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_25_LPUART6_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_26_LPUART6_RX,0x10B0u);
		}

	}
	else if(LPUART_x ==	LPUART7)
	{
		if(map==1)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_08_LPUART7_TX,0U);//GPIO3_IO08           
			IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B1_09_LPUART7_RX,0U);//GPIO3_IO09           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_08_LPUART7_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B1_09_LPUART7_RX,0x10B0u);		
		}
		else if(map==2)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_31_LPUART7_TX,0U);//GPIO4_IO31           
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_32_LPUART7_RX,0U);//GPIO3_IO18           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_31_LPUART7_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_32_LPUART7_RX,0x10B0u);	
		}
	
	}
	else if(LPUART_x ==	LPUART8)
	{	
		if(map==1)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_10_LPUART8_TX,0U);//GPIO1_IO26           
			IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_11_LPUART8_RX,0U);//GPIO1_IO27           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_10_LPUART8_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_AD_B1_11_LPUART8_RX,0x10B0u);	
		}
		else if(map==2)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_38_LPUART8_TX,0U);//GPIO3_IO24           
			IOMUXC_SetPinMux(IOMUXC_GPIO_EMC_39_LPUART8_RX,0U);//GPIO3_IO25           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_38_LPUART8_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_EMC_39_LPUART8_RX,0x10B0u);
		}
		else if(map==3)
		{
			IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_04_LPUART8_TX,0U);//GPIO3_IO16           
			IOMUXC_SetPinMux(IOMUXC_GPIO_SD_B0_05_LPUART8_RX,0U);//GPIO3_IO17           
			IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_04_LPUART8_TX,0x10B0u);   
			IOMUXC_SetPinConfig(IOMUXC_GPIO_SD_B0_05_LPUART8_RX,0x10B0u);
		}

	}
}

//�ж�ѡ��
IRQn_Type Lpuart_IRQN_Chose(LPUART_Type* LPUART_x)
{
	IRQn_Type temp;
	switch((int)LPUART_x)
	{
		case (int)LPUART1:	temp=LPUART1_IRQn;	break;
		case (int)LPUART2:	temp=LPUART2_IRQn;	break;
		case (int)LPUART3:	temp=LPUART3_IRQn;	break;
		case (int)LPUART4:	temp=LPUART4_IRQn;	break;
		case (int)LPUART5:	temp=LPUART5_IRQn;	break;
		case (int)LPUART6:	temp=LPUART6_IRQn;	break;
		case (int)LPUART7:	temp=LPUART7_IRQn;	break;
		case (int)LPUART8:	temp=LPUART8_IRQn;	break;	
	}
	return temp;
}

//�����ж����ȼ�
//IRQn:	�ж�Դ
//prep����ռ���ȼ�
//subp�������ȼ�
void RT_NVIC_SetPriority(IRQn_Type IRQn,uint32_t prep,uint32_t subp)
{ 
	uint32_t prioritygroup = 0x00;
  
	prioritygroup=NVIC_GetPriorityGrouping();
	NVIC_SetPriority(IRQn,NVIC_EncodePriority(prioritygroup,prep,subp));
}



uint8_t g_tipString[]=
    "Lpuart init ok";


//�������ƣ����ڳ�ʼ��
//��     �������ںţ�������,��������,��ռ���ȼ�,�����ȼ�
void Lpuart_Init(LPUART_Type* LPUART_x,uint32_t Baud_Rate,int LPUART_Map,uint32_t prep,uint32_t subp)
{

	lpuart_config_t config;//����Э�����Խṹ��	
	
	Lpuart_IOMUXC_SetPin(LPUART_x,LPUART_Map); //���� ���Ҹ�������
                                         
	LPUART_GetDefaultConfig(&config);
	config.baudRate_Bps = Baud_Rate;//������
	config.dataBitsCount=kLPUART_EightDataBits; 	//8λ

	config.parityMode = kLPUART_ParityDisabled;//����żУ��
	config.stopBitCount = kLPUART_OneStopBit;//1λֹͣλ

	config.enableTx = true;//ʹ�ܴ��ڷ���
	config.enableRx = true;//ʹ�ܴ��ڽ���

	LPUART_Init(LPUART_x, &config, BOARD_DebugConsoleSrcFreq());//��ʼ��

	LPUART_EnableInterrupts(LPUART_x, kLPUART_RxDataRegFullInterruptEnable);//����ʹ�ܽ����ж�
	
	EnableIRQ(Lpuart_IRQN_Chose(LPUART_x));//ʹ���ж�
	
	/* �����жϵ����ȼ� */
	uint32_t prioritygroup = 0x00;	  
	prioritygroup=NVIC_GetPriorityGrouping();
	NVIC_SetPriority(PIT_IRQn,NVIC_EncodePriority(prioritygroup,prep,subp));

	LPUART_WriteBlocking(LPUART_x, g_tipString, sizeof(g_tipString) / sizeof(g_tipString[0]));

}

//log:
//version:1.0
//data:2019.1.6
//by:��С��




