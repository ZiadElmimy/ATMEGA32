#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"

void ADC_Initialization(ADC_Reference reference, ADC_PreScaler scaler)
{
	//set the reference for the ADC
	switch(reference)
	{
		case AREF:
		     ADMUX &= ~(1<<REFS1);
			 ADMUX &= ~(1<<REFS0);
			 break;
		case AVCC:
		     ADMUX &= ~(1<<REFS1);
		     ADMUX |= (1<<REFS0);	
			 break;
		case RESERVED:
		     ADMUX |= (1<<REFS1);
		     ADMUX &= ~(1<<REFS0);	 
			 break;
		case In256_Ref:
		     ADMUX |= (1<<REFS1);
		     ADMUX |= (1<<REFS0);	
			 break;  
	}
	
	//choose the scaler
	ADCSRA &= 0xF8;
	ADCSRA |= scaler;
	
	//choose the way of reading the value after conversion
	ADMUX &= ~(1<<ADLAR);
}

void ADC_Enable(void)
{
	ADCSRA |= (1<<ADEN);
}

void ADC_Disable(void)
{
	ADCSRA &= ~(1<<ADEN);
}

u16 ADC_getRead(ADC_Channel channel)
{
	volatile static u16 ADC_read;
	//choose the channel
	ADMUX &= 0xF8;
	ADMUX |= channel;
	
	//start conversion
	ADCSRA |= (1<<ADSC);
	
	while(((ADCSRA >> ADSC)&1));
	ADC_read = ADCL | (u16)ADCH<<8;
	return ADC_read;
}

u16 Get_Temp(ADC_Channel channel)
{
	volatile static u16 temp = 0, adc_read = 0;
	adc_read = ADC_getRead(channel);
	adc_read = ((u64)adc_read * 5000)/1023; //to get the voltage in mv.
	temp = adc_read / 10;
	return temp;
}
u16 ADC_Voltage(ADC_Channel channel)
{
	volatile static u16 volt = 0, adc_read = 0;
	adc_read = ADC_getRead(channel);
	volt = ((u64)adc_read * 5000)/1023;
	return volt;
}

