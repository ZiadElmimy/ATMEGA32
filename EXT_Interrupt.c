#include <avr/io.h>
#include <util/delay.h>
#include "EXT_Interrupt.h"

void (*INT0_p)(void);
void (*INT1_p)(void);
void (*INT2_p)(void);

void EXT_Interrupt_Mode(EXT_Interrupt interrupt,EXT_ControlMode mode)
{
	switch(interrupt)
	{
		case INT_0:
		     switch(mode)
			 {
				 case LOW_LEVEL:
				     MCUCR &= ~(1<<ISC01);
					 MCUCR &= ~(1<<ISC00);
					 break;
				 case ANY_LOGIC:
				     MCUCR &= ~(1<<ISC01);
				     MCUCR |= (1<<ISC00);
					 break;
				 case FALLING_EDGE:
				     MCUCR |= (1<<ISC01);
				     MCUCR &= ~(1<<ISC00);	
					 break;
				 case RISING_EDGE:
				     MCUCR |= (1<<ISC01);
				     MCUCR |= (1<<ISC00);
					 break;	  	 
			 }
			 break;
		case INT_1:	
		     switch(mode)
			 {
				 case LOW_LEVEL:
				     MCUCR &= ~(1<<ISC11);
					 MCUCR &= ~(1<<ISC10);
					 break;
				 case ANY_LOGIC:
				     MCUCR &= ~(1<<ISC11);
					 MCUCR |= (1<<ISC10);
					 break;
				 case FALLING_EDGE:
				     MCUCR |= (1<<ISC11);
					 MCUCR &= ~(1<<ISC10);
					 break;
				 case RISING_EDGE:
				     MCUCR |= (1<<ISC11);
					 MCUCR |= (1<<ISC10);
					 break;	 	 	 
			 } 
			 break;
		case INT_2:
		     switch(mode)
			 {
				 case LOW_LEVEL:
				 case ANY_LOGIC:
				 case FALLING_EDGE:
				      MCUCSR &= ~(1<<ISC2);
					  break;
				 case RISING_EDGE:
				      MCUCSR |= (1<<ISC2);
					  break;	  
			 }	 
			 break;
	}
	
}

void EXT_Int_Enable(EXT_Interrupt interrupt)
{
	switch(interrupt)
	{
		case INT_0:
		     GICR |= (1<<INT0);
			 break;
	    case INT_1:
		     GICR |= (1<<INT1);
			 break;
		case INT_2:
		     GICR |= (1<<INT2);	
			 break; 		 
	}
}

void EXT_Int_Disable(EXT_Interrupt interrupt)
{
	switch(interrupt)
	{
		case INT_0:
		     GICR &= ~(1<<INT0);
		     break;
		case INT_1:
		     GICR &= ~(1<<INT1);
		     break;
		case INT_2:
		     GICR &= ~(1<<INT2);
			 break;
	}
}

void EXT_Int00_CallBAck(void (*local_fun)(void))
{
	INT0_p = local_fun;
}

void EXT_Int01_CallBAck(void (*local_fun)(void))
{
	INT1_p = local_fun;
}

void EXT_Int02_CallBAck(void (*local_fun)(void))
{
	INT2_p = local_fun;
}

ISR(INT0_Vector)
{
	INT0_p();
}

ISR(INT1_Vector)
{
	INT1_p();
}

ISR(INT2_Vector)
{
	INT2_p();
}
