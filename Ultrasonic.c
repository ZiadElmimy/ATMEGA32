#include<avr/io.h>
#include <util/delay.h>
#include"Ultrasonic.h"

//set the max of the timer counts to calc the total time
#if(Timer_Mode == Normal)
static u16 max = 65535;
#elif(Timer_Mode == CTC)
static u16 max = OCR1A;
#endif
void distance_measure(void);
void Counter (void);
static u8 flag = 0, c = 0;
static u16 T1 = 0, T2 = 0, Tt;

u16 Ultrasonic_GetDistance(DIO_Pin trig)
{
	static u16 distance = 0;
	Timer01_SetCallBack(ICR1_Interrupt,distance_measure);
#if(Timer_Mode == Normal)
	Timer01_SetCallBack(OVF01_Interrupt,Counter);
	Timer01_OVF_Enable();
#elif(Timer_Mode == CTC)
	Timer01_SetCallBack(CMP01A_Interrupt,Counter);
	Timer01_CMPA_Enable();
#endif
	TImer01_ICU_TriggerEdge(Rising_Edge);
	Timer01_ICU_Enable();
    DIO_WritePin(trig,HIGH);
    _delay_us(10);
    DIO_WritePin(trig,LOW);
    if(flag == 2)
    {
      Tt = (T2- T1) + c*max;
      distance = Tt/58;
      flag = 0;
    }
    return distance;


}

void distance_measure(void)
{
    if(flag == 0)
    {
      T1 = ICR1;
      c= 0;
      TImer01_ICU_TriggerEdge(Falling_Edge);
      flag= 1;
    }
    else if(flag == 1)
    {
    	T2 = ICR1;
        flag = 2;
    }
}

void Counter (void)
{
	c++;
}


