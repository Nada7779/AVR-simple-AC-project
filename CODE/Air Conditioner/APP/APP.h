﻿
#ifndef app_H_
#define app_H_



/*****************************************************************************************************************************************************************
*									Includes																				 *
******************************************************************************************************************************************************************/
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMERS/timer.h"
#include "../HAL/lcd/LCD.h"
#include "../HAL/keypad/keypad.h"
#include "../MCAL/adc/adc.h"
#include "../HAL/buzzer/buzzer.h"



/*****************************************************************************************************************************************************************
*									defines																			 *
******************************************************************************************************************************************************************/
typedef enum {
	STARTING ,
	ADJUST_STAGE ,
	SETTED_STAGE ,
	READJUST_STAGE,
	RESET_STAGE
}stages;

#define INCREMENT	 '1'
#define DECREMENT	 '2'
#define SET			 '3'
#define ADJUST		 '4'
#define RESET		 '5'

#define MAX		   	35
#define MIN			18



extern uint8_t flag_stage ;
extern uint8_t g_flagTimer ;
extern uint8_t g_tempValue ; // default value

/*****************************************************************************************************************************************************************
*									Functions prototypes																			 *
******************************************************************************************************************************************************************/
void Start(void);
void adjust_Welcome(void);
void adjust_stage(void);
/************************************************set_stage************************************************************************************/
/* Description:
function used once Once button_3 is pressed the temperature is set and LCD display current temp
and display buzzer shape if temperature > set temperature & buzzer ON
***********************************************************************************************************************************************/
void set_stage(void);
/************************************************LM35_read************************************************************************************/
/* Description:
function used to start reading the LM35 temperature and display its value on the LCD
***********************************************************************************************************************************************/
uint16 LM35_read (void);
/************************************************radjust_stage**********************************************************************************/
/* Description:
function used once button_4 is press to go back to adjust mode and stop buzzer if it was working
***********************************************************************************************************************************************/
void readjust_stage (void);
/************************************************reset_stage**********************************************************************************/
/* Description:
function used once button_5 is press to  reset temperature to its default
*********************************************************************************************************************************************/
void reset_stage (void);



void app_Start(void);
void app_Init(void);


#endif








