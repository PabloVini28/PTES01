#ifndef UART_H_
#define UART_H_

/*
 * =====================================================================================
 *
 *       Filename:  uart.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/02/2022
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author: José Adrian 
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#include "hw_types.h"
#include "soc_AM335x.h"
#include "gpio.h"
#include "pad.h"
#include "control_module.h"
#include "clock_module.h"
#include "interruption.h"
#include "timers.h"

#define UARTx_OP_R_RHR 			0x0
#define UARTx_OP_R_IER			0x4
#define UARTx_OP_R_IIR			0x8
#define UARTx_OP_R_LCR			0xC
#define UARTx_OP_R_MCR			0x10
#define UARTx_OP_R_LSR			0x14
#define UARTx_OP_R_MSRTCR		0x18
#define UARTx_OP_R_SPRTLR		0x1C
#define UARTx_OP_R_MDR1			0x20
#define UARTx_OP_R_MDR2			0x24
#define UARTx_OP_R_SFLSR		0x28
#define UARTx_OP_R_RESUME		0x2C
#define UARTx_OP_R_SFREGL		0x30
#define UARTx_OP_R_SFREGH		0x34
#define UARTx_OP_R_BLR			0x38
#define UARTx_OP_R_ACREG		0x3C
#define UARTx_OP_R_SCR			0x40
#define UARTx_OP_R_SSR			0x44
#define UARTx_OP_R_EBLR			0x48
#define UARTx_OP_R_MVR			0x50
#define UARTx_OP_R_SYSC			0x54
#define UARTx_OP_R_SYSS			0x58
#define UARTx_OP_R_WER			0x5C
#define UARTx_OP_R_CFPS			0x60
#define UARTx_OP_R_RXFIFO_LVL	0x64
#define UARTx_OP_R_TXFIFO_LVL	0x68
#define UARTx_OP_R_IER2			0x6C
#define UARTx_OP_R_ISR2			0x70
#define UARTx_OP_R_FREQ_SEL	0x74
#define UARTx_OP_R_MDR3			0x80
#define UARTx_OP_R_TXDMA		0x84

#define UARTx_OP_W_THR			0x0
#define UARTx_OP_W_IER			0x4
#define UARTx_OP_W_FCR			0x8
#define UARTx_OP_W_LCR			0xC
#define UARTx_OP_W_MCR			0x10
#define UARTx_OP_W_TCR			0x18
#define UARTx_OP_W_SPRTLR		0x1C
#define UARTx_OP_W_MDR1			0x20
#define UARTx_OP_W_MDR2			0x24
#define UARTx_OP_W_TXFLL		0x28
#define UARTx_OP_W_TXFLH		0x2C
#define UARTx_OP_W_RXFLL		0x30
#define UARTx_OP_W_RXFLH		0x34
#define UARTx_OP_W_BLR			0x38
#define UARTx_OP_W_ACREG		0x3C
#define UARTx_OP_W_SCR			0x40
#define UARTx_OP_W_SSR			0x44
#define UARTx_OP_W_EBLR			0x48
#define UARTx_OP_W_SYSC			0x54
#define UARTx_OP_W_WER			0x5C
#define UARTx_OP_W_CFPS			0x60
#define UARTx_OP_W_RXFIFO_LVL	0x64
#define UARTx_OP_W_TXFIFO_LVL	0x68
#define UARTx_OP_W_IER2			0x6C
#define UARTx_OP_W_ISR2			0x70
#define UARTx_OP_W_FREQ_SEL	0x74
#define UARTx_OP_W_MDR3			0x80
#define UARTx_OP_W_TXDMA		0x84

// uart address map if UARTx_LCR[7:0] != 0xBF  (Configuration Mode A)
#define UARTx_MA_R_DLL			0x0
#define UARTx_MA_R_DLH			0x4
#define UARTx_MA_R_IIR			0x8
#define UARTx_MA_R_LCR			0xC
#define UARTx_MA_R_MCR			0x10
#define UARTx_MA_R_LSR			0x14
#define UARTx_MA_R_MSRTCR		0x18
#define UARTx_MA_R_SPRTLR		0x1C
#define UARTx_MA_R_MDR1			0x20
#define UARTx_MA_R_MDR2			0x24
#define UARTx_MA_R_SFLR			0x28
#define UARTx_MA_R_RESUME		0x2C
#define UARTx_MA_R_SFREGL		0x30
#define UARTx_MA_R_SFREGH		0x34
#define UARTx_MA_R_UASR			0x38
#define UARTx_MA_R_SCR			0x40
#define UARTx_MA_R_SSR			0x44
#define UARTx_MA_R_				0x48
#define UARTx_MA_R_MVR			0x50
#define UARTx_MA_R_SYSC			0x54
#define UARTx_MA_R_SYSS			0x58
#define UARTx_MA_R_WER			0x5C
#define UARTx_MA_R_CFPS			0x60
#define UARTx_MA_R_RXFIFO_LVL	0x64
#define UARTx_MA_R_TXFIFO_LVL	0x68
#define UARTx_MA_R_IER2			0x6C
#define UARTx_MA_R_ISR2			0x70
#define UARTx_MA_R_FREQ_SEL	0x74
#define UARTx_MA_R_MDR3			0x80
#define UARTx_MA_R_TXDMA		0x84

#define UARTx_MA_W_DLL			0x00
#define UARTx_MA_W_DLH			0x04
#define UARTx_MA_W_FCR			0x08
#define UARTx_MA_W_LCR			0x0C
#define UARTx_MA_W_MCR			0x10
#define UARTx_MA_W_TCR			0x18
#define UARTx_MA_W_SPRTLR		0x1C
#define UARTx_MA_W_MDR1			0x20
#define UARTx_MA_W_MDR2			0x24
#define UARTx_MA_W_TXFLL		0x28
#define UARTx_MA_W_TXFLH		0x2C
#define UARTx_MA_W_RXFLL		0x30
#define UARTx_MA_W_RXFLH		0x34
#define UARTx_MA_W_SCR			0x40
#define UARTx_MA_W_SSR			0x44
#define UARTx_MA_W_SYSC			0x54
#define UARTx_MA_W_WER			0x5C
#define UARTx_MA_W_CFPS			0x60
#define UARTx_MA_W_RXFIFO_LVL	0x64
#define UARTx_MA_W_TXFIFO_LVL	0x68
#define UARTx_MA_W_IER2			0x6C
#define UARTx_MA_W_ISR2			0x70
#define UARTx_MA_W_FREQ_SEL	0x74
#define UARTx_MA_W_MDR3			0x80
#define UARTx_MA_W_TXDMA		0x84

// uart address map if UARTx_LCR[7:0] == 0xBF  (Configuration Mode B)
#define UARTx_MB_R_DLL			0x00
#define UARTx_MB_R_DLH			0x04
#define UARTx_MB_R_EFR			0x08
#define UARTx_MB_R_LCR			0x0C
#define UARTx_MB_R_XON1ADDR2	0x10
#define UARTx_MB_R_XON2ADDR2	0x14
#define UARTx_MB_R_XOFF1TCR	0x18
#define UARTx_MB_R_XOFF2TLR	0x1C
#define UARTx_MB_R_MDR1			0x20
#define UARTx_MB_R_MDR2			0x24
#define UARTx_MB_R_SFLSR		0x28
#define UARTx_MB_R_RESUME		0x2C
#define UARTx_MB_R_SFREGL		0x30
#define UARTx_MB_R_SFREGH		0x34
#define UARTx_MB_R_UASR			0x38
#define UARTx_MB_R_SCR			0x40
#define UARTx_MB_R_SSR			0x44
#define UARTx_MB_R_MVR			0x50
#define UARTx_MB_R_SYSC			0x54
#define UARTx_MB_R_SYSS			0x58
#define UARTx_MB_R_WER			0x5C
#define UARTx_MB_R_CFPS			0x60
#define UARTx_MB_R_RXFIFO_LVL	0x64
#define UARTx_MB_R_TXFIFO_LVL	0x68
#define UARTx_MB_R_IER2			0x6C
#define UARTx_MB_R_ISR2			0x70
#define UARTx_MB_R_FREQ_SEL	0x74
#define UARTx_MB_R_MDR3			0x80
#define UARTx_MB_R_TXDMA		0x84


#define UARTx_MB_W_DLL			0x00
#define UARTx_MB_W_DLH			0x04
#define UARTx_MB_W_EFR			0x08
#define UARTx_MB_W_LCR			0x0C
#define UARTx_MB_W_XON1ADDR1	0x10
#define UARTx_MB_W_XON2ADDR2	0x14
#define UARTx_MB_W_XOFF1TCR	0x18
#define UARTx_MB_W_XOFF2TLR	0x1C
#define UARTx_MB_W_MDR1			0x20
#define UARTx_MB_W_MDR2			0x24
#define UARTx_MB_W_SFLSR		0x28
#define UARTx_MB_W_RESUME		0x2C
#define UARTx_MB_W_SFREGL		0x30
#define UARTx_MB_W_SFREGH		0x34
#define UARTx_MB_W_UASR			0x38
#define UARTx_MB_W_SCR			0x40
#define UARTx_MB_W_SSR			0x44
#define UARTx_MB_W_MVR			0x50
#define UARTx_MB_W_SYSC			0x54
#define UARTx_MB_W_SYSS			0x58
#define UARTx_MB_W_WER			0x5C
#define UARTx_MB_W_CFPS			0x60
#define UARTx_MB_W_RXFIFO_LVL	0x64
#define UARTx_MB_W_TXFIFO_LVL	0x68
#define UARTx_MB_W_IER2			0x6C
#define UARTx_MB_W_ISR2			0x70
#define UARTx_MB_W_FREQ_SEL	0x74
#define UARTx_MB_W_MDR3			0x80
#define UARTx_MB_W_TXDMA		0x84


/**
 * @brief UART number (0-5)
 **/
