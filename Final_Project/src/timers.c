#include "timers.h"
#include "gpio.h"
#include "interruption.h"

bool flag_timer;
extern unsigned int flag_reset;
#define DELAY_USE_INTERRUPT 1

void DMTimerWaitForWrite(unsigned int value,Timer timer){

    switch (timer)
    {
    case TIMER2:
        if(HWREG(SOC_DMTIMER_2_REGS+DMTIMER_TSICR) & 0x4) // 100 - terceiro bit setado
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
        if(HWREG(SOC_DMTIMER_7_REGS+DMTIMER_TSICR) & 0x4)
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

void delay(unsigned int value, Timer timer) {
if(flag_reset == 1) return;
#ifdef DELAY_USE_INTERRUPT 
    unsigned int aux = TIMER_OVERFLOW - (value*TIMER_1MS_COUNT);

    switch (timer){
        case TIMER2:
            
         DMTimerWaitForWrite(0x2,TIMER2);
        HWREG(SOC_DMTIMER_2_REGS+DMTIMER_TCRR) = aux;
        flag_timer = false;
        HWREG(SOC_DMTIMER_2_REGS+DMTIMER_IRQENABLE_SET) = 0x2;
        timerEnable(TIMER2);
        while (flag_timer == false);
        HWREG(SOC_DMTIMER_2_REGS+DMTIMER_IRQENABLE_CLR) = 0x2; 
        break;
    case TIMER3:
        DMTimerWaitForWrite(0x2,TIMER3);
        HWREG(SOC_DMTIMER_3_REGS+DMTIMER_TCRR) = aux;
        flag_timer = false;
        HWREG(SOC_DMTIMER_3_REGS+DMTIMER_IRQENABLE_SET) = 0x2;
        timerEnable(TIMER3);
        while (flag_timer == false);
        HWREG(SOC_DMTIMER_3_REGS+DMTIMER_IRQENABLE_CLR) = 0x2;
        break;
    case TIMER4:
        DMTimerWaitForWrite(0x2,TIMER4);
        HWREG(SOC_DMTIMER_4_REGS+DMTIMER_TCRR) = aux;
        flag_timer = false;
        HWREG(SOC_DMTIMER_4_REGS+DMTIMER_IRQENABLE_SET) = 0x2;
        timerEnable(TIMER4);
        while (flag_timer == false);
        HWREG(SOC_DMTIMER_4_REGS+DMTIMER_IRQENABLE_CLR) = 0x2;
        break;
    case TIMER5:
        DMTimerWaitForWrite(0x2,TIMER5);
        HWREG(SOC_DMTIMER_5_REGS+DMTIMER_TCRR) = aux;
        flag_timer = false;
        HWREG(SOC_DMTIMER_5_REGS+DMTIMER_IRQENABLE_SET) = 0x2;
        timerEnable(TIMER5);
        while (flag_timer == false);
        HWREG(SOC_DMTIMER_5_REGS+DMTIMER_IRQENABLE_CLR) = 0x2;
        break;
    case TIMER6:
        DMTimerWaitForWrite(0x2,TIMER6);
        HWREG(SOC_DMTIMER_6_REGS+DMTIMER_TCRR) = aux;
        flag_timer = false;
        HWREG(SOC_DMTIMER_6_REGS+DMTIMER_IRQENABLE_SET) = 0x2;
        timerEnable(TIMER6);
        while (flag_timer == false);
        HWREG(SOC_DMTIMER_6_REGS+DMTIMER_IRQENABLE_CLR) = 0x2;
        break;
    case TIMER7:
        
        DMTimerWaitForWrite(0x2,TIMER7);
        HWREG(SOC_DMTIMER_7_REGS+DMTIMER_TCRR) = aux;
        flag_timer = false;
        HWREG(SOC_DMTIMER_7_REGS+DMTIMER_IRQENABLE_SET) = 0x2;
        timerEnable(TIMER7);
        while (flag_timer == false);
        HWREG(SOC_DMTIMER_7_REGS+DMTIMER_IRQENABLE_CLR) = 0x2;
        break;
    default:
        break;
    }
#else   
    switch (timer){
        case TIMER2:
            while(value!= 0){
            
                DMTimerWaitForWrite(0x2,TIMER2);

                HWREG(SOC_DMTIMER_2_REGS+DMTIMER_TCRR) = 0x0;

                timerEnable(TIMER2);

                while(HWREG(SOC_DMTIMER_2_REGS+DMTIMER_TCRR) < TIMER_1MS_COUNT);

                /* Stop the timer */
                timerDisable(TIMER2);
                value--;
            }
        break;
    case TIMER3:
        while(value!= 0){
            
                DMTimerWaitForWrite(0x2,TIMER3);

                HWREG(SOC_DMTIMER_3_REGS+DMTIMER_TCRR) = 0x0;

                timerEnable(TIMER3);

                while(HWREG(SOC_DMTIMER_3_REGS+DMTIMER_TCRR) < TIMER_1MS_COUNT);

                /* Stop the timer */
                timerDisable(TIMER3);
                value--;
            }
        break;
    case TIMER4:
        while(value!= 0){
            
                DMTimerWaitForWrite(0x2,TIMER4);

                HWREG(SOC_DMTIMER_4_REGS+DMTIMER_TCRR) = 0x0;

                timerEnable(TIMER4);

                while(HWREG(SOC_DMTIMER_4_REGS+DMTIMER_TCRR) < TIMER_1MS_COUNT);

                /* Stop the timer */
                timerDisable(TIMER4);
                value--;
            }
        break;
    case TIMER5:
        while(value!= 0){
            
                DMTimerWaitForWrite(0x2,TIMER5);

                HWREG(SOC_DMTIMER_5_REGS+DMTIMER_TCRR) = 0x0;

                timerEnable(TIMER5);

                while(HWREG(SOC_DMTIMER_5_REGS+DMTIMER_TCRR) < TIMER_1MS_COUNT);

                /* Stop the timer */
                timerDisable(TIMER5);
                value--;
            }
        break;
    case TIMER6:
        while(value!= 0){
            
                DMTimerWaitForWrite(0x2,TIMER6);

                HWREG(SOC_DMTIMER_6_REGS+DMTIMER_TCRR) = 0x0;

                timerEnable(TIMER2);

                while(HWREG(SOC_DMTIMER_6_REGS+DMTIMER_TCRR) < TIMER_1MS_COUNT);

                /* Stop the timer */
                timerDisable(TIMER6);
                value--;
            }
        break;
    case TIMER7:
        while(value!= 0){
            
                DMTimerWaitForWrite(0x2,TIMER7);

                HWREG(SOC_DMTIMER_7_REGS+DMTIMER_TCRR) = 0x0;

                timerEnable(TIMER7);

                while(HWREG(SOC_DMTIMER_7_REGS+DMTIMER_TCRR) < TIMER_1MS_COUNT);

                /* Stop the timer */
                timerDisable(TIMER7);
                value--;
            }
        break;
    default:
        break;    
    }
#endif
}


void timerIrqHandler(Timer timer){

    switch (timer){
        case TIMER2:
           
            HWREG(SOC_DMTIMER_2_REGS+DMTIMER_IRQSTATUS) = 0x2; 

            flag_timer = true;

            timerDisable(TIMER2);
        break;
        
        case TIMER3:
        
            HWREG(SOC_DMTIMER_3_REGS+DMTIMER_IRQSTATUS) = 0x2; 

            flag_timer = true;
            
            timerDisable(TIMER3);
        break;
        
        case TIMER4:
           
            HWREG(SOC_DMTIMER_4_REGS+DMTIMER_IRQSTATUS) = 0x2; 

            flag_timer = true;

            
            timerDisable(TIMER4);
        break;

        case TIMER5:
           
            HWREG(SOC_DMTIMER_5_REGS+DMTIMER_IRQSTATUS) = 0x2; 

            flag_timer = true;

            
            timerDisable(TIMER5);
        break;

        case TIMER6:
           
            HWREG(SOC_DMTIMER_6_REGS+DMTIMER_IRQSTATUS) = 0x2; 

            flag_timer = true;
            
            timerDisable(TIMER6);
        break;

        case TIMER7:
           
            HWREG(SOC_DMTIMER_7_REGS+DMTIMER_IRQSTATUS) = 0x2; 

            flag_timer = true;

            timerDisable(TIMER7);
        break;
        
        default:
            break;
    }

}

void disableWdt(void) {
    HWREG(WDT_WSPR) = 0xAAAA;
    while((HWREG(WDT_WWPS) & (1<<4)));

    HWREG(WDT_WSPR) = 0x5555;
    while((HWREG(WDT_WWPS) & (1<<4)));
}