#include "io.h"
#include <stdio.h>
#include "system.h"
#include "alt_types.h"
#include "sys/alt_irq.h"
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_timer.h"

// create standard embedded type definitions
typedef   signed char   sint8;              // signed 8 bit values
typedef unsigned char   uint8;              // unsigned 8 bit values
typedef   signed short  sint16;             // signed 16 bit values
typedef unsigned short  uint16;             // unsigned 16 bit values
typedef   signed long   sint32;             // signed 32 bit values
typedef unsigned long   uint32;             // unsigned 32 bit values
typedef         float   real32;             // 32 bit real values


//set up pointers to peripherals
//unsigned char* LedPtr      = (unsigned char*)LEDS_BASE;
volatile uint8* hex0Ptr	   = (volatile uint8*)HEX0_BASE;
volatile uint8* swPtr	   = (volatile uint8*)SWITCHES_BASE;
volatile uint8* keyPtr	   = (volatile uint8*)PUSHBUTTONS_BASE;


/*****************************************************************************/
/* Interrupt Service Routine                                                 */
/*   Determines what caused the interrupt and calls the appropriate          */
/*  subroutine.                                                              */
/*                                                                           */
/*****************************************************************************/
/*
 void key_isr(void *context)
 {
    unsigned char current_val;

    //clear timer interrupt
    *keyPtr = 0;

    current_val = *keyPtr;

    *keyPtr = current_val + 1;  // change the display

    return;
}*/

int main(void)
{
						//0     1     2     3     4	   5     6     7     8      9
	int numbers[10] = {0x040,0x079,0x024,0x030,0x019,0x012,0x002,0x078,0x000,0x018}; //Contains all numbers
	int i = 0;

	//alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID,TIMER_0_IRQ,key_isr(),0,0);

	//*hex0Ptr = numbers[i];
while(1){
	while(*keyPtr & 0x02);	//when keyPtr not pressed enter this loop

	while(!(*keyPtr & 0x02));
	if (*swPtr & 0x01)
	{
		if(i>=9)
		{
			i = 9;
		}
		else
		{
			i++;
		}
	}
	else
	{
		if(i<=0)
		{
			i = 0;
		}
		else
		{
			i--;
		}
	}
*hex0Ptr = numbers[i];
}
    return 0;
}
