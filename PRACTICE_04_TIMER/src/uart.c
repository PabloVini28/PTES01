#include "uart.h"

static bool checkValidUart(UART_t uart){
   if((uart < UART0) || (uart > UART5)){
      // TODO: raise error (Uart number is either too big or negative: /uart)
      return(false);
   }
   return(true);
}
void uartInitModule(UART_t uart, unsigned int baudrate, STOP_BIT_t stopBit, PARITY_BIT_t parity, FLOW_t flowControl){
   if(checkValidUart(uart)){
      switch(uart){
         case(UART0): // tx=1.11  rx=1.10  cts=1.8  rts=1.9
            cmSetCtrlModule(CM_conf_uart0_txd,0); // do nothing on UART0_tx
            cmSetCtrlModule(CM_conf_uart0_rxd,(1<<4)|(1<<5)); // set pullup/pulldown & receiver enabled on UART0_rx
            padSetMode(CM_conf_uart0_txd,MODE_0); // set p1.11 as UART0_tx
            padSetMode(CM_conf_uart0_rxd,MODE_0); // set p1.10 as UART0_rx
 						
            
         break;
         // TODO: implement UART1-5
         case UART1:
            //
            break;
         case UART2:
            //
            break;
         case UART3:
            //
            break;
         case UART4:
            //
            break;
         case UART5:
            //
            break;

         default:
         break;
      }
   }
}

void uartPutC(UART_t uart, char c){
   unsigned int uart_base = UART_ARRAY_BASE[uart];
   while((HWREG(uart_base+0x14)&0x20)!=0x20);   //wait until txfifo is empty
   HWREG(uart_base+0) = c;
}

char uartGetC(UART_t uart){
   unsigned int uart_base = UART_ARRAY_BASE[uart];
   while((HWREG(uart_base+0x14)&0x1)==0);     //wait for a character to be in the rx fifo
   return(HWREG(uart_base+0x0));
}

int uartPutString(UART_t uart, char *str, unsigned int length){
   for(int i = 0; i < length; i++){
      uartPutC(uart,str[i]);
   }
   return(length);
}

int uartgetString(UART_t uart, char *buf, unsigned int length){
   for(int i = 0; i < length; i ++){
      buf[i] = uartGetC(uart);
   }
   return(length);
}