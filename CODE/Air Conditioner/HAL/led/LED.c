#include "LED.h"


/**DESCRIPTION:-
it intializes a pin to be an output pin
**/
LED_ERROR_TYPE LED_INIT(DIO_PIN_TYPE PIN)
{
	DIO_PIN_TYPE PIN_NUM;
	DIO_PORT_TYPE PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	if(PORT>4)
	{
		return INVALID_LED_PORT;
	}
	else if(PIN_NUM>32)
	{
		return INVLAID_LED_PIN_NUMBER;
	}
	else
	{
		DIO_INITPIN(PIN,OUTPUT);
		return VALID_LED;
	}
}
/**************************************************************************************************************************/
/**DESCRIPTION:-
it sets a certain pin with a high state so that the led will be on 
**/
LED_ERROR_TYPE LED_ON(DIO_PIN_TYPE PIN)
{
	DIO_PIN_TYPE PIN_NUM;
	DIO_PORT_TYPE PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	if(PORT>4)
	{
		return INVALID_LED_PORT;
	}
	else if(PIN_NUM>32)
	{
		return INVLAID_LED_PIN_NUMBER;
	}
	else
	{
		DIO_WRITEPIN(PIN,HIGH);
		return VALID_LED;
	}
}
/*************************************************************************************************************************/
/**DESCRIPTION:-
it sets a sertatin pin with a low voltage so that the led will be off
**/

LED_ERROR_TYPE LED_OFF(DIO_PIN_TYPE PIN)
{
	DIO_PIN_TYPE PIN_NUM;
	DIO_PORT_TYPE PORT;
	PORT=PIN/8;
	PIN_NUM=PIN%8;
	if(PORT>4)
	{
		return INVALID_LED_PORT;
	}
	else if(PIN_NUM>32)
	{
		return INVLAID_LED_PIN_NUMBER;
	}
	else
	{
		DIO_WRITEPIN(PIN,LOW);
		return VALID_LED;
	}
}