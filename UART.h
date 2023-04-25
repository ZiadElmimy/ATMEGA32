#ifndef UART_H_
#define UART_H_
#include "Vectors.h"
#include "STD_Types.h"

//set the baud rate for the UART
/*
 *for 8MHz frequancy Normal speed
 * 2400bps --> 207
 * 4800bps --> 103
 * 9600bps --> 51
 * 14400bps --> 34
 * 19200bps --> 25
 * 38400bps --> 12
 * 76800bps --> 6
 * 250k bps --> 1
 * 05M bps --> 0
 *for 8MHz fequancy Double speed
 * 2400bps --> 416
 * 4800bps --> 207
 * 9600bps --> 103
 * 14400bps --> 68
 * 19200bps --> 51
 * 28800bps --> 34
 * 38400bps --> 25
 * 76800bps --> 12
 * 250k bps --> 3
 * 05M bps --> 1
 * 1M bps --> 0
 */
#define Baud_Rate 51

typedef enum{
	   Asynchronous,
	   Synchronous
}UART_mode;

typedef enum{
       Normal_speed,
	   Double_speed
}UART_speed;
typedef enum{
       Disabled,
	   Even_Parity,
	   Odd_Parity
}UART_parity;

typedef enum{
       Stop_1,
	   Stop_2
}UART_stop;

typedef enum{
       _5_bits,
	   _6_bits,
	   _7_bits,
	   _8_bits ,
	   _9_bits
}UART_databits;

void UART_Initialization(UART_mode mode, UART_speed speed, UART_parity parity, UART_stop stop, UART_databits data);
void UART_Send(u8 data);
u8 UART_Receive(void);
void UART_SendString(u8 *str);
void UART_ReceiveString(u8 *str);
void UART_SendInt(u32 num);
u32 UART_ReceiveInt(void);
void UART_SendString_CS(u8 *str);
u8 UART_ReceiveString_CS(u8 *str);
#endif /* UART_H_ */
