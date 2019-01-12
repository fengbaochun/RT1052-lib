#include "fsl_iomuxc.h"
#include "fsl_gpio.h"  
#include "pad_config.h"  
#include "FBC_rt1052_gpio.h"

/*******API函数***********************************************************/
/*

@例:	void GPIO_Common_Init(
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
						)					   //IOMUXC_GPIO_AD_B1_09_GPIO1_IO25（不同的引脚对应的宏定义不一样）
						
		
		GPIO_Common_Init(GPIO1,9,kGPIO_DigitalOutput, 0,kGPIO_NoIntmode,IOMUXC_GPIO_AD_B0_09_GPIO1_IO09);
		
		
//参数1：GPIO编号	 GPIO1~GPIO5
					 					
//参数2：对应引脚	 GPIO1、2、4     1~32
					 GPIO3			1~28
					 GPIO5			1~3					
//参数3：输出或者输入模式	
					 kGPIO_DigitalInput  输入模式
					 kGPIO_DigitalOutput 输出模式
					 
//参数4：初始化电平		1  高电平  0  低电平


//参数5：引脚中断模式 
					 kGPIO_NoIntmode           		通用IO模式（不会触发中断）
					 kGPIO_IntLowLevel         		低电平触发中断
					 kGPIO_IntHighLevel           	高电平触发中断
					 kGPIO_IntRisingEdge          	上升边沿触发中断
					 kGPIO_IntFallingEdge        	下降边沿触发中断
					 kGPIO_IntRisingOrFallingEdge 	使能边沿选择位以覆盖ICR寄存器的配置

*************************************************************************/
/*
@例:	GPIO_PinWrite(GPIO1, 24, 0);//GPIO1, 24这个引脚 拉低

@例:	GPIO_PinWrite(GPIO1, 24, 1);//GPIO1, 24这个引脚 拉高

@例:	GPIO_PinRead(GPIO1, 24);//读取当前GPIO引脚状态

@例:	GPIO_ClearPinsOutput(GPIO_Type* base, uint32_t mask);//清除引脚电平

@例:	GPIO_PortToggle(GPIO_Type *base, uint32_t mask);//反转当前引脚电平

@例:	GPIO_GetInstance(GPIO_Type *base)//GPIO base 获取GPIO端口编号


*/
/*************************************************************************/
              
//引脚常用设置
void GPIO_Common_Init(
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
						)					   //IOMUXC_GPIO_AD_B1_09_GPIO1_IO25（不同的引脚对应的宏定义不一样）
{

	IOMUXC_SetPinMux(muxRegister,muxMode,inputRegister,inputDaisy,configRegister, 0U);//设置引脚功能 IOMUXC复用

	IOMUXC_SetPinConfig(muxRegister,muxMode,inputRegister,inputDaisy,configRegister, PAD_CONFIG_DATA); //配置PAD属性

	gpio_pin_config_t GPIO_config_s;/* 定义gpio初始化配置结构体 */

	GPIO_config_s.direction = GPIO_direct; //输出模式
	GPIO_config_s.outputLogic =  init_out_level;//电平选择
	GPIO_config_s.interruptMode = inter_mode; //中断模式

	/* 初始化 LED GPIO. */
	GPIO_PinInit(GPIOx, GPIO_Pin, &GPIO_config_s);
}


//log:
//version:1.0
//data:2019.1.1
//by:疯小疯



void Init_gpio()
{
//	GPIO_Common_Init(
//				GPIO1,//GPIO编号
//				24,//引脚编号
//				kGPIO_DigitalOutput,//输出模式
//				0,//引脚初始电平
//				kGPIO_NoIntmode,//引脚中断模式

//				IOMUXC_GPIO_AD_B1_08_GPIO1_IO24
//				//后面这几个参数直接就是一个宏定义 ,改的时候直接跟进去找到对应引脚的对应宏定义就好
//				);
	
//	GPIO_Common_Init(GPIO1,9,kGPIO_DigitalOutput, 1,kGPIO_NoIntmode,IOMUXC_GPIO_AD_B0_09_GPIO1_IO09);
//	GPIO_Common_Init(GPIO1,10,kGPIO_DigitalOutput,1,kGPIO_NoIntmode,IOMUXC_GPIO_AD_B0_10_GPIO1_IO10);
//	GPIO_Common_Init(GPIO1,24,kGPIO_DigitalOutput,1,kGPIO_NoIntmode,IOMUXC_GPIO_AD_B1_08_GPIO1_IO24);
//	GPIO_Common_Init(GPIO1,25,kGPIO_DigitalOutput,1,kGPIO_NoIntmode,IOMUXC_GPIO_AD_B1_09_GPIO1_IO25);
	
	GPIO_Common_Init(GPIO3,7,kGPIO_DigitalOutput, 1,kGPIO_NoIntmode,IOMUXC_GPIO_SD_B0_05_GPIO3_IO17);
}

