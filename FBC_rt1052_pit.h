#ifndef _FBC_RT1052_PIT_H_
#define _FBC_RT1052_PIT_H_

#include "fsl_pit.h"

extern void Pit_Init(int channel,uint64_t time_us,int prep,int subp);


#endif

