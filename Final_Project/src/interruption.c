#include "interruption.h"
#include "marmota.h"
#include "menu.h"

unsigned int penaliza = 1;  // Variável para determinar se a pontuação será penalizada
unsigned int interrups; // Variável para determinar se as interrupções
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

    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 14)) {
        
        if(GpioGetPinValue(GPIO2,2)==HIGH){
            MarmotaAzul();
        }
        disableAzul();
        gpioIsrHandler(GPIO1, type0, 14);
        interrups++;   
    }

    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 15)) {
        
        if(GpioGetPinValue(GPIO2,1)==HIGH){
            MarmotaBranca();
        }
        disableBranca();
        gpioIsrHandler(GPIO1, type0, 15);
        interrups++;
        
    }
    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 16)) {
        
        if(GpioGetPinValue(GPIO1,28)==HIGH){
            MarmotaVerde();
        }
        disableVerde();
        gpioIsrHandler(GPIO1, type0, 16);
        interrups++;
        
    }

    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 17)) {
        
        if(GpioGetPinValue(GPIO1,12)==HIGH){
            MarmotaVermelha();
        }
        disableVermelha();
        gpioIsrHandler(GPIO1, type0,17);
        interrups++;
        
    }
    
    if(HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 18)){
        gpioIsrHandler(GPIO1,type0,18);
        reset();
    }
    if(HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 19)){  
        gpioIsrHandler(GPIO1,type0,19);
        start();
    }
    }
    if (irq_number == 95) {
        if(interrups > 1){
            decrementa_ponto();
            penalizacao();
        }
        interrups = 0;
        timerIrqHandler(TIMER7);
        Pin_Interrup_Config(GPIO1,14,type0);
        Pin_Interrup_Config(GPIO1,15,type0);
        Pin_Interrup_Config(GPIO1,16,type0);
        Pin_Interrup_Config(GPIO1,17,type0);
        
    }

    HWREG(INTC_BASE + INTC_CONTROL) = 0x1; // habilita nova interrupção
}