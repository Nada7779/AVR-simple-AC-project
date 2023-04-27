/*
 * keypad.c
 *
 * Created: 4/18/2023 6:10:37 AM
 *  Author: Kareem
 */ 
#include "keypad.h"


/************************************************ KEYPAD_init **********************************************************************************/
/* Description:
- Function used to initialize the rows pins of keypad as output and set them high and initialize the columns pins of keypad as  input pullup
- FIRST_ROW_PIN , LAST_ROW_PIN ,FIRST_COL_PIN , LAST_COL_PIN are used to define the keypad dimensions and can be changed in configurations
************************************************************************************************************************************************/

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



/************************************************ KEYPAD_getKey **********************************************************************************/
/* Description:
- Function used to return the data of the pressed key
- data can be changed in configurations
*************************************************************************************************************************************************/

uint8_t KEYPAD_getKey(){
	
	uint8_t a_col_state =1 ;
	uint8_t  a_keychar ;
	
	//loop for rows
	for (uint8_t a_rows = FIRST_ROW_PIN ; a_rows <= LAST_ROW_PIN ; a_rows ++)
	{
		
		DIO_WRITEPIN(a_rows,LOW);
		_delay_ms(20);
		
		//loop  for columns
		for(uint8_t a_cols = FIRST_COL_PIN ; a_cols <= LAST_COL_PIN ; a_cols++){
			DIO_READPIN(a_cols,&a_col_state);
	
			while(a_col_state == 0){
				DIO_READPIN(a_cols,&a_col_state);
				
				//check the pressed row
				switch(a_rows){
				
					case ROW_0 :
						
						//check the pressed column
						switch(a_cols){
							
							case COL_0 :
							a_keychar = KEYPAD_ROW_0_COLUMN_0 ;
							break;
							
							case COL_1 :
							a_keychar = KEYPAD_ROW_0_COLUMN_1;
							break;
							
							case COL_2 :
							a_keychar = KEYPAD_ROW_0_COLUMN_2;
							break;
							
							case COL_3 :
							a_keychar = KEYPAD_ROW_0_COLUMN_3;
							break;
							
						}
						
				  break ;
						
						
						
				  case ROW_1 :
					//check the pressed column
					switch(a_cols){
							
							case COL_0 :
							a_keychar= KEYPAD_ROW_1_COLUMN_0 ;
							break;
							
							case COL_1 :
							a_keychar = KEYPAD_ROW_1_COLUMN_1;
							break;
							
							case COL_2 :
							a_keychar= KEYPAD_ROW_1_COLUMN_2;
							break;
							
							case COL_3 :
							a_keychar = KEYPAD_ROW_1_COLUMN_3;
							break;
							
						}
						
				  break ;
						
						
						
						
						
				  case ROW_2 :
						
					//check the pressed column
					switch(a_cols){
							
							case COL_0 :
							a_keychar= KEYPAD_ROW_2_COLUMN_0 ;
							break;
							
							case COL_1 :
							a_keychar = KEYPAD_ROW_2_COLUMN_1;
							break;
							
							case COL_2 :
							a_keychar= KEYPAD_ROW_2_COLUMN_2;
							break;
							
							case COL_3 :
							a_keychar = KEYPAD_ROW_2_COLUMN_3;
							break;
							
						}
						
				  break ;
						
						
						
						
				  case ROW_3 :
						
					//check the pressed column
				   switch(a_cols){
							
							case COL_0 :
							a_keychar= KEYPAD_ROW_3_COLUMN_0 ;
							break;
							
							case COL_1 :
							a_keychar = KEYPAD_ROW_3_COLUMN_1;
							break;
							
							case COL_2 :
							a_keychar= KEYPAD_ROW_3_COLUMN_2;
							break;
							
							case COL_3 :
							a_keychar = KEYPAD_ROW_3_COLUMN_3;
							break;
							
						}
						
			break ;
						
						

			// no press			
			default: 
			a_keychar = 0;
			break;
					
				
				}	
				
				
				}
			
		}
		
		
		DIO_WRITEPIN(a_rows,HIGH);
		
	}
	
	return a_keychar ;
}