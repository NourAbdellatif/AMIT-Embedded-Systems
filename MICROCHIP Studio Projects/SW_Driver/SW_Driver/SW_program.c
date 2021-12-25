#include		"Std_Types.h"
#include		"Bit_Math.h"
#include		"DIO_interface.h"
#include		"DIO_private.h"
#include		"SW_interface.h"
#include		"SW_private.h"



void		SW_voidSetSwitchDirection(u8 SW_ID){
	switch(SW_ID){
		case SW_0:
				DIO_voidSetPinDirection(Port_0,SW_0,INPUT);
				break;
		case SW_1:
				DIO_voidSetPinDirection(Port_1,SW_1,INPUT);
				break;
		case SW_2:
				DIO_voidSetPinDirection(Port_2,SW_2,INPUT);
				break;
				
	}
	
}

int		SW_intSwitchPressed( u8 SW_ID ){
	switch(SW_ID){
		case SW_0:
				if(DIO_u8GetPinValue(Port_0,SW_0)==1){
					return 1;
				}
				else{
					return 0;
				}
				break;
		case SW_1:
				if(DIO_u8GetPinValue(Port_1,SW_1)==1){
					return 1;
				}
				else{
					return 0;
				}
				break;
		case SW_2:
				if(DIO_u8GetPinValue(Port_2,SW_2)==1){
					return 1;
				}
				else{
					return 0;
				}
				break;
	}
	
}