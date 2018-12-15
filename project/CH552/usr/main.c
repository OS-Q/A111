
/********************************** (C) COPYRIGHT *******************************
* File Name          : main.C
* Author             : Qitas
* Version            : V1.0
* Date               : 2018/06/20
* Description        :                        
*******************************************************************************/
#include <stdio.h>
#include <string.h>

#include "CH554.h"                                                  
#include "Debug.h"
#include "ADC.h"


#pragma  NOAREGS

void main( ) 
{
    UINT16 i;
    UINT16 j = 0;
    CfgFsys( );                                                                //CH554时钟选择配置   
    mDelaymS(20);
    mInitSTDIO( );                                                             //串口0初始化
    printf("start ...\n"); 

    ADCInit( 0 );                                                              //ADC时钟配置，0(96clk) 1(384clk)，ADC模块开启	

#if ADC_INTERRUPT                                                              //ADC中断方式
    EA = 1;
    while(1)                                                                   
    {
      for(i=0;i<4;i++){	
        printf("AIN%02x ",(UINT16)i);			                                     //ADC采样通道打印显示，调试用	
        ADC_ChannelSelect( i );                                                //ADC采样电源开启和通道设置，i(0-3)表示采样通道
        ADC_START = 1;                                                         //开始采样，采样完成进入中断
        mDelayuS(30);                                                          //等待采集完成才能切换至下一通道
      }
    } 
#else	
    while(1)                                                                   //ADC 查询方式                                                                  
    {
      for(i=0;i<4;i++){				
        printf("AIN%02x ",(UINT16)i);		
        ADC_ChannelSelect( i );                                                //ADC采样初始化
        ADC_START = 1;                                                         //开始采样，采样完成进入中断
        while(ADC_START);                                                      //ADC_START变为0时，表示采样完成
        printf("DATA: %02x\n",(UINT16)ADC_DATA);
        mDelaymS(100);                                                         //模拟单片机干其他事 
      }	
    }		
#endif		
}