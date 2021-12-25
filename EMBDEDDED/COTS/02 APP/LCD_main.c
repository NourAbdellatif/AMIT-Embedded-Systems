#include		"Std_Types.h"
#include		"Bit_Math.h"


#include		"DIO_interface.h"
#include		"LCD_interface.h"

int main(void)
{
	/*	Init 				*/
	/*	PB2 ,1 , 3 = OUTPUT 		*/
	DIO_voidSetPinDirection(PORTB,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN2,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN3,OUTPUT);
	/*	PORTA = OUTPUT*/
	DIO_voidSetPortDirection(PORTA,0xFF);
	/*	LCD init	  */
	LCD_voidInit8bit();
	_delay_ms(1000);
	LCD_voidWriteChar8bit('A');
	
	while(1)
	{
		
	}
	return 0 ;
}