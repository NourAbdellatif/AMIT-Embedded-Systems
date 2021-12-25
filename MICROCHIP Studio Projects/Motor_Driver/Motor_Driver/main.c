/*
 * Motor_Driver.c
 *
 * Created: 12/25/2021 11:05:39 PM
 * Author : noura
 */ 

#define			F_CPU		16000000UL

#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		<util/delay.h>
#include		"DIO_interface.h"


int main(void)
{
    DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN1,OUTPUT);
	
    while (1) 
    {
		DIO_voidSetPinValue(PORTA,PIN0,HIGH);
		DIO_voidSetPinValue(PORTA,PIN1,LOW);
		_delay_ms(100);
		DIO_voidSetPinValue(PORTA,PIN0,LOW);
		DIO_voidSetPinValue(PORTA,PIN1,HIGH);
		_delay_ms(100);
    }
}

