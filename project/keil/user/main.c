#include "SFR_Macro.h"
#include "N76E003.h"
#include "define.h"
#include "common.h"
#include "delay.h"
#include "adc.h"


/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main(void) 
{	
		u16 AdcVal=0;
		Timer0_Delay1ms(300);
		while(1)
		{
			  AdcVal=adc();
		}
}

