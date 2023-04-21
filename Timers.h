#ifndef TIMERS_H_
#define TIMERS_H_
#include "Vectors.h"
#include "STD_Types.h"

typedef enum{
	    Normal_Mode,
		PhaseCorrect_Mode,
		CTC_Mode,
		FastPWM_Mode
	}Timer_Mode;

typedef enum{
	    Normal,
		Toggle,
		Clear, //non-inverting
		Set //inverting
	}Timer_Output;
	
typedef enum{
	    Stopping,
		No_PreScaler,
		PreScaler_8,
		PreScaler_64,
		PreScaler_128,
		PreScaler_256,
		PreScaler_1024,
		EXT_Falling_Edge,
		EXT_Rising_Edge
	}Timer_PreScaler;
	
typedef enum{
	   OVF00_Interrupt,
	   CMP00_Interrupt
	}Timer0_Interrupt;	
	
typedef enum{
	   OVF01_Interrupt,
	   CMP01A_Interrupt,
	   CMP01B_Interrupt,
	   ICR1_Interrupt
	}Timer1_Interrupt;	
	
typedef enum{
	   Rising_Edge,
	   Falling_Edge
    }Timer1_ICU_Edge;

void Timer00_Initialization(Timer_Mode mode,Timer_PreScaler scaler,Timer_Output output);		
void Timer00_OVF_Enable();
void Timer00_OVF_Disable();
void TImer00_CMP_Enable();
void TImer00_CMP_Disable();
void Timer00_SetCallBack(Timer0_Interrupt inter, void  (*p_fun)(void));

void Timer01_Initialization(Timer_Mode mode,Timer_PreScaler scaler,Timer_Output out_A,Timer_Output out_B);
void Timer01_OVF_Enable();
void Timer01_OVF_Disable();
void Timer01_CMPA_Enable();
void Timer01_CMPA_Disable();
void Timer01_CMPB_Enable();
void Timer01_CMPB_Disable();
void Timer01_ICU_Enable();
void Timer01_ICU_Disable();
void TImer01_ICU_TriggerEdge(Timer1_ICU_Edge edge);
void Timer01_SetCallBack(Timer1_Interrupt inter, void (*p_fun)(void));
#endif /* TIMERS_H_ */
