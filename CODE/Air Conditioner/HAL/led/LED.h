
#ifndef led_H_
#define led_H_
/***************************includes**************************************/
#include "../../MCAL/DIO/DIO.h"
/*************************************************************************/


/****************************enums****************************************/
typedef enum {
	VALID_LED,
	INVALID_LED_PORT,
	INVLAID_LED_PIN_NUMBER
}LED_ERROR_TYPE;
/*********************************************************************/

/**********************func_prototypes********************************/
LED_ERROR_TYPE LED_INIT(DIO_PIN_TYPE PIN);
LED_ERROR_TYPE LED_ON(DIO_PIN_TYPE PIN);
LED_ERROR_TYPE LED_OFF(DIO_PIN_TYPE PIN);





#endif /* led_H_ */