typedef enum _UART_t{
   UART0 = 0,
   UART1 = 1,
   UART2 = 2,
   UART3 = 3,
   UART4 = 4,
   UART5 = 5
}UART_t;


/**
 * @brief Flow control
 **/
typedef enum _FLOW_t{
   FLOW_OFF = 0,
   FLOW_ON = 1
}FLOW_t;


/**
 * @brief Parity control
 **/
typedef enum _PARITY_BIT_t{
   PARITY_NONE,
   PARITY_EVEN,
   PARITY_ODD
}PARITY_BIT_t;


/**
 @brief Stop bit size
 **/
typedef enum _STOP_BIT_t{
   STOP1,
   STOP1_5,
   STOP2
}STOP_BIT_t;


/**
 * @fn int uartInitModule(UART_t uart, unsigned int baudrate, STOP_BIT_t stopBit, PARITY_BIT_t parity, FLOW_t flowControl)
 * @brief                  Initialize an UART with coresponding parameters.
 * @param[in] uart         Uart to Initialize (0-5).
 * @param[in] baudrate     Baudrate to initialize the uart to.
 * @param[in] stopBit      Size of the stopBit.
 * @param[in] parity       Parity setting.
 * @param[in] flowControl  Flow Control setting.
 * @return                 void
 **/
