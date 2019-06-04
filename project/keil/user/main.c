#include "N76E003.h"
#include "define.h"
#include "common.h"
#include "delay.h"
#include "adc.h"
#include "SFR_Macro.h"

#include "uart.h"
#include "WS281X.h"

unsigned char temp _at_ 0x08;
unsigned char idata itemp _at_ 0x80;
unsigned char xdata xtemp _at_ 0x80;
/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main(void) 
{	
	InitUART();
}

