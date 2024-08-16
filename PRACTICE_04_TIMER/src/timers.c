#include "timers.h"

void DMTimerWaitForWrite(unsigned int value,Timer timer){

    switch (timer)
    {
    case TIMER2:
        if(HWREG(SOC_DMTIMER_2_REGS+DMTIMER_TSICR) & 0x4); // 100
        while(value & HWREG(SOC_DMTIMER_2_REGS+DMTIMER_TWPS));
        break;
    case TIMER3:
        if(HWREG(SOC_DMTIMER_3_REGS+DMTIMER_TSICR) & 0x4);
        while(value & HWREG(SOC_DMTIMER_3_REGS+DMTIMER_TWPS));
        break;
    case TIMER4:
        if(HWREG(SOC_DMTIMER_4_REGS+DMTIMER_TSICR) & 0x4);
        while(value & HWREG(SOC_DMTIMER_4_REGS+DMTIMER_TWPS));
        break;
    case TIMER5:
        if(HWREG(SOC_DMTIMER_5_REGS+DMTIMER_TSICR) & 0x4);
        while(value & HWREG(SOC_DMTIMER_5_REGS+DMTIMER_TWPS));
        break;
    case TIMER6:
        if(HWREG(SOC_DMTIMER_6_REGS+DMTIMER_TSICR) & 0x4);
        while(value & HWREG(SOC_DMTIMER_6_REGS+DMTIMER_TWPS));
        break;
    case TIMER7:  
        if(HWREG(SOC_DMTIMER_7_REGS+DMTIMER_TSICR) & 0x4);
        while(value & HWREG(SOC_DMTIMER_7_REGS+DMTIMER_TWPS));
        break;
    default:
        break;
    }
}

void timerEnable(Timer timer){
    switch (timer)
    {
    case TIMER2:
        DMTimerWaitForWrite(0x1,TIMER2);
        HWREG(SOC_DMTIMER_2_REGS+DMTIMER_TCLR) |= 0x1;
        break;
    case TIMER3:
        DMTimerWaitForWrite(0x1,TIMER3);
        HWREG(SOC_DMTIMER_3_REGS+DMTIMER_TCLR) |= 0x1;
        break;

    case TIMER4:
        DMTimerWaitForWrite(0x1,TIMER4);
        HWREG(SOC_DMTIMER_4_REGS+DMTIMER_TCLR) |= 0x1;
        break;
    case TIMER5:
        DMTimerWaitForWrite(0x1,TIMER5);
        HWREG(SOC_DMTIMER_5_REGS+DMTIMER_TCLR) |= 0x1;
        break;
    case TIMER6:
        DMTimerWaitForWrite(0x1,TIMER6);
        HWREG(SOC_DMTIMER_6_REGS+DMTIMER_TCLR) |= 0x1;
        break;
    case TIMER7:
        DMTimerWaitForWrite(0x1,TIMER7);
        HWREG(SOC_DMTIMER_7_REGS+DMTIMER_TCLR) |= 0x1;
        break;
    default:
        break;
    }
}

void timerDisable(Timer timer){
    switch (timer)
    {
    case TIMER2:
        DMTimerWaitForWrite(0x1,TIMER2);
        HWREG(SOC_DMTIMER_2_REGS+DMTIMER_TCLR) &= ~0x1;
        break;
    case TIMER3:
        DMTimerWaitForWrite(0x1,TIMER3);
        HWREG(SOC_DMTIMER_3_REGS+DMTIMER_TCLR) &= ~0x1;
        break;
    case TIMER4:
        DMTimerWaitForWrite(0x1,TIMER4);
        HWREG(SOC_DMTIMER_4_REGS+DMTIMER_TCLR) &= ~0x1;
        break;
    case TIMER5:
        DMTimerWaitForWrite(0x1,TIMER5);
        HWREG(SOC_DMTIMER_5_REGS+DMTIMER_TCLR) &= ~0x1;
        break;
    case TIMER6:
        DMTimerWaitForWrite(0x1,TIMER6);
        HWREG(SOC_DMTIMER_6_REGS+DMTIMER_TCLR) &= ~0x1;
        break;
    case TIMER7:
        DMTimerWaitForWrite(0x1,TIMER7);
        HWREG(SOC_DMTIMER_7_REGS+DMTIMER_TCLR) &= ~0x1;
        break;
    default:
        break;
    }
}

void timerSetup(Timer timer){
    switch (timer)
    {
    case TIMER2:
        HWREG(SOC_CM_PER_REGS+TIMER2_CLKCTRL) |= 0x2;
        while ((HWREG(SOC_CM_PER_REGS+TIMER2_CLKCTRL) & 0x3) != 0x2);
        break;
    case TIMER3:
        HWREG(SOC_CM_PER_REGS+TIMER3_CLKCTRL) |= 0x2;
        while ((HWREG(SOC_CM_PER_REGS+TIMER3_CLKCTRL) & 0x3) != 0x2);
        break;
    case TIMER4:
        HWREG(SOC_CM_PER_REGS+TIMER4_CLKCTRL) |= 0x2;
        while ((HWREG(SOC_CM_PER_REGS+TIMER4_CLKCTRL) & 0x3) != 0x2);
        break;
    case TIMER5:
        HWREG(SOC_CM_PER_REGS+TIMER5_CLKCTRL) |= 0x2;
        while ((HWREG(SOC_CM_PER_REGS+TIMER5_CLKCTRL) & 0x3) != 0x2);
        break;
    case TIMER6:
        HWREG(SOC_CM_PER_REGS+TIMER6_CLKCTRL) |= 0x2;
        while ((HWREG(SOC_CM_PER_REGS+TIMER6_CLKCTRL) & 0x3) != 0x2);
        break;
    case TIMER7:
        HWREG(SOC_CM_PER_REGS+TIMER7_CLKCTRL) |= 0x2;
        while ((HWREG(SOC_CM_PER_REGS+TIMER7_CLKCTRL) & 0x3) != 0x2);
        break;
    default:
        break;
    }
}

void delay(unsigned int value,Timer timer){
    switch (timer)
    {
    case TIMER2:
        
        break;
    case TIMER3:
    /* code */
        break;

    case TIMER4:
    /* code */
        break;
    case TIMER5:
    /* code */
        break;
    case TIMER6:
    /* code */
        break;
    case TIMER7:
    /* code */
        break;
    default:
        break;
    }
}
