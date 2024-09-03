#include "gpio.h"
#include "interruption.h"
#include "timers.h"
#include "uart.h"
#include "control_module.h"
#include "menu.h"

unsigned int numero_pontos = 0;

#define DELAY_USE_INTERRUPT 1 // macro para habilitar ou desabilitar o uso de interrupção no delay

int strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void ISR_Handler(void) {
    unsigned int irq_number = HWREG(INTC_BASE + INTC_SIR_IRQ) & 0x7f;
    if (irq_number == 98) {
        if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 17)) {
            gpioIsrHandler(GPIO1, 0, 17);
            if (GpioGetPinValue(GPIO1, 28) == HIGH) {
                GpioSetPinValue(GPIO1, 28, LOW);
                numero_pontos++;
            }
        }
        if (HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_RAW_0) & (1 << 16)) {
            gpioIsrHandler(GPIO1, 0, 16);
            if (GpioGetPinValue(GPIO1, 12) == HIGH) {
                GpioSetPinValue(GPIO1, 12, LOW);
                numero_pontos++;
            }
        }
    }
    if (irq_number == 95) {
        timerIrqHandler(TIMER7);
    }

    HWREG(INTC_BASE + INTC_CONTROL) = 0x1; // habilita nova interrupção
}

void intToStr(int num, char *str) {
    int i = 0;
    int isNegative = 0;

    // Trata o caso de número negativo
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    // Extrai os dígitos do número de trás para frente
    do {
        str[i++] = (num % 10) + '0';
        num /= 10;
    } while (num != 0);

    // Adiciona o sinal negativo se necessário
    if (isNegative) {
        str[i++] = '-';
    }

    // Adiciona o caractere nulo de terminação
    str[i] = '\0';

    // Inverte a string
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

int main() {
    disableWdt();

    Init_module_gpio(GPIO1);
    char str[5];  // Aumentado para garantir espaço suficiente

    cmSetCtrlModule(CM_conf_gpmc_ben1, 7);
    cmSetCtrlModule(CM_conf_gpmc_ad12, 7);
    cmSetCtrlModule(CM_conf_gpmc_a1, 7);
    cmSetCtrlModule(CM_conf_gpmc_a0, 7);

    Init_pin_gpio(GPIO1, 28, OUTPUT);
    Init_pin_gpio(GPIO1, 12, OUTPUT);
    Init_pin_gpio(GPIO1, 17, INPUT);
    Init_pin_gpio(GPIO1, 16, INPUT);

    timerSetup(TIMER7);

    Interrupt_Setup(98);
    Interrupt_Setup(95);

    Debounce(GPIO1, 16);
    Debounce(GPIO1, 17);

    Pin_Interrup_Config(GPIO1, 17, type0); // tipo A = type0 B = type1
    Pin_Interrup_Config(GPIO1, 16, type0);

    while (true) {
        delay(1000, TIMER7);
        GpioSetPinValue(GPIO1, 28, HIGH); // ponto 1
        delay(1000, TIMER7);
        GpioSetPinValue(GPIO1, 28, LOW);
        delay(1000, TIMER7);
        GpioSetPinValue(GPIO1, 28, HIGH);
        delay(1000, TIMER7);
        GpioSetPinValue(GPIO1, 28, LOW);
        delay(1000, TIMER7);
        GpioSetPinValue(GPIO1, 12, HIGH);
        delay(1000, TIMER7);
        GpioSetPinValue(GPIO1, 12, LOW);
        delay(1000, TIMER7);
        GpioSetPinValue(GPIO1, 12, HIGH);
        delay(1000, TIMER7);
        GpioSetPinValue(GPIO1, 12, LOW);
        delay(1000, TIMER7);

        intToStr(numero_pontos%100, str);
        putString(UART0, str, strlen(str)); // Usando strlen definido anteriormente
    }
    return 0;
}
