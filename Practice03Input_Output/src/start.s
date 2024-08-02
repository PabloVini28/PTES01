/*
 * =====================================================================================
 *
 *       Filename:  start.s
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2017 20:05:55
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author:  Francisco Helder (FHC), helderhdw@gmail.com
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

_start:
   mrs r0, cpsr
   bic r0, r0, #0x1F @ clear mode bits
   orr r0, r0, #0x13 @ set SVC mode
//   orr r0, r0, #0xC0 @ disable FIQ and IRQ
   msr cpsr, r0

   ldr sp, =0x4030CDFC  @6kB public stack  TMR 26.1.3.2

   bl _main


.loop: b .loop

