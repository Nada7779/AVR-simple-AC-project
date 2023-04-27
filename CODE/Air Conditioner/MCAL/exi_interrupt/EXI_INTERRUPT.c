#include "EXI_INTERRUPT.h"

static void (*ptrf_INT_0)(void)=NULL;
static void (*ptrf_INT_1)(void)=NULL;
static void (*ptrf_INT_2)(void)=NULL;

uint8_t car_flag =0  ;
/*****************************************************************************************************************/

/**DESCRIPTION:-
it enables one of the external interrupt
*/
EN_int__error_t EXI_Enable (EN_int_t Interrupt)
{
	switch (Interrupt)
	{
		case EXT_INT_0:
		set_bit(GICR,INT0);
		break;
		case EXT_INT_1:
		set_bit(GICR,INT1);
		break;
		case EXT_INT_2:
		set_bit(GICR,INT2);
		break;
	}
}
/***********************************************************************************************************************/

/**DESCRIPTION:-
it disables one of the external interrupt
*/

EN_int__error_t EXI_Disable (EN_int_t Interrupt)
{
	switch (Interrupt)
	{
		case EXT_INT_0:
		clear_bit(GICR,INT0);
		break;
		case EXT_INT_1:
		clear_bit(GICR,INT1);
		break;
		case EXT_INT_2:
		clear_bit(GICR,INT2);
		break;
	}
}
/***************************************************************************************************************/

/**DESCRIPTION:-
it give you the ability to choose between different triggers 
*/

EN_int__error_t EXI_Trigger(EN_int_t Interrupt,EN_trig trigger)
{
	
	switch(Interrupt)
	{
		case EXT_INT_0:
		switch(trigger)
		{
			case LOW_LEVEL:
			clear_bit(MCUCR,ISC00);
			clear_bit(MCUCR,ISC01);
			break;
			case ANY_LOGIC_CHANGE:
			set_bit(MCUCR,ISC00);
			clear_bit(MCUCR,ISC01);
			break;
			case FALLING_EDGE:
			clear_bit(MCUCR,ISC00);
			set_bit(MCUCR,ISC01);
			break;
			case RISING_EDGE:
			set_bit(MCUCR,ISC00);
			set_bit(MCUCR,ISC01);
			break;
		}
		break;
		case EXT_INT_1:
		switch(trigger)
		{
			case LOW_LEVEL:
			clear_bit(MCUCR,ISC10);
			clear_bit(MCUCR,ISC11); break;
			case ANY_LOGIC_CHANGE:
			set_bit(MCUCR,ISC10);
			clear_bit(MCUCR,ISC11); break;
			case FALLING_EDGE:
			clear_bit(MCUCR,ISC10);
			set_bit(MCUCR,ISC11); break;
			case RISING_EDGE:
			set_bit(MCUCR,ISC10);
			set_bit(MCUCR,ISC11); break;
		}
		break;
		case EXT_INT_2:
		switch(trigger)
		{
			case FALLING_EDGE:
			clear_bit(MCUCSR,ISC2);
			break;
			case RISING_EDGE:
			set_bit(MCUCSR,ISC2);
			break;
		}
		break;
	}
}
/********************************************************************************************************************/

/**DESCRIPTION:-
it instruct the interrupt ISR to perform a specific function by passing the function
*/


void EXI_SetCallBack(EN_int_t Interrupt,void(*ptrf)(void))
{
	switch (Interrupt)
	{
		case EXT_INT_0:
		ptrf_INT_0 =ptrf;
		break;
		case EXT_INT_1:
		ptrf_INT_1 =ptrf;
		break;
		case EXT_INT_2:
		ptrf_INT_2 =ptrf;
		break;
	}
}
/*******************************************************ISR INT_0********************************************************/


ISR (INT0_vect)
{
	car_flag = 0;
	if (ptrf_INT_0 != NULL)
	{
		ptrf_INT_0();
		
		DIO_WRITEPIN(pinc0,LOW);
		DIO_WRITEPIN(pinc1,LOW);
		DIO_WRITEPIN(pinc2,LOW);
		DIO_WRITEPIN(pinc3,LOW);
		
	}
}

ISR (INT1_vect)
{
	if (ptrf_INT_1 != NULL)
	{
		//ptrf_INT_1();
		
	}
	car_flag = 1 ;
}

ISR (INT2_vect)
{
	if (ptrf_INT_2 != NULL)
	{
		ptrf_INT_2();
	}
}