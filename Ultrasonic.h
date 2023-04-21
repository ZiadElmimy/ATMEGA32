#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "DIO.h"
#include "Timers.h"
#define Normal 0
#define CTC    1
#define Timer_Mode Normal

u16 Ultrasonic_GetDistance(DIO_Pin trig);

#endif /* ULTRASONIC_H_ */
