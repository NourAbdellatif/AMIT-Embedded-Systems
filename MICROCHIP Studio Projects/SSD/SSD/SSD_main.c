/*
 * SSD.c
 *
 * Created: 12/22/2021 7:50:47 PM
 * Author : noura
 */ 
#define		F_CPU		16000000UL
#include "util/delay.h"

#include <avr/io.h>
#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"DIO_private.h"

#include		"SSD_interface.h"
#include		"SSD_private.h"
int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		SSD_voidSetValue(SEG_2,5);
    }
}

