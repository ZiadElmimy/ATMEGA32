
#ifndef DIO_H_
#define DIO_H_
#include "STD_Types.h"

typedef enum{
	PinA0 = 0,
	PinA1,
	PinA2,
	PinA3,
	PinA4,
	PinA5,
	PinA6,
	PinA7,
	PinB0,
	PinB1,
	PinB2,
	PinB3,
	PinB4,
	PinB5,
	PinB6,
	PinB7,
	PinC0,
	PinC1,
	PinC2,
	PinC3,
	PinC4,
	PinC5,
	PinC6,
	PinC7,
	PinD0,
	PinD1,
	PinD2,
	PinD3,
	PinD4,
	PinD5,
	PinD6,
	PinD7,
	total_pins = 32
}DIO_Pin;

typedef enum{
	PA,
	PB,
	PC,
	PD
}DIO_Port;

typedef enum{
	INFREE= 0,
	INPULLUP,
	OUTPUT
}DIO_Status;

typedef enum{
	LOW = 0,
	HIGH
}DIO_Voltage;

/**********************************************************DIO_FUNCTIONS********************************************************/
void DIO_PinInitialization(DIO_Pin pin, DIO_Status status);
void DIO_WritePin(DIO_Pin pin, DIO_Voltage volt);
DIO_Voltage DIO_ReadPin(DIO_Pin pin);

void DIO_PortInitialization(DIO_Port port, DIO_Status status);
void DIO_WritePort(DIO_Port port, u8 data);
u8 DIO_ReadPort(DIO_Port port);

extern DIO_Status config[total_pins];
void DIO_Initialization(void);
#endif /* DIO_H_ */