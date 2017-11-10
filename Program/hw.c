/******************************************************************************
 *
 * Copyright:
 *    (C) 2006 Embedded Artists AB
 *
 * File:
 *    hw.c
 *
 * Description:
 *    Implements hardware specific routines
 *
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "../pre_emptive_os/api/osapi.h"
#include "../pre_emptive_os/api/general.h"
#include <lpc2xxx.h>

#include "hw.h"
#include "pins.h"


/******************************************************************************
 * Typedefs and defines
 *****************************************************************************/


/*****************************************************************************
 * Global variables
 ****************************************************************************/
tBool ver1_0;
tBool ver1_1;

/*****************************************************************************
 * Local variables
 ****************************************************************************/
//static tU8 greenLedShadow;
//static tU8 btResetShadow;

/*****************************************************************************
 * Local prototypes
 ****************************************************************************/


/*****************************************************************************
 *
 * Description:
 *    Initialize the io-pins and find out if HW is ver 1.0 or ver 1.1
 *
 ****************************************************************************/
void
immediateIoInit(void)
{
  //tU8 initCommand[] = {0x12, 0x97, 0x80, 0x00, 0x40, 0x00, 0x14, 0x00, 0x00};
  //                                                         04 = LCD_RST# low
  //                                                         10 = BT_RST# low

  //make all key signals as inputs
  //IODIR &= ~(KEYPIN_CENTER | KEYPIN_UP | KEYPIN_DOWN | KEYPIN_LEFT | KEYPIN_RIGHT);

  IODIR |= BUZZER_PIN;
  IOSET  = BUZZER_PIN;

  IODIR |= BACKLIGHT_PIN;
  IOSET  = BACKLIGHT_PIN;

  //initialize PCA9532
  //i2cInit();
 // if (I2C_CODE_OK == pca9532(initCommand, sizeof(initCommand), NULL, 0))
  //{
   // ver1_0 = FALSE;
  //  ver1_1 = TRUE;
  //  greenLedShadow = FALSE;
  //  btResetShadow  = TRUE;
  //}

  //else
  //{
    //ver1_0 = TRUE;
    //ver1_1 = FALSE;
    
	//IODIR |= LCD_RST;
    //IOCLR  = LCD_RST;
    
    //IODIR |= BT_RST;
    //IOCLR  = BT_RST;
    
    IODIR |= (LED_GREEN_PIN | LED_RED_PIN);
    IOSET  = (LED_GREEN_PIN | LED_RED_PIN);
  }




/*****************************************************************************
 *
 * Description:
 *    Controls the buzzer (on or off)
 *
 ****************************************************************************/
void
setBuzzer(tBool on)
{
  if (TRUE == on)
    IOCLR = BUZZER_PIN;
  else
    IOSET = BUZZER_PIN;
}


/*****************************************************************************
 *
 * Description:
 *    Controls the two LEDs
 *
 ****************************************************************************/
void
setLED(tU8 ledSelect, tBool ledState)
{
  //tU8 commandLedGreen[] = {0x07, 0x00};
  //                               40 = LED on
  //                               00 = LED off
  //                               10 = BT_RST# low   (must handle this also)

  //tU8 commandLedRed[] =   {0x08, 0x00};
  //                               01 = LED on
  //                               00 = LED off

  //check if ver 1.0 of HW
  if (TRUE == ver1_0)
  {
    if (LED_GREEN == ledSelect)
    {
      if (TRUE == ledState)
        IOCLR = LED_GREEN_PIN;
      else
        IOSET = LED_GREEN_PIN;
    }
    else if (LED_RED == ledSelect)
    {
      if (TRUE == ledState)
        IOCLR = LED_RED_PIN;
      else
        IOSET = LED_RED_PIN;
    }
  }
}


