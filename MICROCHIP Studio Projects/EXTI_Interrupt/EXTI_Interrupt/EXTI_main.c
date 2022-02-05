#define		F_CPU		16000000

#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"DIO_interface.h"
#include	"GIE_interface.h"
#include	"EXTI_interface.h"


#include	<util/delay.h>

void	EXTI_app	(void)
{
	// Toggle LED
	DIO_voidSetPinValue(PORTA,PIN1,HIGH);
	_delay_ms(100);
	DIO_voidSetPinValue(PORTA,PIN1,LOW);
	_delay_ms(100);
	
}

int main(void)
{
	EXTI0_voidSetCallBack(EXTI_app);
	//DIO initialization
	DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
	DIO_voidSetPinValue(PORTD,PIN2,HIGH);
	
	DIO_voidSetPinDirection(PORTB,PIN1,OUTPUT);
	
	//Sense Mode
	EXTI0_voidInit();
	//PIE enable
	EXTI0_voidEnable();
	//GIE enable
	GIE_voidEnable();
	while(1)
	{
		DIO_voidSetPinValue(PORTB,PIN1,HIGH);
		_delay_ms(100);
		DIO_voidSetPinValue(PORTB,PIN1,LOW);
		_delay_ms(100);
	}
	
	return 0;
}