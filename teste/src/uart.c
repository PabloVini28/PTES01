/*
 * =====================================================================================
 *
 *       Filename:  uart.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/02/2017 10:50:03
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author: José Adrian, jadriannassilva@gmail.com
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */


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
      unsigned int uart_base =  UART_ARRAY_BASE[uart];
      switch(uart){
         case(UART0): // tx=1.11  rx=1.10  cts=1.8  rts=1.9
            cmSetCtrlModule(CM_conf_uart0_txd,0); // do nothing on UART0_tx
            cmSetCtrlModule(CM_conf_uart0_rxd,(1<<4)|(1<<5)); // set pullup/pulldown & receiver enabled on UART0_rx
            padSetMode(CM_conf_uart0_txd,MODE_0); // set p1.11 as UART0_tx
            padSetMode(CM_conf_uart0_rxd,MODE_0); // set p1.10 as UART0_rx
 						
			unsigned int temp = ckmGetCLKModuleRegister(CKM_WKUP_CLKSTCTRL);
            temp &= ~(0b11);
            temp |= 0b10;      // software-forced wake-up transition on the "always on clock domain", TRM Table 8-92
			ckmSetCLKModuleRegister(CKM_WKUP_CLKSTCTRL,temp);
           
            temp = ckmGetCLKModuleRegister(CKM_PER_L4HS_CLKSTCTRL);
	        temp &= ~(0b11);
            temp |= 0b10;      // software-forced wake up transition on the L4 high speed domain
            ckmSetCLKModuleRegister(CKM_PER_L4HS_CLKSTCTRL,temp);
            
			temp = ckmGetCLKModuleRegister(CKM_WKUP_UART0_CLKCTRL);
	        temp &= ~(0b11);
            temp |= 0b10;      // Module is explicitly enabled,    TRM Table 8-137
            ckmSetCLKModuleRegister(CKM_WKUP_UART0_CLKCTRL,temp);
			while((ckmGetCLKModuleRegister(CKM_WKUP_UART0_CLKCTRL) & (0b11<<16)) != 0); //wait until clock transition is complete
						// TODO: verifiy it next block is needed for uart0
            // warning, why would the UART1 registers need modification when configuring UART0?
            temp = ckmGetCLKModuleRegister(CKM_PER_UART1_CLKCTRL);
            temp &= ~(0b11);
            temp |= 0b10;      // Module is explicitly enabled,    TRM Table 8-137
            ckmSetCLKModuleRegister(CKM_PER_UART1_CLKCTRL, temp);
            
            temp = HWREG(uart_base+0x54);    // SYSC
            temp |= 0x2;      // uart module reset
            HWREG(uart_base+0x54) = temp;
            
            while((HWREG(uart_base+0x58)&1)==0);   // wait for reset to be complete
            
            //gpioSetPinValue(GPIO1, 21, LOW);
            temp = HWREG(uart_base+0x54);
            temp |= (0x1<<3); // no idle
            HWREG(uart_base+0x54) =temp;
            
            while(((HWREG(uart_base+0x14)&0x40)!=0x40));    // wait for txfifo to be empty
            
            
            float div = 48000000.0/(16.0*(float)baudrate);
            unsigned int intdiv = (unsigned int) div;
            HWREG(uart_base+0x04) = 0;
            HWREG(uart_base+0x20) = 0x7;        // Disable modeselect (default) TRM table 19-50
            HWREG(uart_base+0x0C) = ~(0x7C);    // divisor latch enable, access DLL DHL, set uart as 8bit
            HWREG(uart_base+0x00) = 0;          // DLL = 0
            HWREG(uart_base+0x04) = 0;          // DHL = 0
            HWREG(uart_base+0x0C) = 0x3;        // set uart as 8bit
            HWREG(uart_base+0x10) = 0x3;        // force /rts & /drt to active (low) (?!)
            HWREG(uart_base+0x08) = 0x7;        // clear rx&tx FIFOs, and enables them (each 64 bytes deep)
            HWREG(uart_base+0x0C) = ~(0x7C);    // divisor latch enable, access DLL DHL, set uart as 8bit
            HWREG(uart_base+0x00) = intdiv&0xFF;          // DLL = 0
            HWREG(uart_base+0x04) = (intdiv>>8)&0x3F;          // DHL = 0

//            PUT8(uart_base+0x00,26);         // DLL/DHL value for 115200
            HWREG(uart_base+0x0C) = 0x3;        // set uart as 8 bit
            HWREG(uart_base+0x20) = 0;          // uart 16x oversampling
         break;
         // TODO: implement UART1-5
         default:
         break;
      }
   }
}

void putCh(UART_t uart, char c){
   unsigned int uart_base = UART_ARRAY_BASE[uart];
   while((HWREG(uart_base+0x14)&0x20)!=0x20);   //wait until txfifo is empty
   HWREG(uart_base+0) = c;
}

char getCh(UART_t uart){
   unsigned int uart_base = UART_ARRAY_BASE[uart];
   while((HWREG(uart_base+0x14)&0x1)==0);     //wait for a character to be in the rx fifo
   return(HWREG(uart_base+0x0));
}

int putString(UART_t uart, char *str, unsigned int length){
   for(int i = 0; i < length; i++){
      putCh(uart,str[i]);
   }
   return(length);
}

int uartgetString(UART_t uart, char *buf, unsigned int length){
   for(int i = 0; i < length; i ++){
      buf[i] = getCh(uart);
   }
   return(length);
}

void uartClearBuffer(UART_t uart){
   unsigned int uart_base = UART_ARRAY_BASE[uart];
   while((HWREG(uart_base+0x14)&0x1)==1)
      getCh(uart);
}