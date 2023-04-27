#include "LCD.h"


#if (LCD_Mode==_8_bit_mode)

/*************************************************************************************************
                                     8_bit_mode
*****************************************************************************************************/
/**DESCRIPTION:-
  This Function Send a Command To The LCD MicroController To Be Executed
  **/
void LCD_WRITE_COMMAND(uint8_t a_COMMAND)
{
	DIO_WRITEPIN(RS,LOW);
	DIO_WRITEPIN(RW,LOW);
	DIO_WritePort(LCD_PORT,a_COMMAND);
	DIO_WRITEPIN(EN,HIGH);
	_delay_ms(1);
	DIO_WRITEPIN(EN,LOW);
	_delay_ms(1);
	
}

/*************************************************************************************************************************/
/**DESCRIPTION:-
  This Function Send Data To The LCD MicroController To Be displayed 
  **/
void LCD_WRITE_DATA(uint8_t a_DATA)
{
	DIO_WRITEPIN(RS,HIGH);
	DIO_WRITEPIN(RW,LOW);
	DIO_WritePort(LCD_PORT,a_DATA);
	DIO_WRITEPIN(EN,HIGH);
	_delay_ms(1);
	DIO_WRITEPIN(EN,LOW);
	_delay_ms(1);
	
}

/*************************************************************************************************************************/
/**DESCRIPTION:-
  This Function Initializes The LCD With the required Configuration
  **/
void LCD_INIT(void)
{
	_delay_ms(50);
	
	LCD_WRITE_COMMAND(0X38);                     /* THIS IS FOR UNCTION SET IN THE DATA SHEET  8BIT MODE, 2LINE, 5*7*/
	_delay_ms(1);
	LCD_WRITE_COMMAND(0x0c);                     /*SCREEN ON, CURSOR OFF*/
	_delay_ms(1);
	LCD_WRITE_COMMAND(0X01);                      /*CLEAR SCREEN*/
	_delay_ms(2);
	LCD_WRITE_COMMAND(0X06);
	_delay_ms(1);
}

/************************************end of 8_bit mode driver*********************************************************/


#elif (LCD_Mode==_4_bit_mode)

/*************************************************************************************************
                                     4_bit_mode
*****************************************************************************************************/

void LCD_WRITE_COMMAND(uint8_t a_COMMAND)
{
	DIO_WRITEPIN(RS,LOW);
	DIO_WRITEPIN(RW,LOW);
	/**for the 4 most significant bits**/
	DIO_WRITEPIN(D4,read_bit(a_COMMAND,4));
	DIO_WRITEPIN(D5,read_bit(a_COMMAND,5));
	DIO_WRITEPIN(D6,read_bit(a_COMMAND,6));
	DIO_WRITEPIN(D7,read_bit(a_COMMAND,7));
	DIO_WRITEPIN(EN,HIGH);
	_delay_ms(1);
	DIO_WRITEPIN(EN,LOW);
	_delay_ms(1);
	/**for the 4 least significant bits**/
	DIO_WRITEPIN(D4,read_bit(a_COMMAND,0));
	DIO_WRITEPIN(D5,read_bit(a_COMMAND,1));
	DIO_WRITEPIN(D6,read_bit(a_COMMAND,2));
	DIO_WRITEPIN(D7,read_bit(a_COMMAND,3));
	DIO_WRITEPIN(EN,HIGH);
	_delay_ms(1);
	DIO_WRITEPIN(EN,LOW);
	_delay_ms(1);
}

/*************************************************************************************************************************/

void LCD_WRITE_DATA(uint8_t a_DATA)
{
	DIO_WRITEPIN(RS,HIGH);
	DIO_WRITEPIN(RW,LOW);
	/**for the 4 most significant bits**/
	DIO_WRITEPIN(D4,read_bit(a_DATA,4));
	DIO_WRITEPIN(D5,read_bit(a_DATA,5));
	DIO_WRITEPIN(D6,read_bit(a_DATA,6));
	DIO_WRITEPIN(D7,read_bit(a_DATA,7));
	DIO_WRITEPIN(EN,HIGH);
	_delay_ms(1);
	DIO_WRITEPIN(EN,LOW);
	_delay_ms(1);
	/**for the 4 least significant bits**/
	DIO_WRITEPIN(D4,read_bit(a_DATA,0));
	DIO_WRITEPIN(D5,read_bit(a_DATA,1));
	DIO_WRITEPIN(D6,read_bit(a_DATA,2));
	DIO_WRITEPIN(D7,read_bit(a_DATA,3));
	DIO_WRITEPIN(EN,HIGH);
	_delay_ms(1);
	DIO_WRITEPIN(EN,LOW);
	_delay_ms(1);
}
/*************************************************************************************************************************/

