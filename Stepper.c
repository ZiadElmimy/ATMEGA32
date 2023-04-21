#include <avr/io.h>
#include <util/delay.h>
#include "Stepper.h"

void Forward_move(void)
{
	DIO_WritePin(IN_1,LOW);
	DIO_WritePin(IN_2,HIGH);
	DIO_WritePin(IN_3,LOW);
	DIO_WritePin(IN_4,LOW);
	_delay_ms(delay);
	DIO_WritePin(IN_1,LOW);
	DIO_WritePin(IN_2,LOW);
	DIO_WritePin(IN_3,LOW);
	DIO_WritePin(IN_4,HIGH);
	_delay_ms(delay);
	DIO_WritePin(IN_1,LOW);
	DIO_WritePin(IN_2,LOW);
	DIO_WritePin(IN_3,HIGH);
	DIO_WritePin(IN_4,LOW);
	_delay_ms(delay);
	DIO_WritePin(IN_1,HIGH);
	DIO_WritePin(IN_2,LOW);
	DIO_WritePin(IN_3,LOW);
	DIO_WritePin(IN_4,LOW);
	_delay_ms(delay);
}
void Backward_move(void)
{
	DIO_WritePin(IN_1,LOW);
	DIO_WritePin(IN_2,LOW);
	DIO_WritePin(IN_3,HIGH);
	DIO_WritePin(IN_4,LOW);
	_delay_ms(delay);
	DIO_WritePin(IN_1,LOW);
	DIO_WritePin(IN_2,LOW);
	DIO_WritePin(IN_3,LOW);
	DIO_WritePin(IN_4,HIGH);
	_delay_ms(delay);
	DIO_WritePin(IN_1,LOW);
	DIO_WritePin(IN_2,HIGH);
	DIO_WritePin(IN_3,LOW);
	DIO_WritePin(IN_4,LOW);
	_delay_ms(delay);
	DIO_WritePin(IN_1,HIGH);
	DIO_WritePin(IN_2,LOW);
	DIO_WritePin(IN_3,LOW);
	DIO_WritePin(IN_4,LOW);
	_delay_ms(delay);
}

void forward_angle(u16 angle)
{
	for(u16 i = 0; i < (angle/8); i++)
	{
		Forward_move();
	}
}
void backword_angle(u16 angle)
{
	for(u16 i = 0; i < (angle/8); i++)
	{
		Backward_move();
	}
}

void Forward_rounds(u8 rounds)
{
	for(u16 i = 0; i < (rounds*45); i++)
	{
		Forward_move();
	}
}
void Backward_rounds(u8 rounds)
{
	for(u16 i = 0; i < (rounds*45); i++)
	{
		Backward_move();
	}
}
