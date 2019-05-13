/****************************************************************************
*       Copyright (C), ������ά���ǽ����Ƽ����޹�˾
*
*       N76E003
*       V0.1
*       2017-12-04
*       Woody  QQ:2490006131
*Description
*�����׼16λ��ʱ��/��������
      ��ʱ��0��1
*һ�����3·�ܽ����벶��ģʽ��16λ��ʱ����
      ��ʱ��
*һ�鿴�Ź���ʱ����WDT��
*һ���Ի��Ѷ�ʱ����WKT��
*һ����Զ���װ�ع��ܣ������ڲ�����׼�����ʵĶ�ʱ����
      ��ʱ��3
*�����׼���пڣ�UART���������鴮�пھ���֡������⼰�Զ���ַʶ����
*һ��SPI
*һ��IIC
*6ͨ����ǿ��PWM���
*8·12λADC
* �������ܶ�Ӧ����18���ж�Դ������4���ж����ȼ�����
*****************************************************************************/

/****************************************************************************
*< N76E003 >
			FLASH SIZE:18Kbytes (APROM)
			SRAM SIZE:256bytes
			XRAM SIZE:768bytes
			Package:TSSOP20
* ����
			FLASH:Kbytes
			RAM:  Kbytes
*****************************************************************************/
#include "includes.h"  //���ļ������·��

/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
uint16_t ddddd;

void main (void)
{
    P12_Quasi_Mode;															//For GPIO1 output, Find in "Function_define.h" - "GPIO INIT"
    InitialUART0_Timer1(115200);
    Enable_ADC_BandGap;													//Find in "Function_define.h" - "ADC INIT"

    while(1)
    {
        clr_ADCF;
        set_ADCS;																	// Each time ADC start trig signal
        while(ADCF == 0);
        printf ("\n Value = 0x%bx",ADCRH);
        printf ("\n Value = 0x%bx",ADCRL);
        clr_GPIO1;
        Timer0_Delay1ms(100);
        set_GPIO1;
    }
}




