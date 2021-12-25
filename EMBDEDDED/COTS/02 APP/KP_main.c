#include		"Std_Types.h"
#include		"Bit_Math.h"


#include		"DIO_interface.h"
#include		"LCD_interface.h"
#include		"KP_interface.h"

int main(void)
{
	/*	Init 				*/
	/*	PB2 ,1 , 3 = OUTPUT 		*/
	DIO_voidSetPinDirection(PORTB,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN2,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN3,OUTPUT);
	/*	PORTA = OUTPUT*/
	DIO_voidSetPortDirection(PORTA,0xFF);
	/*	PORTD = Keypad (0:3 ==> OUTPUT) && (4:7 ==> INPUT Pulled up) */
	DIO_voidSetPortDirection(PORTD,0x0F);
	DIO_voidSetPortValue(PORTD,0XF0);
	
	/*	LCD init	  */
	LCD_voidInit8bit();
	u8	PressedKey=0xFF;
	while(1)
	{
		PressedKey = KP_u8GetPressedKey();
		if(PressedKey != 0xFF)
		{
			LCD_voidWriteChar8bit(PressedKey);
			_delay_ms(500);
		}
	}
	return 0 ;
}