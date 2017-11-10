/******************************************************************************
 * File:
 *    music.c
 *
 * Description:
 *    Implements music
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
#include "notes.h"
#include "timer.h"

 void 
 bleep(tU8 k){
	//shortly k bleep with the buzzer 
  tU32 i,j;
	for(i=0;i<k;i++){
		for(j=0; j<1000; j++)
		{
			setBuzzer(TRUE);
			sleep(1000);
			setBuzzer(FALSE);
			sleep(1000);
		}
		sleep(10000000);
	}
    
	
 }
	
	
void 
buzzerPlus(tU32 k) {
	//shortly bleep with the buzzer and flash with the LEDs
  tU32 j;

    for(j=0; j<1000000/k; j++)
    {
      setBuzzer(TRUE);
      sleep(k);
      setBuzzer(FALSE);
      sleep(k);
    }
}

void 
dzwiekiWojtka(void){
	tU32 j, i, a = 0, p = 55;
	for(j=10; j>0;j--)
	{
		i = j+p;
		if (j%4 != 0) {
		buzzerPlus(i*i+a);
		sleep(5000000);
		}
	}
	sleep(5000000);
	sleep(5000000);
	for(j=1; j<11;j++)
	{
		i = j+p;
		if (j%4 != 0) {
		buzzerPlus(i*i+a);
		sleep(5000000);
		}
	}
}

void 
 sound(tU32 freq, tU32 lenght, tU32 volume){ //float czy tU32
	// sound with the buzzer 
	//noteLenght=lenght*10000000; //one second
	tU32 t=100000000/(2*freq); //one second
	tU32 j;
	tU32 skala = 99.0;
		for(j=0; j<(freq*lenght/1000000); j++)
		{
			setBuzzer(TRUE);
			sleep(t*volume/skala);
			setBuzzer(FALSE);
			sleep(t*(2*skala-volume)/skala);
		}
}
   void evry() {/*
						sound(A6,sixteenth, 33);
						sleep(62500);
						sound(A6,sixteenth, 33);
						sleep(62500);
							sound(B6,sixteenth, 33);
							sleep(62500);
							sound(B6,sixteenth, 33);
							sleep(62500*4);
		sound(D7,eight);
		sleep(62500);
				sound(F7,quarter);
				sleep(62500);
			sound(E7,eight);
			sleep(62500);
			sound(E7,quarter);
			sleep(62500);	
				sound(F7,quarter);
				sleep(62500);
			
  */ } 
   void ref(tU32 volume) {
				sound(B7,sixteenth, volume);
				sleep(62500);
				sound(B7,sixteenth, volume);
				sleep(62500);
				sound(B7,sixteenth, volume);
				sleep(62500);
				sound(B7,sixteenth, volume);
				sleep(62500);
			sound(A7,eight, volume);
			sleep(62500);
			sound(A7,sixteenth, volume);
			sleep(31250);
			sound(A7,sixteenth, volume);
			sleep(31250);
	sound(F7,(eight+sixteenth), volume);
	sleep(62500);
	sound(F7,(eight+sixteenth), volume);
	sleep(62500);
			sound(A7,quarter, volume);
			sleep(62500);
  }
void 
 music(void){
	// music with the buzzer 
	
				
			//evry();
			sleep(62500*4);
			ref(33);
			sleep(625000);
			
			tU32 j;
		/*for(j=1; j<99; j++)
		{
			sleep(31250*2);
			sound(A7,sixteenth*2, j);
		}
		*/
		
			
			
}


	