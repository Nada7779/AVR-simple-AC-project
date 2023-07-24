
#ifndef memorymap_H_
#define memorymap_H_
#include "../SERVICE/std_types.h"

/********************************************DIO MAPING************************	********/
#define DDRA (*(volatile uint8_t*)0x3A)
#define DDRB (*(volatile  uint8_t*)0x37)
#define DDRC (*(volatile uint8_t*)0x34)
#define DDRD (*(volatile uint8_t*)0x31)


#define PINA (*(volatile uint8_t*)0x39)
#define PINB (*(volatile uint8_t*)0x36)
#define PINC (*(volatile uint8_t*)0x33)
#define PIND (*(volatile uint8_t*)0x30)


#define PORTA (*(volatile uint8_t*)0x3B)
#define PORTB (*(volatile uint8_t*)0x38)
#define PORTC (*(volatile uint8_t*)0x35)
#define PORTD (*(volatile uint8_t*)0x32)

/******************************EXT INTERRUPT MAPPING**************************************/

#define MCUCSR  (*(volatile uint8_t*)0X54)
#define MCUCR  (*(volatile uint8_t*)0X55)
#define GICR  (*(volatile uint8_t*)0X5B)
/*************interrupt registers pin macro*/
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2  6
#define INT0 6
#define INT1 7
#define INT2 5
/****data sheet attributes to enable context switching and to enable global interrupt*/
#define INT0_vect	 __vector_1
#define INT1_vect	 __vector_2
#define INT2_vect	 __vector_3
#define TIMER2_OVF	 __vector_5

#define sei() __asm__ __volatile__("sei" ::: "memory")
#define cli() __asm__ __volatile__("cli" ::: "memory")

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)



/*****************************************TIMER MAPING*************************************/
/***************************** TIMER_0 ******************************/
#define TCNT0   (*(volatile uint8_t*)0x52)
#define TCCR0   (*(volatile uint8_t*)0x53)
#define TIMSK   (*(volatile uint8_t*)0x59)
#define GIFR    (*(volatile uint8_t*)0x5A)
#define TIFR    (*(volatile uint8_t*)0x58)
#define OCR0    (*(volatile uint8_t*)0x5C)
/**TCCR0**/
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7
/*************/

/***TIMSK**/
#define TOIE0 0
#define OCIE0 1
/**************/

/**GIFR**/


/*********/

/**TIFR**/
#define TOV0 0
#define OCF0 1
/**************/

/***************************** TIMER_2 ******************************/
#define TCCR2   (*(volatile uint8_t*)0x45)
#define TCNT2   (*(volatile uint8_t*)0x44)


/**TCCR2**/
#define CS20	0
#define CS21	1
#define CS22	2
#define WGM21	3
#define COM20	4
#define COM21	5
#define WGM20	6
#define FOC2	7
      
/**TIFR**/
#define TOV2 6

/***** TIMSK***/
#define TOIE2 6

/*************************************ADC MAPPING**************************************/

#define ADMUX     *((volatile uint8_t*)0x27)
#define ADCSRA    *((volatile uint8_t*)0x26)
#define ADCL      *((volatile uint8_t*)0x24)
#define ADCH      *((volatile uint8_t*)0x25)
#define ADCLH     *((volatile unsigned short int*)0x24) // use this when we use right method to read high and low bits
#define SFIOR     *((volatile uint8_t*)0x50)

#endif /* memorymap_H_ */