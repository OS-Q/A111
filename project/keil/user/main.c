#include "N76E003.h"
#include "define.h"
#include "common.h"
#include "delay.h"
#include "adc.h"
#include "SFR_Macro.h"


unsigned char temp _at_ 0x08;
unsigned char idata itemp _at_ 0x80;
unsigned char xdata xtemp _at_ 0x80;


void InitUART0(void) 
{
	InitialUART0_Timer3(115200);
	TI = 1;														
	while(1)
	{
		printf("\n Hello world");
		Timer0_Delay1ms(300);
	}
}


void InitUART1(void) 
{
	InitialUART1_Timer3(115200);
	TI_1 = 1;
	while(1)
	{
		printf("\n hello Qitas");
		Timer0_Delay1ms(300);
	}
}

/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main(void) 
{	
	InitUART1();
}

