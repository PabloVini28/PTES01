#ifndef __PAD_H
#define __PAD_H

/*
 * =====================================================================================
 *
 *       Filename:  pad.h
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



#include "control_module.h"

/*-----------------------------------------------------------------------------
 *  ENUM
 *-----------------------------------------------------------------------------*/
typedef enum{
   MODE_0 = 0,
   MODE_1 = 1,
   MODE_2 = 2,
   MODE_3 = 3,
   MODE_4 = 4,
   MODE_5 = 5,
   MODE_6 = 6,
   MODE_7 = 7
   
}pinmode_t;

/*-----------------------------------------------------------------------------
 *  Function prototype
 *-----------------------------------------------------------------------------*/
void padSetMode(CONTROL_MODULE offset, pinmode_t mode);
pinmode_t padGetMode(CONTROL_MODULE offset);

#endif /* __PAD_H */

