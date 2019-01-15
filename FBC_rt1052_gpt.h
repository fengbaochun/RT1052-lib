#ifndef _FBC_RT1052_GPT_H_
#define _FBC_RT1052_GPT_H_

#include "fsl_iomuxc.h"
#include "fsl_gpt.h"  
#include "pad_config.h"  


extern void Gpt_Init(GPT_Type *GPT_x,int channel,uint32_t gpt_inter_time,uint32_t mask,uint32_t prep,uint32_t subp);

#endif

