/*
 * ADC.c
 *
 * Created: 4/20/2023 6:18:15 AM
 *  Author: NADA
 */ 


#include "adc.h"

/************************************************ADC_init**********************************************************************************/
/* Description:
Function used to initialize the ADC with the properties chosen from thE ADC_config
*******************************************************************************************************************************************/
void ADC_init(void)
{
// selecting voltage ref
ADMUX &=  ADC_VREF_clr_msk;
ADMUX |=  ADC_volatge_ref_selector; 
// select ADC mode
#if  ADC_mode_selector ==  ADC_mode_auto_trigger 
     ADCSRA   |= (1<<5);
	 SFIOR &= ADC_auto_trig_clr_msk;
	 SFIOR |= ADC_auto_trig_source_selector;
#elif  ADC_mode_selector ==  ADC_single_conversion  
     ADCSRA &= ~(1<<5);
#endif
// select adjustment
#if     ADC_adjust_selector ==  ADC_right_adjust
        ADMUX &= ~(1<<5);
#elif   ADC_adjust_selector ==  ADC_left_adjust
        ADMUX |=  (1<<5);
#endif
// clear interrupt flag
ADCSRA |= (1<<4);

//enabling ADC
ADCSRA |= (1<<7);	
}
/************************************************ADC_start_conversion**********************************************************************************/
/* Description:
Function used to start the ADC conversion at the required pin
********************************************************************************************************************************************************/
void ADC_start_conversion (ADC_CH_type ADC_CH)
{
// selecting ADC channel
ADMUX &= ADC_CH_selector_clr_msk;
ADMUX |= ADC_CH;
// ADC start conversion
ADCSRA |= (1<<6);
// wait until conversion is done
while((ADCSRA & (1<<6))==0);

}
/************************************************ADC_Read***********************************************************************************************/
/* Description:
Function used to read the value converted by the ADC using the right method right method to read high and low bits
********************************************************************************************************************************************************/
uint16 ADC_Read(void)
{
 
 return ADCLH;	
}
/************************************************LM35_Read***********************************************************************************************/
/* Description:
Function used to calibrate the value read from the LM35 temperature sensor using ADC_Read according to voltage reference 2.56 volts in degree celsius
********************************************************************************************************************************************************/
uint16 ADC_LM35_calibration (void)
{
    uint16 a_temp_celsius;	
	a_temp_celsius	 = ADC_Read();
	a_temp_celsius	 = (2.5* a_temp_celsius	)/10;
	return a_temp_celsius;
}