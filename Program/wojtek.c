/******************************************************************************
 * File:
 *    WOJTEK.c
 *
 * Description:
 *    buzzer+pwm+UART
 *
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "../pre_emptive_os/api/osapi.h"
#include "../pre_emptive_os/api/general.h"
#include <lpc2xxx.h>

#include "pins.h"
#include "timer.h"
#include "music.h"

void wojtekW(){
	music();
}

