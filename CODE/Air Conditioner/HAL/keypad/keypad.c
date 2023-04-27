/*
 * keypad.c
 *
 * Created: 4/18/2023 6:10:37 AM
 *  Author: moham
 */ 
#include "keypad.h"


void KEYPAD_init(void){
	
	for (uint8_t row_pins = FIRST_ROW_PIN ; row_pins <= LAST_ROW_PIN ; row_pins++)
	{
		DIO_INITPIN(row_pins,OUTPUT);
		DIO_WRITEPIN(row_pins,HIGH);
	}
	
	for (uint8_t col_pins = FIRST_COL_PIN ; col_pins <= LAST_COL_PIN ; col_pins++)
	{
		DIO_INITPIN(col_pins,INPLUP);
		

	}
	
	
}





uint8_t KEYPAD_getKey(){
	
	uint8_t col_state =1 ;
	uint8_t  keychar ;
	for (uint8_t rows = FIRST_ROW_PIN ; rows <= LAST_ROW_PIN ; rows ++)
	{
		
		DIO_WRITEPIN(rows,LOW);
		_delay_ms(20);
		
		for(uint8_t cols = FIRST_COL_PIN ; cols <= LAST_COL_PIN ; cols++){
			DIO_READPIN(cols,&col_state);
	
			while(col_state == 0){
				DIO_READPIN(cols,&col_state);
				
				
				switch(rows){
				
					case ROW_0 :
						
						switch(cols){
							
							case COL_0 :
							keychar= KEYPAD_ROW_0_COLUMN_0 ;
							break;
							
							case COL_1 :
							keychar = KEYPAD_ROW_0_COLUMN_1;
							break;
							
							case COL_2 :
							keychar= KEYPAD_ROW_0_COLUMN_2;
							break;
							
							case COL_3 :
							keychar = KEYPAD_ROW_0_COLUMN_3;
							break;
							
						}
						
				  break ;
						
						
						
				  case ROW_1 :
						
					switch(cols){
							
							case COL_0 :
							keychar= KEYPAD_ROW_1_COLUMN_0 ;
							break;
							
							case COL_1 :
							keychar = KEYPAD_ROW_1_COLUMN_1;
							break;
							
							case COL_2 :
							keychar= KEYPAD_ROW_1_COLUMN_2;
							break;
							
							case COL_3 :
							keychar = KEYPAD_ROW_1_COLUMN_3;
							break;
							
						}
						
				  break ;
						
						
						
						
						
				  case ROW_2 :
						
					switch(cols){
							
							case COL_0 :
							keychar= KEYPAD_ROW_2_COLUMN_0 ;
							break;
							
							case COL_1 :
							keychar = KEYPAD_ROW_2_COLUMN_1;
							break;
							
							case COL_2 :
							keychar= KEYPAD_ROW_2_COLUMN_2;
							break;
							
							case COL_3 :
							keychar = KEYPAD_ROW_2_COLUMN_3;
							break;
							
						}
						
				  break ;
						
						
						
						
				  case ROW_3 :
						
				   switch(cols){
							
							case COL_0 :
							keychar= KEYPAD_ROW_3_COLUMN_0 ;
							break;
							
							case COL_1 :
							keychar = KEYPAD_ROW_3_COLUMN_1;
							break;
							
							case COL_2 :
							keychar= KEYPAD_ROW_3_COLUMN_2;
							break;
							
							case COL_3 :
							keychar = KEYPAD_ROW_3_COLUMN_3;
							break;
							
						}
						
			break ;
						
						

						
			default: 
			keychar = 0;
			break;
					
				
				}	
				
				
				}
			
		}
		
		
		DIO_WRITEPIN(rows,HIGH);
		
	}
	
	return keychar ;
}