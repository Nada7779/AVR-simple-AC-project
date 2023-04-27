/*
 * ADC_config.h
 *
 * Created: 4/20/2023 8:01:38 AM
 *  Author: NADA
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* configure the voltage range
  // ADC voltage select
  ADC_VREF_AVCC      
  ADC_VREF_AREF      
  ADC_VREF_2_56 
 */
#define ADC_volatge_ref_selector       ADC_VREF_2_56
#define ADC_volatge_mv                 5000
#define ADC_max_number_of_steps        1024  

/* configure ADC modes
 // ADC modes
 ADC_mode_auto_trigger   
 ADC_single_conversion   
*/
#define ADC_mode_selector    ADC_mode_auto_trigger   

/* configure ADC adjustment
  // ADC adjust
  ADC_right_adjust  
  ADC_left_adjust   
*/
#define ADC_adjust_selector   ADC_right_adjust      



/* configure ADC prescaler
// ADC prescaler
ADC_prescaler_2         
ADC_prescaler_4         
ADC_prescaler_8         
ADC_prescaler_16        
ADC_prescaler_32        
ADC_prescaler_64        
ADC_prescaler_128       
*/
#define ADC_prescaler_selector     ADC_prescaler_128 


/* configure ADC trigger source 
// ADC auto trigger
ADC_auto_trig_clr_msk       
ADC_auto_trig_free_running   
ADC_auto_trig_analog_comp    
ADC_auto_trig_exit0          
ADC_auto_trig_timer0_comp    
ADC_auto_trig_timer0_ovf  
ADC_auto_trig_timer1_comp    
ADC_auto_trig_timer1_ovf     
ADC_auto_trig_timer1_capt    
*/
#define ADC_auto_trig_source_selector  ADC_auto_trig_free_running         


#endif /* ADC_CONFIG_H_ */