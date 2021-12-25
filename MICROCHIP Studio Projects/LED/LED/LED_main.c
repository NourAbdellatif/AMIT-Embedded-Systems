/*
 * LED.c
 *
 * Created: 12/22/2021 6:52:58 PM
 * Author : noura
 */ 
#define		F_CPU		16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"DIO_private.h"

#include		"LED_interface.h"

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		LED_voidLedOn(LED0);
		_delay_ms(5000);
		LED_voidLedOff(LED0);
		LED_voidLedOn(LED1);
		_delay_ms(5000);
		LED_voidLedOff(LED1);
		LED_voidLedOff(LED1);
		LED_voidLedOn(LED2);
		_delay_ms(5000);
		LED_voidLedOff(LED2);
    }
}

