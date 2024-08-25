#ifndef INTERRUPTION_H_
#define INTERRUPTION_H_

#include "hw_types.h"
#include "soc_AM335x.h"
#include "gpio.h"


/* Interrupt */
#define INTC_BASE       						0x48200000
#define INTC_SIR_IRQ    						0x40
#define INTC_CONTROL    						0x48
#define INTC_ILR        						0x100
#define MIR_CLEAR0                              0x88
#define MIR_CLEAR1                              0xA8
#define MIR_CLEAR2 						        0xC8
#define MIR_CLEAR3 					        	0xE8
#define INTC_SYSCONFIG							0x10
#define INTC_SYSSTATUS							0x14
#define INTC_THRESHOLD							0x68



int Interrupt_Setup(unsigned int inter);

#endif /*INTERRUPTION_H_ */