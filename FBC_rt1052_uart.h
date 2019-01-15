#ifndef _FBC_RT1052_UART_H_
#define _FBC_RT1052_UART_H_

#include "fsl_iomuxc.h"
#include "fsl_lpuart.h"  
#include "pad_config.h"  

extern void Lpuart_Init(LPUART_Type* LPUART_x,uint32_t Baud_Rate,int LPUART_Map,uint32_t prep,uint32_t subp);
extern void LPUART_WriteBytes(LPUART_Type* LPUART_x,uint8_t *data,int len);

#define DEMO_RING_BUFFER_SIZE 16
extern uint8_t g_tipString[];
	
extern uint16_t txIndex; /* Index of the data to send out. */
extern uint16_t rxIndex; /* Index of the memory to save new arrived data. */




#endif

