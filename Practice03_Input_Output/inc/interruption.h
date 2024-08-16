#ifndef INTERRUPTION_H_
#define INTERRUPTION_H_

#include "hw_types.h"
#include "soc_AM335x.h"
#include "gpio.h"
/*
 * =====================================================================================
 *
 *       Filename:  interruption.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/02/2022
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author:  José Adrian
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */


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

/* The Input clock is selected as 24MHz. So for 1ms set the count to 0x5DC0. 
 *If the input clock is changed to different source this value has to be updated 
 *accordingly.	
*/
#define TIMER_1MS_COUNT                 		0x5DC0u
#define TIMER_OVERFLOW                  		0xFFFFFFFFu

int Interrupt_Setup(unsigned int inter);

#endif /*INTERRUPTION_H_ */