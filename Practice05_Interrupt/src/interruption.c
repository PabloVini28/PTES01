#include "interruption.h"

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