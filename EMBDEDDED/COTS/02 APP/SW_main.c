/*
 * SW_Driver.c
 *
 * Created: 12/22/2021 8:25:35 PM
 * Author : noura
 */ 

#include <avr/io.h>
#include		"Std_Types.h"
#include		"Bit_Math.h"
#include		"DIO_interface.h"
#include		"DIO_private.h"
#include		"SW_interface.h"
#include		"SW_private.h"



int main(void)
{
    /* Replace with your application code */
	SW_voidSetSwitchDirection(SW_0);
    while (1)
    {
		if(SW_intSwitchPressed(SW_0)){
			printf("button pressed");
		}
    }
}

