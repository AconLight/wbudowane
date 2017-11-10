/******************************************************************************
 * File:
 *    main.c
 *
 * Description:
 *    Main function of the "LPC2104 Color LCD Game Board with Bluetooth"
 *
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "../pre_emptive_os/api/osapi.h"
#include "../pre_emptive_os/api/general.h"
#include <printf_P.h>
#include <ea_init.h>
#include <stdlib.h>
#include "hw.h"
#include "wojtek.h"
#include "michal.h"
#include "pacia.h"
#include "timer.h"


/******************************************************************************
 * Typedefs and defines
 *****************************************************************************/
#define PROC1_STACK_SIZE 800
#define INIT_STACK_SIZE  600


/*****************************************************************************
 * Global variables
 ****************************************************************************/
volatile tU32 ms;


/*****************************************************************************
 * Local variables
 ****************************************************************************/
static tU8 proc1Stack[PROC1_STACK_SIZE];
static tU8 initStack[INIT_STACK_SIZE];
static tU8 pid1;



/*****************************************************************************
 * Local prototypes
 ****************************************************************************/
static void proc1(void* arg);
static void initProc(void* arg);


/*****************************************************************************
 *
 * Description:
 *    The first function to execute 
 *
 ****************************************************************************/
int
main(void)
{
  tU8 error;
  tU8 pid;
  
  osInit();

  //immediate initilaizeation of hardware I/O pins
  immediateIoInit();
  
  osCreateProcess(initProc, initStack, INIT_STACK_SIZE, &pid, 1, NULL, &error);
  osStartProcess(pid, &error);
  
  osStart();
  return 0;
}


static void 
proc1(void* arg)
{
	wojtekW();
	//michalW();
	//paciaW();
	
	for(;;)
	{}
}

/*****************************************************************************
 *
 * Description:
 *    The entry function for the initialization process. 
 *
 * Params:
 *    [in] arg - This parameter is not used in this application. 
 *
 ****************************************************************************/
static void
initProc(void* arg)
{
  tU8 error;

  //eaInit();

#ifdef __IAR_SYSTEMS_ICC__
  printf("\n* Compiled with IAR Embedded Workbench                  *");
#else
  printf("\n* Compiled with GCC                                     *");
#endif
  

  osCreateProcess(proc1, proc1Stack, PROC1_STACK_SIZE, &pid1, 3, NULL, &error);
  osStartProcess(pid1, &error);

  osDeleteProcess();
}

/*****************************************************************************
 *
 * Description:
 *    The timer tick entry function that is called once every timer tick
 *    interrupt in the RTOS. Observe that any processing in this
 *    function must be kept as short as possible since this function
 *    execute in interrupt context.
 *
 * Params:
 *    [in] elapsedTime - The number of elapsed milliseconds since last call.
 *
 ****************************************************************************/
void
appTick(tU32 elapsedTime)
{
  ms += elapsedTime;
}





