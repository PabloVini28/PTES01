#include "uart.h"
#include "menu.h"

int chamaMenu(){
    
    char buffer[4];  // Buffer para 3 dígitos + 1 caractere nulo

    // Solicitar ao usuário uma entrada
    putString(UART0, "Ola professor Helder, digite 3 digitos numericos: ", 50);
    uartGetString(UART0, buffer, 3);
    putString(UART0, "\n\r", 2);

    buffer[3] = '\0';  // Assegure que a string esteja terminada com '\0'

    // Verificar se todos os caracteres são dígitos
    for (int i = 0; i < 3; i++) {
        if (buffer[i] < '0' || buffer[i] > '9') {
            putString(UART0, "Entrada invalida. Por favor, insira apenas digitos.\n\r", 50);
            return 1;
        }
    }

    if(buffer[0] == '0' && buffer[1] == '0' && buffer[2] == '0'){
        putString(UART0, "Entrada invalida. Por favor, insira um valor maior que 0.\n\r", 60);
        return 1;
    }

    unsigned int ms = (buffer[0] - '0') * 100 + (buffer[1] - '0') * 10 + (buffer[2] - '0');

    return ms;
    
}