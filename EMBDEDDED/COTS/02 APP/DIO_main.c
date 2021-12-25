#include		"Std_Types.h"
#include		"Bit_Math.h"


#include		"DIO_interface.h"


int main(void)
{
	/*	Init 				*/
	/*	PC7 = OUTPUT 		*/
	DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);
	
	while(1)
	{
		/*	LED ON C7 			*/
		DIO_voidSetPinValue(PORTC,PIN7,HIGH);
	}
	return 0 ;
}