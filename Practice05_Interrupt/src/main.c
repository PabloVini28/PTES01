#include "gpio.h"
#include "interruption.h"
#include "timers.h"
#include "uart.h"
#include "control_module.h"

#define DELAY_USE_INTERRUPT 1  // macro para habilitar ou desabilitar o uso de interrupção no delay

void ISR_Handler(void) {
    unsigned int irq_number = HWREG(INTC_SIR_IRQ) & 0x7f;
    if(irq_number == 95)
        timerIrqHandler(TIMER7);
    /* acknowledge IRQ */
    HWREG(INTC_CONTROL) = 0x1;
}

int main() {
    disableWdt();

    Init_module_gpio(GPIO1);
    Init_pin_gpio(GPIO1, 28, OUTPUT);
    Interrupt_Setup(98); //gpioint1A
    Interrupt_Setup(95); //timer7

    Pin_Interrup_Config(GPIO1,28,0);

    while (true) {
        
    }

    return 0;
}
