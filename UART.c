#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

void UART_Initialization(UART_mode mode, UART_speed speed, UART_parity parity, UART_stop stop, UART_databits data)
{
	//choose the mode of the uart peripheral
#if(mode == Asynchronous)
        UCSRC &= ~(1<<UMSEL);
#elif(mode == Synchronous)
		UCSRC |= (1<<UMSEL);
#endif

	//choose the speed of transmission
#if(speed == Normal_speed)
		UCSRA &= ~(1<<U2X);
#elif(speed == Double_speed)
		UCSRA |= (1<<U2X);
#endif

   //choose the number of parity bits
#if(parity == Disabled)
        UCSRC &= ~(1<<UPM1);
        UCSRC &= ~(1<<UPM0);
#elif(parity == Even_Parity)
		UCSRC &= ~(1<<UPM1);
		UCSRC |= (1<<UPM0);
#elif(parity == Odd_Parity)
		UCSRC |= (1<<UPM1);
		UCSRC |= (1<<UPM0);
#endif

	//choose the number of stop bits

#if(stop == Stop_1)
		UCSRC &= ~(1<<USBS);
#elif(stop == Stop_2)
        UCSRC |= (1<<USBS);
#endif

	//choose the number of data bits

#if(data ==  _5_bits)
		UCSRB &= ~(1<<UCSZ2);
		UCSRC &= ~(1<<UCSZ1);
		UCSRC &= ~(1<<UCSZ0);
#elif(data == _6_bits)
		UCSRB &= ~(1<<UCSZ2);
		UCSRC &= ~(1<<UCSZ1);
		UCSRC |= (1<<UCSZ0);
#elif(data == _7_bits)
		UCSRB &= ~(1<<UCSZ2);
		UCSRC |= (1<<UCSZ1);
		UCSRC &= ~(1<<UCSZ0);
#elif(data == _8_bits)
		UCSRB &= ~(1<<UCSZ2);
		UCSRC |= (1<<UCSZ1);
		UCSRC |= (1<<UCSZ0);
#elif(data == _9_bits)
		UCSRB |= (1<<UCSZ2);
		UCSRC |= (1<<UCSZ1);
		UCSRC |= (1<<UCSZ0);
#endif

	//set the baud rate
	UBRRL = Baud_Rate;

	//enable the tx and rx
	UCSRB |= (1<<TXEN);
	UCSRB |= (1<<RXEN);
}

void UART_Send(u8 data)
{
	while(!((UCSRA>>UDRE)&1));
	UDR = data;
}

u8 UART_Receive(void)
{
	volatile static u8 data;
    while(!((UCSRA>>RXC)&1));
    data = UDR;
    return data;
}

void UART_SendString(u8 *str)
{
	static u8 i = 0;
   while(str[i])
   {
	   UART_Send(str[i++]);
   }
   UART_Send('\n');
}

void UART_ReceiveString(u8 *str)
{
   u8 i = 0;
   str[i] = UART_Receive();
   while(str[i] != '\n')
   {
      str[++i] = UART_Receive();
   }
   str[i] ='\0';
}

void UART_SendInt(u32 num)
{
   UART_Send(num);
   UART_Send(num>>8);
   UART_Send(num>>16);
   UART_Send(num>>24);
}

u32 UART_ReceiveInt(void)
{
   u32 num;
   u8 byte_1 = UART_Receive();
   u8 byte_2 = UART_Receive();
   u8 byte_3 = UART_Receive();
   u8 byte_4 = UART_Receive();
   num = byte_1 | ((u32)byte_2<<8) | ((u32)byte_3<<16) | ((u32)byte_4<<24);
   return num;
}

void UART_SendString_CS(u8 *str)
{
    static u8 i = 0; u16 sum = 0;
    while(str[i])
    {
        sum += str[i++];
    }
    UART_Send(sum);
    UART_Send(sum>>8);
    i = 0;
    while(str[i])
    {
    	UART_Send(str[i++]);
    }
    UART_Send('\n');
}

u8 UART_ReceiveString_CS(u8 *str)
{
	static u16 sum = 0, check = 0;
	static u8 i = 0;
	u8 sum_0 = UART_Receive();
	u8 sum_1 = UART_Receive();
	sum = sum_0 | (u16)sum_1<<8;
	str[0] = UART_Receive();
    while(str[i]!= '\n')
    {
    	check += str[i];
    	str[++i] = UART_Receive();
    }
    str[i] = '\0';
    if(sum == check)
    	return 1;
    else
    	return 0;
}

