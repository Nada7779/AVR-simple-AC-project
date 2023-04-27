
#ifndef motor_H_
#define motor_H_

/*************************includes*********************************************************************************/
#include "../../MCAL/DIO/DIO.h"
/******************************************************************************************************************/

/**************************************defines*********************************************************************/
#define motor1_0  pina0
#define motor1_1  pina1
#define motor2_0  pina2
#define motor2_1  pina3
#define motor3_0  pina4
#define motor3_1  pina5
#define motor4_0  pina6
#define motor4_1  pina7


/*******************************************************************************************************************/

/************************************************declarations*******************************************************/

void Car_Motors_init(void);
void Car_Moving_FWD(void);
void Car_Rotating(void);
void Car_Stop(void);
#endif /* MOTOR_H_ */