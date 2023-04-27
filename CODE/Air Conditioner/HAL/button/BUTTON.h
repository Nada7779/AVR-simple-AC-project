
#ifndef button_H_
#define button_H_
/**********************includes**********************************************/
#include "../../MCAL/DIO/DIO.h"
/*****************************************************************************/

/*****************************enums********************************************/
typedef enum {
	VALID_BUTTON,
	INVALID_BUTTON_PORT,
	INVALID_BUTTON_PIN_NUMBER
}BUTTON_ERROR_TYPE;

/************************func_prototypes*************************************/

BUTTON_ERROR_TYPE Button_INIT(DIO_PIN_TYPE PIN);
BUTTON_ERROR_TYPE Button_read(DIO_PIN_TYPE PIN,DIO_VOLTAGE_TYPE*VOLT);





#endif /* button_H_ */