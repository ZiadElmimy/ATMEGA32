#include <avr/io.h>
#include "Servo.h"

void Servo_angle(u8 angle)
{
	 /*
	  *  0   ----> 1000
	  *  0  ---->  180
	  */

	ICR1 = 19999;
	OCR1A = (((u64)angle*1000)/180)+999;

}
