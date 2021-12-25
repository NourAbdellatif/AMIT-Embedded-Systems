/*
 * SSD_CommonCathode.c
 *
 * Created: 12/18/2021 7:34:09 PM
 * Author : noura
 */ 

#define		F_CPU			16000000UL

//#include <avr/io.h>
#include <util/delay.h>

typedef	unsigned	char u8;

#define		DDRA			*((u8 *)0x3A)
#define		PORTA			*((u8 *)0x3B)
#define		DDRB			*((u8 *)0x37)
#define		PORTB			*((u8 *)0x38)

#define		DDRC			*((volatile u8 *)0x34)
#define		PORTC			*((volatile u8 *)0x35)

#define		DDRD			*((volatile u8 *)0x31)
#define		PIND			*((volatile u8 *)0x30)

#define		GET_BIT(REG,BIT_NUM) 	REG = ((REG>>BIT_NUM)&1)
int main(void)
{
	/*	All pins in PORT A are Output				*/
	DDRA = 0xF0;
	/*	All pins in PORT B are Output				*/
	DDRC = 0xFF;
	DDRD = 0x00;
    /* Replace with your application code */
	PORTB = 0x06;
    while (1) 
    {
		if (GET_BIT(PIND,6)==1)
		{
			PORTC = 0x80;
			_delay_ms(20);
		}
		else
		{
			PORTC = 0;
		}
		/*PORTB=0x0C;
		PORTA=0x60;
		_delay_ms(20);
		PORTB=0x0A;
		PORTA=0x90;
		_delay_ms(20);*/
    }
	return 0 ;
}

