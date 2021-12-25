#define		F_CPU		16000000UL

#include		"Std_Types.h"
#include		"Bit_Math.h"


#include		"DIO_interface.h"
#include		"util/delay.h"

int main(void)
{
	/*	Init 				*/
	/*	PC7 = OUTPUT 		*/
	DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
	while(1)
	{
		/*	LED ON C7 			*/
		if(DIO_u8GetPinValue(PORTD,PIN2)==1){
			DIO_voidSetPinValue(PORTC,PIN7,HIGH);
			_delay_ms(1000);
			DIO_voidSetPinValue(PORTC,PIN7,LOW);
			_delay_ms(1000);
		}
		
		
	}
	return 0 ;
}