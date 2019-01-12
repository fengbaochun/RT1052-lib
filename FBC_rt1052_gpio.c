#include "fsl_iomuxc.h"
#include "fsl_gpio.h"  
#include "pad_config.h"  
#include "FBC_rt1052_gpio.h"

/*******API����***********************************************************/
/*

@��:	void GPIO_Common_Init(
						GPIO_Type* GPIOx,//GPIO���
						uint32_t GPIO_Pin,//���ű��
						gpio_pin_direction_t GPIO_direct,//���ģʽ
						uint8_t init_out_level,//���ų�ʼ��ƽ
						gpio_interrupt_mode_t inter_mode,//�����ж�ģʽ

						uint32_t muxRegister,
						uint32_t muxMode,
						uint32_t inputRegister,
						uint32_t inputDaisy,
						uint32_t configRegister//�����⼸������ֱ�Ӿ���һ���궨�� ,�ĵ�ʱ��ֱ�Ӹ���ȥ�ҵ���Ӧ���ŵĶ�Ӧ�궨��ͺ�
						)					   //IOMUXC_GPIO_AD_B1_09_GPIO1_IO25����ͬ�����Ŷ�Ӧ�ĺ궨�岻һ����
						
		
		GPIO_Common_Init(GPIO1,9,kGPIO_DigitalOutput, 0,kGPIO_NoIntmode,IOMUXC_GPIO_AD_B0_09_GPIO1_IO09);
		
		
//����1��GPIO���	 GPIO1~GPIO5
					 					
//����2����Ӧ����	 GPIO1��2��4     1~32
					 GPIO3			1~28
					 GPIO5			1~3					
//����3�������������ģʽ	
					 kGPIO_DigitalInput  ����ģʽ
					 kGPIO_DigitalOutput ���ģʽ
					 
//����4����ʼ����ƽ		1  �ߵ�ƽ  0  �͵�ƽ


//����5�������ж�ģʽ 
					 kGPIO_NoIntmode           		ͨ��IOģʽ�����ᴥ���жϣ�
					 kGPIO_IntLowLevel         		�͵�ƽ�����ж�
					 kGPIO_IntHighLevel           	�ߵ�ƽ�����ж�
					 kGPIO_IntRisingEdge          	�������ش����ж�
					 kGPIO_IntFallingEdge        	�½����ش����ж�
					 kGPIO_IntRisingOrFallingEdge 	ʹ�ܱ���ѡ��λ�Ը���ICR�Ĵ���������

*************************************************************************/
/*
@��:	GPIO_PinWrite(GPIO1, 24, 0);//GPIO1, 24������� ����

@��:	GPIO_PinWrite(GPIO1, 24, 1);//GPIO1, 24������� ����

@��:	GPIO_PinRead(GPIO1, 24);//��ȡ��ǰGPIO����״̬

@��:	GPIO_ClearPinsOutput(GPIO_Type* base, uint32_t mask);//������ŵ�ƽ

@��:	GPIO_PortToggle(GPIO_Type *base, uint32_t mask);//��ת��ǰ���ŵ�ƽ

@��:	GPIO_GetInstance(GPIO_Type *base)//GPIO base ��ȡGPIO�˿ڱ��


*/
/*************************************************************************/
              
//���ų�������
void GPIO_Common_Init(
						GPIO_Type* GPIOx,//GPIO���
						uint32_t GPIO_Pin,//���ű��
						gpio_pin_direction_t GPIO_direct,//���ģʽ
						uint8_t init_out_level,//���ų�ʼ��ƽ
						gpio_interrupt_mode_t inter_mode,//�����ж�ģʽ

						uint32_t muxRegister,
						uint32_t muxMode,
						uint32_t inputRegister,
						uint32_t inputDaisy,
						uint32_t configRegister//�����⼸������ֱ�Ӿ���һ���궨�� ,�ĵ�ʱ��ֱ�Ӹ���ȥ�ҵ���Ӧ���ŵĶ�Ӧ�궨��ͺ�
						)					   //IOMUXC_GPIO_AD_B1_09_GPIO1_IO25����ͬ�����Ŷ�Ӧ�ĺ궨�岻һ����
{

	IOMUXC_SetPinMux(muxRegister,muxMode,inputRegister,inputDaisy,configRegister, 0U);//�������Ź��� IOMUXC����

	IOMUXC_SetPinConfig(muxRegister,muxMode,inputRegister,inputDaisy,configRegister, PAD_CONFIG_DATA); //����PAD����

	gpio_pin_config_t GPIO_config_s;/* ����gpio��ʼ�����ýṹ�� */

	GPIO_config_s.direction = GPIO_direct; //���ģʽ
	GPIO_config_s.outputLogic =  init_out_level;//��ƽѡ��
	GPIO_config_s.interruptMode = inter_mode; //�ж�ģʽ

	/* ��ʼ�� LED GPIO. */
	GPIO_PinInit(GPIOx, GPIO_Pin, &GPIO_config_s);
}


//log:
//version:1.0
//data:2019.1.1
//by:��С��



void Init_gpio()
{
//	GPIO_Common_Init(
//				GPIO1,//GPIO���
//				24,//���ű��
//				kGPIO_DigitalOutput,//���ģʽ
//				0,//���ų�ʼ��ƽ
//				kGPIO_NoIntmode,//�����ж�ģʽ

//				IOMUXC_GPIO_AD_B1_08_GPIO1_IO24
//				//�����⼸������ֱ�Ӿ���һ���궨�� ,�ĵ�ʱ��ֱ�Ӹ���ȥ�ҵ���Ӧ���ŵĶ�Ӧ�궨��ͺ�
//				);
	
//	GPIO_Common_Init(GPIO1,9,kGPIO_DigitalOutput, 1,kGPIO_NoIntmode,IOMUXC_GPIO_AD_B0_09_GPIO1_IO09);
//	GPIO_Common_Init(GPIO1,10,kGPIO_DigitalOutput,1,kGPIO_NoIntmode,IOMUXC_GPIO_AD_B0_10_GPIO1_IO10);
//	GPIO_Common_Init(GPIO1,24,kGPIO_DigitalOutput,1,kGPIO_NoIntmode,IOMUXC_GPIO_AD_B1_08_GPIO1_IO24);
//	GPIO_Common_Init(GPIO1,25,kGPIO_DigitalOutput,1,kGPIO_NoIntmode,IOMUXC_GPIO_AD_B1_09_GPIO1_IO25);
	
	GPIO_Common_Init(GPIO3,7,kGPIO_DigitalOutput, 1,kGPIO_NoIntmode,IOMUXC_GPIO_SD_B0_05_GPIO3_IO17);
}

