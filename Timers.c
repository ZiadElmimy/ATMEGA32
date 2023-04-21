#include <avr/io.h>
#include <util/delay.h>
#include "Timers.h"

void (*p_ovf)(void);
void (*p_cmp)(void);
void (*p_ovf1)(void);
void (*p_cmp1A)(void);
void (*p_cmp1B)(void);
void (*p_ICU1) (void);

void Timer00_Initialization(Timer_Mode mode,Timer_PreScaler scaler,Timer_Output output)
{
	//choose the mode of timer 0
	switch(mode)
	{
		case Normal_Mode:
		    TCCR0 &= ~(1<<WGM01);
			TCCR0 &= ~(1<<WGM00);
			break;
		case PhaseCorrect_Mode:
		    TCCR0 &= ~(1<<WGM01);
			TCCR0 &= ~(1<<WGM00);
			break;
		case CTC_Mode:
		    TCCR0 |= (1<<WGM01);
			TCCR0 &= ~(1<<WGM00);
			break;
		case FastPWM_Mode:
		    TCCR0 |= (1<<WGM01);
			TCCR0 |= (1<<WGM00);
			break;			
	}
	
	//choose the output mode for timer 0
	switch(output)
	{
		case Normal:
		    TCCR0 &= ~(1<<COM01);
			TCCR0 &= ~(1<<COM00);
			break;
		case Toggle:
		    TCCR0 &= ~(1<<COM01);
			TCCR0 |= (1<<COM00);
			break;
		case Clear:
		    TCCR0 |= (1<<COM01);
			TCCR0 &= ~(1<<COM00);
			break;
		case Set:
		    TCCR0 |= (1<<COM01);
			TCCR0 |= (1<<COM00);
			break;			
	}
	
	//set the pre-scaler for timer 0
	TCCR0 &= 0xF8;
	TCCR0 |= scaler;
}

void Timer00_OVF_Enable()
{
	TIMSK |= (1<<TOIE0);
}

void Timer00_OVF_Disable()
{
	TIMSK &= ~(1<<TOIE0);
}

void TImer00_CMP_Enable()
{
	TIMSK |= (1<<OCIE0);
}

void TImer00_CMP_Disable()
{
	TIMSK &= ~(1<<OCIE0);
}

void Timer00_SetCallBack(Timer0_Interrupt inter, void  (*p_fun)(void))
{
	switch(inter)
	{
		case OVF00_Interrupt:
		    p_ovf = p_fun;
			break;
		case CMP00_Interrupt:
		    p_cmp = p_fun;
			break;	
	}
}

ISR(TIMER0_OVF_Vector)
{
	p_ovf();
}

ISR(TIMER0_COMP_Vector)
{
	p_cmp();
}



void Timer01_Initialization(Timer_Mode mode,Timer_PreScaler scaler,Timer_Output out_A,Timer_Output out_B)
{
	//choose the mode of timer 1
	//I choose the top for pwm-modes as ICR1 to control the duty of the wave using OCR1
	switch(mode)
	{
		case Normal_Mode:
		    TCCR1B &= ~(1<<WGM13);
			TCCR1B &= ~(1<<WGM12);
			TCCR1A &= ~(1<<WGM11);
			TCCR1A &= ~(1<<WGM10);
			break;
		case PhaseCorrect_Mode:	//top is ICR1
		    TCCR1B |= (1<<WGM13);
		    TCCR1B &= ~(1<<WGM12);
		    TCCR1A |= (1<<WGM11);
		    TCCR1A &= ~(1<<WGM10);
			break;
		case CTC_Mode: 	//top is OCR1A
		    TCCR1B &= ~(1<<WGM13);
		    TCCR1B |= (1<<WGM12);
		    TCCR1A &= ~(1<<WGM11);
		    TCCR1A &= ~(1<<WGM10);
			break;
		case FastPWM_Mode:  //top is ICR1
		    TCCR1B |= (1<<WGM13);
		    TCCR1B |= (1<<WGM12);
		    TCCR1A |= (1<<WGM11);
		    TCCR1A &= ~(1<<WGM10);	
			break;
	}
	
	//choose the output_A mode for timer 1
	switch(out_A)
	{
		case Normal:
		    TCCR1A &= ~(1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			break;
		case Toggle:
		    TCCR1A &= ~(1<<COM1A1);
			TCCR1A |= (1<<COM1A0);
			break;
		case Clear:  //non-inverting
		    TCCR1A |= (1<<COM1A1);
			TCCR1A &= ~(1<<COM1A0);
			break;
		case Set:  //inverting
		    TCCR1A |= (1<<COM1A1);
			TCCR1A |= (1<<COM1A0);
			break;			
	}
	
	//choose the output_B mode for timer 1
	switch(out_B)
	{
		case Normal:
		    TCCR1A &= ~(1<<COM1B1);
		    TCCR1A &= ~(1<<COM1B0);
			break;
		case Toggle:
		    TCCR1A &= ~(1<<COM1B1);
		    TCCR1A |= (1<<COM1B0);
			break;
		case Clear: //non-inverting
		    TCCR1A |= (1<<COM1B1);
		    TCCR1A &= ~(1<<COM1B0);
			break;
		case Set:  // inverting
		    TCCR1A |= (1<<COM1B1);
		    TCCR1A |= (1<<COM1B0);		
			break;	
	}
	
	//set the pre-scaler for timer 1
	TCCR1B &= 0xF8;
	TCCR1B |= scaler;
}

void TImer01_ICU_TriggerEdge(Timer1_ICU_Edge edge)
{
	switch(edge)
	{
	   case Rising_Edge:
		   TCCR1B |= (1<<ICES1);
		   break;
	   case Falling_Edge:
		   TCCR1B &= ~(1<<ICES1);
		   break;
	}
}

void Timer01_OVF_Enable()
{
	TIMSK |= (1<<TOIE1);
}

void Timer01_OVF_Disable()
{
	TIMSK &= ~(1<<TOIE1);
}

void Timer01_CMPA_Enable()
{
	TIMSK |= (1<<OCIE1A);
}

void Timer01_CMPA_Disable()
{
	TIMSK &= ~(1<<OCIE1A);
}

void Timer01_CMPB_Enable()
{
	TIMSK |= (1<<OCIE1B);
}

void Timer01_CMPB_Disable()
{
	TIMSK &= ~(1<<OCIE1B);
}

void Timer01_ICU_Enable()
{
	TIMSK |= (1<<TICIE1);
}

void Timer01_ICU_Disable()
{
	TIMSK &= ~(1<<TICIE1);
}

void Timer01_SetCallBack(Timer1_Interrupt inter, void (*p_fun)(void))
{
	switch(inter)
	{
		case OVF01_Interrupt:
		     p_ovf1 = p_fun;
			 break;
		case CMP01A_Interrupt:
		     p_cmp1A = p_fun;
			 break;
		case CMP01B_Interrupt:
		     p_cmp1B = p_fun;
		     break;
		case ICR1_Interrupt:
			 p_ICU1 = p_fun;
			 break;
	}
}

ISR(TIMER1_OVF_Vector)
{
	p_ovf1();
}

ISR(TIMER1_COMA_Vector)
{
	p_cmp1A();
}

ISR(TIMER1_COMB_Vector)
{
	p_cmp1B();
}

ISR(TIMER1_CAP_Vector)
{
	p_ICU1();
}
