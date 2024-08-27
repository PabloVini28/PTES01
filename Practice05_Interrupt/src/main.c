#include "gpio.h"
#include "interruption.h"
#include "timers.h"
#include "uart.h"
#include "control_module.h"
#include "menu.h"

#define DELAY_USE_INTERRUPT 1 // macro para habilitar ou desabilitar o uso de interrupção no delay

unsigned int tempo;

void ISR_Handler(void) {
    
    unsigned int irq_number = HWREG(INTC_BASE+INTC_SIR_IRQ) & 0x7f;
    if(irq_number == 98){
        if(HWREG(SOC_GPIO_1_REGS+GPIO_IRQSTATUS_RAW_0)&(1<<16)){
            gpioIsrHandler(GPIO1,0,16);
            tempo += 100;
            if(tempo > 1000){
                tempo = 50;
            }

		}
        else if(HWREG(SOC_GPIO_1_REGS+GPIO_IRQSTATUS_RAW_0)&(1<<17)){
            gpioIsrHandler(GPIO1,0,17);
            unsigned int mili = chamaMenu();
            tempo = mili;
        }
	}
    if(irq_number == 95){
        timerIrqHandler(TIMER7);
    }
    
    HWREG(INTC_BASE+INTC_CONTROL) = 0x1; // habilita nova interrupção
        
}

int main() {

    disableWdt();

    Init_module_gpio(GPIO1);

    cmSetCtrlModule(CM_conf_gpmc_ben1,7);
    cmSetCtrlModule(CM_conf_gpmc_a0,7);
    cmSetCtrlModule(CM_conf_gpmc_a1,7);
    cmSetCtrlModule(CM_conf_gpmc_ad12,7);
    cmSetCtrlModule(CM_conf_gpmc_csn0,7);

    Init_pin_gpio(GPIO1,28,OUTPUT);
    Init_pin_gpio(GPIO1,12,OUTPUT);
    Init_pin_gpio(GPIO1,29,OUTPUT);
    Init_pin_gpio(GPIO1,16,INPUT);
    Init_pin_gpio(GPIO1,17,INPUT);

    timerSetup(TIMER7);

    Interrupt_Setup(98);
    Interrupt_Setup(95);
    
    Pin_Interrup_Config(GPIO1,16,type0); // tipo A = type0 B = type1
    Pin_Interrup_Config(GPIO1,17,type0); // tipo A = type0 B

    tempo = 50;
    while(1){
        delay(tempo,TIMER7);
        GpioSetPinValue(GPIO1,12,HIGH);
        GpioSetPinValue(GPIO1,28,HIGH);
        GpioSetPinValue(GPIO1,29,HIGH);
        delay(tempo,TIMER7);
        GpioSetPinValue(GPIO1,12,LOW);
        GpioSetPinValue(GPIO1,28,LOW);
        GpioSetPinValue(GPIO1,29,LOW);
    }

    return 0;
}
