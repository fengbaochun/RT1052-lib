#ifndef _FBC_RT1052_QTMR_H_
#define _FBC_RT1052_QTMR_H_

#include "fsl_iomuxc.h"
#include "pad_config.h"
#include "fsl_qtmr.h"
/* 获取QTMR驱动程序的源时钟 */
#define QTMR_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_IpgClk)
extern void Qtmr_Init(TMR_Type *base,uint16_t ticks,int channel_1,int channel_2,uint32_t prep,uint32_t subp);




#endif

