#include "MOTOR.h"

/*********************************func_implementation********************************************************/
/**DESCRIPTION:-
  this function intializes the DIO pins connected to the motors to be output
  **/
void Car_Motors_init()
{
	DIO_INITPIN(motor1_0,OUTPUT);
	DIO_INITPIN(motor1_1,OUTPUT);
	DIO_INITPIN(motor2_0,OUTPUT);
	DIO_INITPIN(motor2_1,OUTPUT);

}


/**************************************************************************************************************/
/**DESCRIPTION:-
this fumction is used to drive the motor to move in the +VE direction which will lead the car to move FWD
**/
void Car_Moving_FWD(void)
{
	DIO_WRITEPIN(motor1_0,LOW);          //this is used to provide voltage to the +ve pin of the motor 
	DIO_WRITEPIN(motor1_1,HIGH);           //this is used to provide the ground to the -ve pin of 
	DIO_WRITEPIN(motor2_0,LOW);
	DIO_WRITEPIN(motor2_1,HIGH);
	
}

/***********************************************************************************************************************/
/**DESCRIPTION:-
this function is used to drive the right wheels to move FWD, and the left wheels to move BWD,
which will lead to rotation of the car */
void Car_Rotating(void)
{
	 //this is used to provide the ground to the -ve pin of
	DIO_WRITEPIN(motor1_0,HIGH);        
	DIO_WRITEPIN(motor1_1,LOW);    
	
	//this is used to provide voltage to the +ve pin of the motor
	DIO_WRITEPIN(motor2_0,LOW);
	DIO_WRITEPIN(motor2_1,HIGH);

}

/***********************************************************************************************************************/
/**DESCRIPTION:-
this function is used to stop the 4 wheels by stopping the 4 motors*/
void Car_Stop(void)
{
	
	
  DIO_WRITEPIN(motor1_0,LOW);          
  DIO_WRITEPIN(motor1_1,LOW);           
  DIO_WRITEPIN(motor2_0,LOW);
  DIO_WRITEPIN(motor2_1,LOW);

}