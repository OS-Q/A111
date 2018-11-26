
#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"

#if 0
//#define Enable_ADC_AIN0			ADCCON0&=0xF0;P17_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT0;ADCCON1|=SET_BIT0									//P17
//#define Enable_ADC_AIN1			ADCCON0&=0xF0;ADCCON0|=0x01;P30_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT1;ADCCON1|=SET_BIT0		//P30
//#define Enable_ADC_AIN2			ADCCON0&=0xF0;ADCCON0|=0x02;P07_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT2;ADCCON1|=SET_BIT0		//P07
//#define Enable_ADC_AIN3			ADCCON0&=0xF0;ADCCON0|=0x03;P06_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT3;ADCCON1|=SET_BIT0		//P06
//#define Enable_ADC_AIN4			ADCCON0&=0xF0;ADCCON0|=0x04;P05_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT4;ADCCON1|=SET_BIT0		//P05
//#define Enable_ADC_AIN5			ADCCON0&=0xF0;ADCCON0|=0x05;P04_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT5;ADCCON1|=SET_BIT0		//P04
//#define Enable_ADC_AIN6			ADCCON0&=0xF0;ADCCON0|=0x06;P03_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT6;ADCCON1|=SET_BIT0		//P03
//#define Enable_ADC_AIN7			ADCCON0&=0xF0;ADCCON0|=0x07;P11_Input_Mode;AINDIDS=0x00;AINDIDS|=SET_BIT7;ADCCON1|=SET_BIT0		//P11
//#define Enable_ADC_BandGap	ADCCON0|=SET_BIT3;ADCCON0&=0xF8;																															//Band-gap 1.22V

//#define PWM0_FALLINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
//#define PWM2_FALLINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0|=SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
//#define PWM4_FALLINGEDGE_TRIG_ADC		ADCCON0|=SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1&=~SET_BIT2;ADCCON1|=SET_BIT1
//#define PWM0_RISINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
//#define PWM2_RISINGEDGE_TRIG_ADC		ADCCON0&=~SET_BIT5;ADCCON0|=SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1
//#define PWM4_RISINGEDGE_TRIG_ADC		ADCCON0|=SET_BIT5;ADCCON0&=~SET_BIT4;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1

//#define P04_FALLINGEDGE_TRIG_ADC		ADCCON0|=0x30;ADCCON1&=0xF3;ADCCON1|=SET_BIT1;ADCCON1&=~SET_BIT6
//#define P13_FALLINGEDGE_TRIG_ADC		ADCCON0|=0x30;ADCCON1&=0xF3;ADCCON1|=SET_BIT1;ADCCON1|=SET_BIT6
//#define P04_RISINGEDGE_TRIG_ADC			ADCCON0|=0x30;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1;ADCCON1&=~SET_BIT6
//#define P13_RISINGEDGE_TRIG_ADC			ADCCON0|=0x30;ADCCON1&=~SET_BIT3;ADCCON1|=SET_BIT2;ADCCON1|=SET_BIT1;ADCCON1|=SET_BIT6
#endif

		int ADCdataH[16], ADCdataL[16], ADCsumH=0, ADCsumL=0;
		unsigned char ADCavgH, ADCavgL;
				
/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main (void) 
{
		int i;			
		P05_PushPull_Mode;
		P05 = 1;
		Timer0_Delay1ms(300);
	
		P05 = 0;	
		Enable_ADC_AIN0;						// Enable AIN0 P1.7 as ADC input, Find in "Function_define.h" - "ADC INIT"
		ADCsumH = 0x0000;
		ADCsumL = 0x0000;
			
		for(i=0;i<16;i++)
    {
			clr_ADCF;
			set_ADCS;									// ADC start trig signal
      while(ADCF == 0);
			ADCdataH[i] = ADCRH;
			ADCdataL[i] = ADCRL;
		}		
		
		for(i=0;i<16;i++)
    {
			ADCsumH = ADCsumH + ADCdataH[i];
			ADCsumL = ADCsumL + ADCdataL[i];
		}				

		ADCavgH = ADCsumH/16;
		ADCavgL = ADCsumL/16;
		P05 = 1;
		while(1);
}