void uartInitModule(UART_t uart, unsigned int baudrate, STOP_BIT_t stopBit, PARITY_BIT_t parity, FLOW_t flowControl);


/**
 * @fn void uartPutC(UART_t uart, char c)
 * @brief                  Send a character.
 * @param[in] uart         Uart to send the character through.
 * @param[in] c            Character to send.
 * @return                 void
 **/
void putCh(UART_t uart, char c);


/**
 * @fn char uartGetC(UART_t uart)
 * @brief                  Get a character.
 * @param[in] uart         Uart to get the character from.
 * @return                 The character gotten from the uart.
 **/
char getCh(UART_t uart);


/**
 * @fn int uartPutString(UART_t uart, char *str, unsigned int length)
 * @brief                  Send a string.
 * @param[in] uart         Uart to send the string through.
 * @param[in] str          Pointer to the string to send.
 * @param[in] length       Length of the string to send.
 * @return                 The length sent.
 **/
int putString(UART_t uart, char *str, unsigned int length);

/**
 * @fn int uartGetString(UART_t uart, char *buf, unsigned int length)
 * @brief                  Get a string.
 * @param[in]  uart        Uart to get the string from.
 * @param[out] str         Pointer to the location where to put the string read.
 * @param[in]  length      Length to read.
 * @return                 The lenght read
 **/
int uartGetString(UART_t uart, char *buf, unsigned int length);
void uartClearBuffer(UART_t );

static const unsigned int UART_ARRAY_BASE[] = {SOC_UART_0_REGS, SOC_UART_1_REGS, SOC_UART_2_REGS, SOC_UART_3_REGS, SOC_UART_4_REGS, SOC_UART_5_REGS};

#endif /*UART_H_*/
