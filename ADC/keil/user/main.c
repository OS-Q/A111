#include <string.h>
#include <intrins.h> 
#include <stdio.h>

//#include "common.h"
//
#include "N76E003.h"
//#include "WS281X.h"
#include "SFR_Macro.h"
#include "define.h"
#include "dht11.h"
#include "adc.h"
#include "uart.h"
#include "delay.h"
unsigned char temp _at_ 0x08;
unsigned char idata itemp _at_ 0x80;
unsigned char xdata xtemp _at_ 0x80;
/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main(void) 
{	
	char getdht[6]={0};
	int ret=0;
	InitUART();
	printf("power level=%d\n",(int)43);
	while(1)
	{
			ret = dht11_read(getdht);
			printf("%c",ret);
			printf("%s",getdht);
			printf("%d",(int)0x35);
			Timer1_Delay10ms(100);
	};
}

