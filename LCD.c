#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#if(LCD_mode == _8_bit_mode)
void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	DIO_WritePort(LCD_port,command);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	DIO_WritePort(LCD_port,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_initialization(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38); //set the LCD on 8 bits mode
	_delay_ms(5);
	LCD_WriteCommand(0x0C); //the display is on and the cursor doesn't appear
	_delay_ms(5);
	LCD_WriteCommand(0x01); //clear the display
	_delay_ms(5);
	LCD_WriteCommand(0x06); //the cursor increases and there is no shift
	_delay_ms(1);
}


#elif(LCD_mode == _4_bit_mode)
void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	DIO_WritePin(data_0,((command>>4)&1));
	DIO_WritePin(data_1,((command>>5)&1));
	DIO_WritePin(data_2,((command>>6)&1));
	DIO_WritePin(data_3,((command>>7)&1));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(data_0,((command>>0)&1));
	DIO_WritePin(data_1,((command>>1)&1));
	DIO_WritePin(data_2,((command>>2)&1));
	DIO_WritePin(data_3,((command>>3)&1));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	DIO_WritePin(data_0,((data>>4)&1));
	DIO_WritePin(data_1,((data>>5)&1));
	DIO_WritePin(data_2,((data>>6)&1));
	DIO_WritePin(data_3,((data>>7)&1));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(data_0,((data>>0)&1));
	DIO_WritePin(data_1,((data>>1)&1));
	DIO_WritePin(data_2,((data>>2)&1));
	DIO_WritePin(data_3,((data>>3)&1));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_initialization(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	_delay_ms(1);
	LCD_WriteCommand(0x28); //set the LCD on 4 bits mode
	_delay_ms(5);
	LCD_WriteCommand(0x0C); //the display is on and the cursor doesn't appear
	_delay_ms(5);
	LCD_WriteCommand(0x01); //clear the display
	_delay_ms(5);
	LCD_WriteCommand(0x06); //the cursor increases and there is no shift
	_delay_ms(1);
}

#endif
/***********************************************************************/
void LCD_Cursor(u8 x, u8 y)
{
	u8 address = 0x80;
	if(y == 0)
	address = 0x80;
	else if(y == 1)
	address = 0xC0;
	address += x;
	if(x < 16)
	LCD_WriteCommand(address);
	_delay_ms(1);
}

void LCD_WriteChar(u8 data)
{
	LCD_WriteData(data);
}

void LCD_WriteString(u8 *str)
{
	u8 i = 0;
	while(str[i])
		LCD_WriteData(str[i++]);
}

void LCD_WriteNum(s64 num) //1200
{
	u8 rem = 0, arr[16] = {0}, i = 0;
	if(num == 0)
	  LCD_WriteData('0');
	else
	{
		if(num < 0)
		{
		   LCD_WriteData('-');
		   num = num * -1;
		}
		while(num > 0)
		{
			rem = num%10;
			arr[i++] = rem;
			num /= 10;
		}
		for(u8 count = i; count > 0; count--)
		{
			LCD_WriteData(arr[count-1]+'0');
		}
		
	}  
}

void LCD_WriteNum_5D(u16 num)
{
	LCD_WriteData(((num%100000)/10000)+'0');
	LCD_WriteData(((num%10000)/1000)+'0');
	LCD_WriteData(((num%1000)/100)+'0');
	LCD_WriteData(((num%100)/10)+'0');
	LCD_WriteData(((num%10)/1)+'0');
}

void LCD_WriteNum_Binary(u16 num)
{
	u8 rem = 0, arr[16] = {0}, i = 0;
	if(num == 0)
	   LCD_WriteData('0');
	else
	{
		while(num > 0)
		{
			rem = num%2;
			arr[i++] = rem;
			num /= 2;
		}
		for(u8 count = i; count > 0; count--)
		{
			LCD_WriteData(arr[count-1] + '0');
		}
	}   	
}
