#define			F_CPU		16000000UL

#include		"Std_Types.h"
#include		"Bit_Math.h"


#include		"DIO_interface.h"
#include		"LCD_interface.h"

#include		<util/delay.h>
int main(void)
{
	/*	Init 				*/
	/*	PB2 , 1 ,3 = OUTPUT 		*/
	DIO_voidSetPinDirection(PORTB,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN2,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN3,OUTPUT);
	/*	PORTA = OUTPUT				*/
	DIO_voidSetPortDirection(PORTA,0xFF);
	/*	LCD init					*/
	LCD_voidInit8bit();
	_delay_ms(10);
	LCD_voidSendCMD8bit(0x80);
	// Store arabic character in CGRAM (0x40)
	//LCD_voidSendCMD4bit(0x40);
	///*  0x00,
	//0x00,
	//0x04,
	//0x11,
	//0x11,
	//0x11,
	//0x11,
	//0x0E*/
	//// Display Char in DDRAM
	//LCD_voidSendCMD4bit(0x89)
	//LCD_voidWriteChar4bit()
	//LCD_voidGotoXY(1,2);
	LCD_voidWriteString("Ahmed");
	//LCD_voidWriteString((u8*) "^_^");
	while(1)
	{
		LCD_voidSendCMD8bit(0x1C);
		_delay_ms(5);
		
	}
	return 0 ;
}