#include "interruption.h"
#include "gpio.h"
#include "timers.h"

int Interrupt_Setup(unsigned int inter){
    if(inter < 0 || inter > 127){
        return false;
    }
    unsigned int aux = inter >> 5 ; // pega o valor de inter dividido entre 32

    switch (aux)
    {
    case 0:
        HWREG(INTC_BASE +  MIR_CLEAR0) |= (1<<(inter%32));
        break;
    case 1:
        HWREG(INTC_BASE +  MIR_CLEAR1) |= (1<<(inter%32));
        break;
    case 2:
        HWREG(INTC_BASE +  MIR_CLEAR2) |= (1<<(inter%32));
        break;
    case 3:
        HWREG(INTC_BASE +  MIR_CLEAR3) |= (1<<(inter%32));
        break;
    default:
        break;
    }
    return true;
}

void ISR_Handler(void) {
    unsigned int irq_number = HWREG(INTC_BASE + INTC_SIR_IRQ) & 0x7f;
    if (irq_number == 98) {
        gpioHandler();
    }
    if (irq_number == 95) {
        timerHandler();
    }

    HWREG(INTC_BASE + INTC_CONTROL) = 0x1; // habilita nova interrupção
}