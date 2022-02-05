#define		F_CPU		16000000UL

#include	"Std_Types.h"
#include	"Bit_Math.h"

//#include	"DIO_interface.h"
#include	<avr/io.h>
#include	<avr/interrupt.h>
#include	<util/delay.h>

int main(void)
{
    DDRD = 0xF0;
	PORTD = 0XFF;
	DDRA= 0XFF;
	
	
	//Sense mode of external interrupt 0 (Falling edge)
	SET_BIT(MCUCR,1);
	
	//Peripheral interrupt 0 Enable
	SET_BIT(GICR,6);

	 //Global Interrupt enable
	SET_BIT(SREG,7);
	
	PORTA = 0XFF;
	_delay_ms(100);
	PORTA= 0X00;
	_delay_ms(100);
    while (1) 
    {
    }
}

ISR(INT0_vect)
{
	// Toggle LED when interrupt occurs
	PORTA = 0XFF;
	_delay_ms(100);
	PORTA= 0X00;
	_delay_ms(100);
}