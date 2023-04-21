#include "Keypad.h"

static u8 Keys_array[4][4] = {{'7','8','9','/'},
                              {'4','5','6','*'},
							  {'1','2','3','-'},
							  {'C','0','=','+'}};

u8 Keypad_Entry(void)
{
	u8 key = default_key;
	DIO_WritePin(Keypad_col_Pin,HIGH);
	DIO_WritePin(Keypad_col_Pin+1,HIGH);
	DIO_WritePin(Keypad_col_Pin+2,HIGH);
	DIO_WritePin(Keypad_col_Pin+3,HIGH);
	for(u8 c = 0; c < 4; c++)
	{
		DIO_WritePin(Keypad_col_Pin+c,LOW);
		for(u8 r = 0; r < 4; r++)
		{
			if(!DIO_ReadPin(Keypad_raw_Pin+r))
			{
				key = Keys_array[r][c];
				while(!DIO_ReadPin(Keypad_raw_Pin+r));
			}
		}
		DIO_WritePin(Keypad_col_Pin+c,HIGH);
	}
	return key;
}


