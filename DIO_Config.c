#include "DIO.h"

DIO_Status config[total_pins] = {
	       OUTPUT, //PINA0
		   OUTPUT, //PINA1
		   OUTPUT, //PINA2
		   OUTPUT, //PINA3
		   OUTPUT, //PINA4
		   OUTPUT, //PINA5
		   OUTPUT, //PINA6
		   OUTPUT, //PINA7
		   OUTPUT, //PINB0
		   OUTPUT, //PINB1
		   OUTPUT, //PINB2/ INT2
		   OUTPUT, //PINB3/ OC0
		   OUTPUT, //PINB4
		   OUTPUT, //PINB5
		   OUTPUT, //PINB6
		   OUTPUT, //PINB7
		   OUTPUT, //PINC0
		   OUTPUT, //PINC1
		   OUTPUT, //PINC2
		   OUTPUT, //PINC3
		   OUTPUT, //PINC4
		   OUTPUT, //PINC5
		   OUTPUT, //PINC6
		   OUTPUT, //PINC7
		   OUTPUT, //PIND0
		   OUTPUT, //PIND1
		   OUTPUT, //PIND2/ INT0
		   OUTPUT, //PIND3/ INT1
		   OUTPUT, //PIND4/ OC1A
		   OUTPUT, //PIND5/ OC1B
		   INFREE, //PIND6
		   OUTPUT  //PIND7
};
