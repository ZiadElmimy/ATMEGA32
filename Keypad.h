#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO.h"

#define Keypad_raw_Pin PinD0 //input
#define Keypad_col_Pin PinC4 //output
#define default_key '.'

u8 Keypad_Entry(void);


#endif /* KEYPAD_H_ */
