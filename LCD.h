#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"

#define _8_bit_mode  0
#define _4_bit_mode  1
#define LCD_mode _4_bit_mode
#define RS PinC0
#define RW PinC1
#define EN PinC2
#if(LCD_mode == _8_bit_mode)
#define LCD_port PD
#elif(LCD_mode == _4_bit_mode)
#define data_0   PinA0
#define data_1   PinA1
#define data_2   PinA2
#define data_3   PinA3
#endif

void LCD_initialization(void);
void LCD_Cursor(u8 x, u8 y);
void LCD_WriteData(u8 data);
void LCD_WriteCommand(u8 command);
void LCD_WriteChar(u8 data);
void LCD_WriteString(u8 *str);
void LCD_WriteNum(s64 num);
void LCD_WriteNum_5D(u16 num);
void LCD_WriteNum_Binary(u16 num);
#endif /* LCD_H_ */
