#ifndef _FBC_RT1052_GPIO_H_
#define _FBC_RT1052_GPIO_H_

#include "fsl_iomuxc.h"
#include "fsl_gpio.h"  
#include "pad_config.h"  

extern void GPIO_Common_Init(
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
						);					   //IOMUXC_GPIO_AD_B1_09_GPIO1_IO25

extern void Init_gpio(void);


#endif

