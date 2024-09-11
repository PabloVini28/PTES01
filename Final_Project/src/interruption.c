#include "interruption.h"
#include "marmota.h"

extern unsigned int numero_pontos;

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
    bool penaliza = true;  // Variável para determinar se a pontuação será penalizada

    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 14)) {
        gpioIsrHandler(GPIO1, type0, 14);
        MarmotaAzul();
        penaliza = false;  // Botão correto, não penalizar
    }

    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 15)) {
        gpioIsrHandler(GPIO1, type0, 15);
        MarmotaBranca();
        penaliza = false;  // Botão correto, não penalizar
    }

    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 16)) {
        gpioIsrHandler(GPIO1, type0, 16);
        MarmotaVerde();
        penaliza = false;  // Botão correto, não penalizar
    }

    if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 17)) {
        gpioIsrHandler(GPIO1, type0, 17);
        MarmotaVermelha();
        penaliza = false;  // Botão correto, não penalizar
    }

    // Penaliza caso nenhum botão tenha sido pressionado corretamente
    if (penaliza) {
        if (numero_pontos > 0) {
            putCh(UART0, 'X');  // 'X' representando uma penalização
            numero_pontos--;
        }
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
        timerIrqHandler(TIMER7);
    }

    HWREG(INTC_BASE + INTC_CONTROL) = 0x1; // habilita nova interrupção
}