void LCD_INIT(void)
{
	
	DIO_INITPIN(pind0,OUTPUT);
	DIO_INITPIN(pind1,OUTPUT);
	DIO_INITPIN(pind2,OUTPUT);
	DIO_INITPIN(pinc0,OUTPUT);
	DIO_INITPIN(pinc1,OUTPUT);
	DIO_INITPIN(pinc2,OUTPUT);
	DIO_INITPIN(pinc3,OUTPUT);
	
	
	_delay_ms(50);
	LCD_WRITE_COMMAND(0x02);
	_delay_ms(1);
	LCD_WRITE_COMMAND(0X28);                     /* THIS IS FOR FUNCTION SET IN THE DATA SHEET  4BIT MODE, 2LINE, 5*7*/
	_delay_ms(1);
	LCD_WRITE_COMMAND(0x0c);                     /*SCREEN ON, CURSOR OFF*/
	_delay_ms(1);
	LCD_WRITE_COMMAND(0X01);                      /*CLEAR SCREEN*/
	_delay_ms(2);
	LCD_WRITE_COMMAND(0X06);
	_delay_ms(1);
}

/*************************************end of 4_bit mode driver********************************************************/

#endif

/**************************************************************************************************
                                   APIS for LCD
********************************************************************************************************/
/**DESCRIPTION:-
  This Function Takes a Full String and Displays It
  **/
void LCD_Write_String(uint8_t*a_String)
{
	uint8_t L_Index_i=0;
	while(a_String[L_Index_i])
	{
		LCD_WRITE_DATA(a_String[L_Index_i]);
		L_Index_i++;
	}
}
/********************************************************************************************/
/**DESCRIPTION:-
  This Function Takes a Number and Displays IT
  **/
void LCD_Write_Number(uint32_t a_number)
{
	uint8_t L_Remainder=0,L_Arr[16],L_Index_i=0,L_Index_j;
	if (a_number==0)
	{
		LCD_WRITE_DATA('0');
	}
	while(a_number>0)
	{
	L_Remainder=a_number%10;
	L_Arr[L_Index_i]=L_Remainder+'0';    /*tp display the number it self, when we add the zero asci it shits the number to it's asci*/
	L_Index_i++;
	a_number/=10;
	}
	
	for (L_Index_j=L_Index_i;L_Index_j>0;L_Index_j--)    /*to display the array of number */
	{
		LCD_WRITE_DATA(L_Arr[L_Index_j-1]);
	}
}

/**********************************************************************************************/
/**DESCRIPTION:-
  This Function Clears The LCD
  **/
void LCD_Clear(void)
{
	LCD_WRITE_COMMAND(0x01);
}

/**********************************************************************************************/
/**DESCRIPTION:-
  This Function Takes a Specific Line and a Cell On The LCD and Displays the Data In That Location
  **/
void LCD_GoTo(uint8_t a_line,uint8_t a_cell)
{
//0x80 this is from data sheet to write an address on the DDRAM"screen"*/
	if (a_line==1)
	{
		LCD_WRITE_COMMAND(0x80+a_cell);    /*0x80 means we ant to write an address and a_cell is the address we want*/
	}
	else if (a_line==2)
	{
		LCD_WRITE_COMMAND(0x80+0x40+a_cell);  /*0x40 to start from cell 0 at line 2 from the data sheet*/	
	}
}

/********************************************************************************************/
/**DESCRIPTION:-
  This Function Is Used To Display Any Character And It also used To Display the Shapes Saved In The CGRAM
  **/
void LCD_Write_Charecter(uint8_t a_char)
{
	LCD_WRITE_DATA(a_char);
}
/*****************************************************************************************/
/**DESCRIPTION
   This Function Is Used To Store New Charecter in The CGRAM Of The LCD
   **/
void LCD_Create_Charecter(uint8_t*a_Pattern,uint8_t a_Adress)
{
	uint8_t Index_I;
	LCD_WRITE_COMMAND(0x40+a_Adress*8);   //we multiply it by 8 to make it block addressable //
	
	for (Index_I=0;Index_I<8;Index_I++)
	{
		LCD_WRITE_DATA(a_Pattern[Index_I]);
	}
	
}



/*******************************************************************************************************************************************************************************************/


