#include "N76E003.h"
#include "define.h"
#include "common.h"
#include "delay.h"
#include "SFR_Macro.h"
#include "uart.h"
/****************************************************************************/
/* Define putchar send from UART1, printf function will send from P1.6(TXD_1)
/* NOTICE: Since UART1 pin is multi-function with OCD DATA/CLK pin.
/* Suggest download than use run with realchip but not OCD mode.
/****************************************************************************/


#if 0
char putchar (char c)				//for UART1_printf
{
		while (!TI_1);  /* wait until transmitter ready */
		TI_1 = 0;
		SBUF_1 = c;      /* output character */
		return (c);
}
void InitUART(void) 
{
	InitialUART1_Timer3(115200);
	TI_1 = 1;
	while(1)
	{
		printf("\n hello Qitas");
		Timer0_Delay1ms(300);
	}
}

#else
char putchar (char c)  			//for UART0_printf
{				
  while (!TI);
  TI = 0;
  return (SBUF = c);
}
void InitUART(void) 
{
	InitialUART0_Timer3(115200);
	TI = 1;														
	while(1)
	{
		printf("\n Hello world");
		Timer0_Delay1ms(300);
	}
}

#endif



