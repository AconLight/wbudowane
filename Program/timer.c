/******************************************************************************
 * File:
 *    TIMER.c
 *
 * Description:
 *    Timer: sleep function
 *
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "../pre_emptive_os/api/osapi.h"
#include "../pre_emptive_os/api/general.h"
#include <lpc2xxx.h>

#include "pins.h"


 void sleep (tU32 czas) { //milimilisekundy
  TIMER1_TCR = 0x02;          //stop and reset timer
  TIMER1_PR  = 0x00;          //set prescaler to zero
  TIMER1_MR0 = (147456 * 1 / 10000) * czas;
  //TIMER1_MR0 = czas * ((FOSC * PLL_MUL)/ (1000000 * PBSD));
  TIMER1_IR  = 0xff;          //reset all interrrupt flags
  TIMER1_MCR = 0x04;          //stop timer on match
  TIMER1_TCR = 0x01;          //start timer
  
  //wait until delay time has elapsed
  while (TIMER1_TCR & 0x01)
    ;

 }