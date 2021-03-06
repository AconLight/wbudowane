/******************************************************************************
 *
 * Copyright:
 *    (C) 2006 Embedded Artists AB
 *
 * File:
 *    hw.h
 *
 * Description:
 *    Expose hardware specific routines
 *
 *****************************************************************************/
#ifndef _HW_H_
#define _HW_H_

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "../pre_emptive_os/api/general.h"
#include <lpc2xxx.h>


/******************************************************************************
 * Typedefs and defines
 *****************************************************************************/
#define LED_GREEN  1
#define LED_RED    2


/*****************************************************************************
 * Global variables
 ****************************************************************************/
extern tBool ver1_0;
extern tBool ver1_1;

void immediateIoInit(void);
void resetLCD(void);
void setBuzzer(tBool on);
void setLED(tU8 ledSelect, tBool ledState);

#endif
