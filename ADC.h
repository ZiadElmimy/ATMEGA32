#ifndef ADC_H_
#define ADC_H_
#include "STD_Types.h"

typedef enum{
	  Ch_0,
	  Ch_1,
	  Ch_2,
	  Ch_3,
	  Ch_4,
	  Ch_5,
	  Ch_6,
	  Ch_7
	}ADC_Channel;
	
typedef enum{
	  AREF,
	  AVCC,
	  RESERVED,
	  In256_Ref
	}ADC_Reference;
	
typedef enum{
	  Scaler_2 = 1,
	  Scaler_4,
	  Scaler_8,
	  Scaler_16,
	  Scaler_32,
	  Scaler_64,
	  Scaler_128
	}ADC_PreScaler;
	

void ADC_Initialization(ADC_Reference reference, ADC_PreScaler scaler);
void ADC_Enable(void);
void ADC_Disable(void);
u16 ADC_getRead(ADC_Channel channel);			
u16 Get_Temp(ADC_Channel channel);
u16 ADC_Voltage(ADC_Channel channel);
#endif /* ADC_H_ */
