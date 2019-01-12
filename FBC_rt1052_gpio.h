#ifndef _FBC_RT1052_GPIO_H_
#define _FBC_RT1052_GPIO_H_

#include "fsl_iomuxc.h"
#include "fsl_gpio.h"  
#include "pad_config.h"  

extern void GPIO_Common_Init(
						GPIO_Type* GPIOx,//GPIO编号
						uint32_t GPIO_Pin,//引脚编号
						gpio_pin_direction_t GPIO_direct,//输出模式
						uint8_t init_out_level,//引脚初始电平
						gpio_interrupt_mode_t inter_mode,//引脚中断模式

						uint32_t muxRegister,
						uint32_t muxMode,
						uint32_t inputRegister,
						uint32_t inputDaisy,
						uint32_t configRegister//后面这几个参数直接就是一个宏定义 ,改的时候直接跟进去找到对应引脚的对应宏定义就好
						);					   //IOMUXC_GPIO_AD_B1_09_GPIO1_IO25

extern void Init_gpio(void);


#endif

