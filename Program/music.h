/******************************************************************************
 * File:
 *    music.h
 *
 * Description:
 *    Implements music
 *
 *****************************************************************************/
#ifndef _MUSIC_H_
#define _MUSIC_H_

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "../pre_emptive_os/api/general.h"
#include <lpc2xxx.h>


void bleep(tU8 k);
void buzzerPlus(tU32 k);
void dzwiekiWojtka(void);
void sound(tU32 freq, tU32 lenght, tU32 volume);
void music(void);


#endif
