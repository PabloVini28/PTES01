#ifndef TIMERS_H_
#define TIMERS_H_
/*
 * =====================================================================================
 *
 *       Filename:  timers.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/02/2022
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author: José Adrian 
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */
#include "interruption.h"
#include "soc_AM335x.h"
#include "hw_types.h"

/* The Input clock is selected as 24MHz. So for 1ms set the count to 0x5DC0. 
 *If the input clock is changed to different source this value has to be updated 
 *accordingly.	
*/
#define TIMER_1MS_COUNT                 		0x5DC0u
#define TIMER_OVERFLOW                  		0xFFFFFFFFu

#define TIMER7_CLKCTRL					        0x7C
#define TIMER6_CLKCTRL                          0xF0
#define TIMER5_CLKCTRL                          0xEC
#define TIMER4_CLKCTRL                          0x88
#define TIMER3_CLKCTRL                          0x84
#define TIMER2_CLKCTRL                          0x80     


/*OFFSETS OF DMTIMER(x)*/

#define DMTIMER_TIDR   							0x00
#define DMTIMER_TIOCP_CFG   					0x10
#define DMTIMER_IRQ_EOI   						0x20
#define DMTIMER_IRQSTATUS_RAW   				0x24
#define DMTIMER_IRQSTATUS   					0x28
#define DMTIMER_IRQENABLE_SET   				0x2C
#define DMTIMER_IRQENABLE_CLR   				0x30
#define DMTIMER_IRQWAKEEN  	 					0x34
#define DMTIMER_TCLR   							0x38
#define DMTIMER_TCRR   							0x3C
#define DMTIMER_TLDR   							0x40
#define DMTIMER_TTGR   							0x44
#define DMTIMER_TWPS   							0x48
#define DMTIMER_TMAR   							0x4C
#define DMTIMER_TCAR1   						0x50
#define DMTIMER_TCAR2   						0x58
#define DMTIMER_TSICR  		 					0x54

/* RTC */
#define RTC_BASE           						0x44E3E000
#define SECONDS_REG        						0x44E3E000
#define MINUTES_REG        						0x44E3E004
#define HOURS_REG          						0x44E3E008
#define RTC_CTRL_REG       						0x44E3E040
#define RTC_STATUS_REG     						0x44E3E044
#define RTC_INTERRUPTS_REG 						0x44E3E048
#define RTC_OSC_REG        						0x44E3E054
#define KICK0R             						0x44E3E06C
#define KICK1R             						0x44E3E070

typedef enum Timer{
    TIMER2 = 2,
    TIMER3,
    TIMER4,
    TIMER5,
    TIMER6,
    TIMER7
}Timer;


/****************************************************************************
 * PROTOTIPE OF FUNCTIONS
 * *************************************************************************/
void DMTimerWaitForWrite(unsigned int ,Timer);
void timerEnable(Timer);
void timerDisable(Timer);
void delay(unsigned int ,Timer);
void timerSetup(Timer);
void timerIrqHandler(Timer);

#endif /*TIMERS_H_ */