#include <string.h>
#include <intrins.h> 
#include <stdio.h>

//#include "common.h"
//#include "delay.h"
#include "N76E003.h"
#include "WS281X.h"
#include "SFR_Macro.h"
#include "define.h"

#include "adc.h"
#include "uart.h"

unsigned char temp _at_ 0x08;
unsigned char idata itemp _at_ 0x80;
unsigned char xdata xtemp _at_ 0x80;
/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main(void) 
{	
	char *i ="test";
	int x =3333;
	InitUART();
	printf("power level=%d",x);
	printf("power level=%s\n",i);
	printf("power level=%d\n",(int)43);
	while(1);
}

