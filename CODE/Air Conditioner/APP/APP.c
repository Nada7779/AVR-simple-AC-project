#include "APP.h"

/***********************************************************************************************************************
                                    GLOBAL VARIABLES 
*****************************************************************************************************************************/
uint8_t g_tempValue = 20 ; // default value

uint8_t g_flagStage ;
uint8_t g_flagTimer ;
/***********************************************************************************************************************
                                   FUNCTION IMPLMENTATION
****************************************************************************************************************************/

void adjust_Welcome(void){

	LCD_GoTo(1,0);
	LCD_Write_String("MAX TEMP IS 35");
	LCD_GoTo(2,0);
	LCD_Write_String("MIN TEMP IS 18");
	TIMER_0_DELAY_MS(500);
	LCD_Clear();
	
	
	LCD_GoTo(1,0);
	LCD_Write_String("PLEASE CHOOSE ");
	LCD_GoTo(2,0);
	LCD_Write_String("REQUIRED TEMP ");
	TIMER_0_DELAY_MS(500);
	LCD_Clear();
}


void adjust_stage(void){
uint8_t key = 0;
	 while (key != '3' && g_flagStage != 2)
	 {
		key = KEYPAD_getKey() ;
		TIMER_0_DELAY_MS(50);
			switch(key){
				case '1' :
				g_tempValue++;
				g_flagTimer = 0;
				break;
				
				case '2' :
				g_tempValue--;
				LCD_Clear();
				g_flagTimer = 0;
				break;
				
				default :
				g_flagTimer = 1;
				break;
				
			}
	
			
			LCD_GoTo(1,7);
			LCD_Write_Number(g_tempValue);
			LCD_GoTo(2,0);
			for (uint8_t i= 18 ; i <= g_tempValue ; i++)
			{
				LCD_Write_Charecter('|');
			}
			
	
	}
	g_flagStage = 2 ;
}
/************************************************set_stage************************************************************************************/
/* Description:
function used once Once button_3 is pressed the temperature is set and LCD display current temp
and display buzzer shape if temperature > set temperature & buzzer ON
***********************************************************************************************************************************************/
void set_stage(void){
LCD_Clear();
uint8_t a_key = 0;
while (a_key != '4' && a_key != '5')
{
	a_key = KEYPAD_getKey() ;
	TIMER_0_DELAY_MS(50);
	unsigned short int curreunt_temp = LM35_read();
	if (curreunt_temp > g_tempValue) buzzer_On();
	else buzzer_Off();
	if (a_key=='1' || a_key=='2') //after set mode all buttons are not allowed except button_4 and button_5
	{
		LCD_Clear();
		LCD_Write_String("the operation is");
		LCD_GoTo(2,1);
		LCD_Write_String("not allowed");
		TIMER_0_DELAY_MS(500);
		LCD_Clear();
	}
}
LCD_Clear();
if (a_key == '4') g_flagStage = 3;
else if (a_key == '5') g_flagStage = 4;
}
/************************************************LM35_read************************************************************************************/
/* Description:
function used to start reading the LM35 temperature and display its value on the LCD
***********************************************************************************************************************************************/
uint16 LM35_read (void)
{
	uint16 a_temp_celus;
	ADC_start_conversion (ADC_CH_6);
	LCD_GoTo(1,2);
	LCD_Write_String("current temp =");
	LCD_GoTo(2,2);
	a_temp_celus = ADC_LM35_calibration();
	LCD_Write_Number(a_temp_celus);
	return a_temp_celus;
}
/************************************************radjust_stage**********************************************************************************/
/* Description:
function used once button_4 is press to go back to adjust mode and stop buzzer if it was working
***********************************************************************************************************************************************/
void readjust_stage (void)
{
	LCD_Clear();
	buzzer_Off();
	g_flagStage = 1;
	TIMER_0_DELAY_MS(500);// timeout
}
/************************************************reset_stage**********************************************************************************/
/* Description:
function used once button_5 is press to  reset temperature to its default
*********************************************************************************************************************************************/
void reset_stage (void)
{
	LCD_Clear();
	g_tempValue = 20;
	LCD_Write_String("Temp value is");
	LCD_GoTo(2,1);
	LCD_Write_String("resettled to 20");
	TIMER_0_DELAY_MS(2000);
	g_flagStage = 2;
}

void app_Init(void){
	
	KEYPAD_init();
	TIMER_2_INT();
	LCD_INIT();
	ADC_init();
	ADC_start_conversion (ADC_CH_6);
	buzzer_init();
}

void app_Start(void){
		
if (g_flagStage == 0 ){
	//starting 	
   g_flagStage = 1 ;
}	
if (g_flagStage == 1 )
{
  adjust_Welcome();
  adjust_stage();
}		
if (g_flagStage == 2 )
{			
   set_stage();
}

if (g_flagStage == 3 )
{
  readjust_stage();
}
if (g_flagStage == 4) 
{
	reset_stage();
}

}


