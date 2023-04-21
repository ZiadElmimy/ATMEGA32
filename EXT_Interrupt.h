#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_
#include "STD_Types.h"
#include "Vectors.h"

typedef enum{
	    LOW_LEVEL,
		ANY_LOGIC,
		FALLING_EDGE,
		RISING_EDGE
	}EXT_ControlMode;

typedef enum{
	    INT_0,
		INT_1,
		INT_2
	}EXT_Interrupt;
	
void EXT_Interrupt_Mode(EXT_Interrupt interrupt,EXT_ControlMode mode);
void EXT_Int_Enable(EXT_Interrupt interrupt);
void EXT_Int_Disable(EXT_Interrupt interrupt);
void EXT_Int00_CallBAck(void (*local_fun)(void));
void EXT_Int01_CallBAck(void (*local_fun)(void));
void EXT_Int02_CallBAck(void (*local_fun)(void));

#endif /* EXT_INTERRUPT_H_ */