/*
 * keypad.h
 *
 * Created: 4/18/2023 6:10:25 AM
 *  Author: moham
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/*************************************************/
//					INCLUDES
/**************************************************/
#include "../../MCAL/dio/DIO.h"
#include "../../SERVICE/STD_TYPES.h"
#include <util/delay.h>
/*************************************************/
//					CONFIGURATIONS
/**************************************************/



// PINS
#define FIRST_ROW_PIN				pina0
#define LAST_ROW_PIN				pina2
#define FIRST_COL_PIN				pina3
#define LAST_COL_PIN				pina5

/**** KEYPAD DATA ******/

//ROW 0
#define  KEYPAD_ROW_0_COLUMN_0		'7'
#define  KEYPAD_ROW_0_COLUMN_1		'8'
#define  KEYPAD_ROW_0_COLUMN_2		'9'
#define  KEYPAD_ROW_0_COLUMN_3		'/'

//ROW 1
#define  KEYPAD_ROW_1_COLUMN_0		'4'
#define  KEYPAD_ROW_1_COLUMN_1		'5'
#define  KEYPAD_ROW_1_COLUMN_2		'6'
#define  KEYPAD_ROW_1_COLUMN_3		'*'

//ROW 2
#define  KEYPAD_ROW_2_COLUMN_0		'1'
#define  KEYPAD_ROW_2_COLUMN_1		'2'
#define  KEYPAD_ROW_2_COLUMN_2		'3'
#define  KEYPAD_ROW_2_COLUMN_3		'-'

//ROW 3
#define  KEYPAD_ROW_3_COLUMN_0		'A'
#define  KEYPAD_ROW_3_COLUMN_1		'0'
#define  KEYPAD_ROW_3_COLUMN_2		'='
#define  KEYPAD_ROW_3_COLUMN_3		'+'


/*************************************************/
//					DEFIENS
/**************************************************/


typedef enum {
	COL_0 = FIRST_COL_PIN,
	COL_1,
	COL_2,
	COL_3,
	}COLUMN;

typedef enum {
	ROW_0,
	ROW_1,
	ROW_2,
	ROW_3,
}ROW;

/*************************************************/
//			FUNCTIONS PROTOTYPES
/**************************************************/
void KEYPAD_init(void);
uint8_t KEYPAD_getKey(void);

#endif /* KEYPAD_H_ */