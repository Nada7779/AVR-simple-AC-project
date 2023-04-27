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

/**************************************************************************************************************************/
/**DESCRIPTION:-
   This Function displays The Welcome Message And it Stores The Bell Shape In th LCD 
   **/
void Start(void)
{
	uint8_t Start_Message[]="<<Welcome>>",STR[]="Default Temp=20",LV_Length1=0,LV_Length2=0,LV_Index_I;
	
	uint8_t bell[8] = {0x04, 0x0E ,0x0E ,0x0E ,0x1f ,0x00 ,0x04 ,0x00};  //HEX Array for the Bell Shape//
		
	while(Start_Message[LV_Length1]) //this while loop is used to measure the length of the string //
	{
		LV_Length1++;
	}
	while(STR[LV_Length2])
	{
		LV_Length2++;
	}
	
	for (LV_Index_I=LV_Length1;LV_Index_I>1;LV_Index_I--)  //this for loop is used to display the str from the last charecter to the first one//
	{
		LCD_Write_String(Start_Message+LV_Index_I-1);
		_delay_ms(50);
		LCD_Clear();
	}
	for (LV_Index_I=0;LV_Index_I<15;LV_Index_I++) //this for loop is used to display the whole string along the LCD Length//
	{
		LCD_GoTo(1,LV_Index_I);
		LCD_Write_String(Start_Message);
		_delay_ms(50);
		LCD_Clear();
	}
	for (LV_Index_I=LV_Length2;LV_Index_I>1;LV_Index_I--)
	{
		LCD_GoTo(2,0);
		LCD_Write_String(STR+LV_Index_I-1);
		_delay_ms(50);
		LCD_Clear();
	}
	_delay_ms(50);
	
	for (LV_Index_I=0;LV_Index_I<15;LV_Index_I++)
	{
		LCD_GoTo(2,LV_Index_I);
		LCD_Write_String(STR);
		_delay_ms(50);
		LCD_Clear();
	}
	LCD_GoTo(1,0);
	LCD_Write_String("1:++	2:--  3:SET");
	LCD_GoTo(2,0);
	LCD_Write_String("4:RESET	5:ADJUST");
	_delay_ms(500);
	
	//storing the bell shape in the CGRAM//
	LCD_Create_Charecter(bell,2);
}
/******************************************************************************************************************************************/
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
	 while (key != SET && key != RESET  && g_flagStage != SETTED_STAGE)
	 {
		key = KEYPAD_getKey() ;
		TIMER_0_DELAY_MS(50);
			switch(key){
				case INCREMENT :
				g_tempValue++;
				g_flagTimer = 0;
				break;
				
				case DECREMENT :
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
	
	
		switch(key){
				case SET :
				g_flagStage = SETTED_STAGE ;
				break;
				
				case RESET :
				g_flagStage = RESET_STAGE ;
				break;
				
				
				default :
				
				break;
				
			}
}
/************************************************set_stage************************************************************************************/
/* Description:
function used once Once button_3 is pressed the temperature is set and LCD display current temp
and display buzzer shape if temperature > set temperature & buzzer ON
***********************************************************************************************************************************************/
void set_stage(void){
LCD_Clear();
uint8_t a_key = 0;
while (a_key != ADJUST && a_key != RESET)
{
	a_key = KEYPAD_getKey() ;
	TIMER_0_DELAY_MS(50);
	unsigned short int curreunt_temp = LM35_read();
	if (curreunt_temp > g_tempValue) 
	{
		buzzer_On();
		LCD_GoTo(2,8);
		LCD_Write_Charecter(2);
	}
	else 
	{
		buzzer_Off();
		LCD_GoTo(2,8);
		LCD_Write_String(" ");
	}
	if (a_key== INCREMENT || a_key== DECREMENT) //after set mode all buttons are not allowed except button_4 and button_5
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
if (a_key == ADJUST) g_flagStage = READJUST_STAGE;
else if (a_key == RESET) g_flagStage = RESET_STAGE;
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
	g_flagStage = ADJUST_STAGE;
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
	g_flagStage = SETTED_STAGE ;
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
		
	if (g_flagStage == STARTING ){
	   Start();	
	   g_flagStage = ADJUST_STAGE ;
	}	
	
	if (g_flagStage == ADJUST_STAGE )
	{
	  adjust_Welcome();
	  adjust_stage();
	}		
	if (g_flagStage == SETTED_STAGE )
	{			
	   set_stage();
	}

	if (g_flagStage == READJUST_STAGE )
	{
	  readjust_stage();
	}
	if (g_flagStage == RESET_STAGE) 
	{
		reset_stage();
	}

}





