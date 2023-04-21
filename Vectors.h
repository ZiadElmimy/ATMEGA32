#ifndef VECTORS_H_
#define VECTORS_H_

#define RESET_Vector  __vector_0
#define INT0_Vector   __vector_1
#define INT1_Vector   __vector_2
#define INT2_Vector   __vector_3
#define TIMER2_COMP_Vector     __vector_4
#define TIMER2_OVF_Vector      __vector_5
#define TIMER1_CAP_Vector      __vector_6
#define TIMER1_COMA_Vector     __vector_7
#define TIMER1_COMB_Vector     __vector_8
#define TIMER1_OVF_Vector      __vector_9
#define TIMER0_COMP_Vector     __vector_10
#define TIMER0_OVF_Vector       __vector_11
#define SPI_STC_Vector         __vector_12
#define USART_RXC_Vector       __vector_13
#define USART_UDRE_Vector      __vector_14
#define USART_TXC_Vector       __vector_15
#define ADC_Vector             __vector_16
#define EEPROM_Vector          __vector_17
#define ANALOG_COMP_Vector     __vector_18
#define TWI_Vector             __vector_19
#define SPM_Vector             __vector_20


#define ISR(Vector)  void Vector (void) __attribute__((signal));\
void Vector (void)

#define sei() __asm__ __volatile__ ("sei"::)
#define cli() __asm__ __volatile__ ("cli"::)


#endif /* VECTORS_H_ */