#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"DIO_private.h"

#include		"SSD_interface.h"
#include		"SSD_private.h"

void		SSD_voidSetValue(u8 SEG_ID , u8 Number){
	if((SEG_ID==1 || SEG_ID==0) && Number>=0 && Number<=9){
		DIO_voidSetPinDirection(Number_Port,4,OUTPUT);
		DIO_voidSetPinDirection(Number_Port,5,OUTPUT);
		DIO_voidSetPinDirection(Number_Port,6,OUTPUT);
		DIO_voidSetPinDirection(Number_Port,7,OUTPUT);
		DIO_voidSetPinDirection(Enable_Port,1,OUTPUT);
		DIO_voidSetPinDirection(Enable_Port,2,OUTPUT);
		
		switch(SEG_ID){
			case SEG_1 :
						DIO_voidSetPinValue(Enable_Port,1,1);
						DIO_voidSetPinValue(Enable_Port,2,0);
						break;
			case SEG_2 :
						DIO_voidSetPinValue(Enable_Port,1,0);
						DIO_voidSetPinValue(Enable_Port,2,1);
						break;
		}
		switch(Number){
			case 0:
						DIO_voidSetPinValue(Number_Port,4,0);
						DIO_voidSetPinValue(Number_Port,5,0);
						DIO_voidSetPinValue(Number_Port,6,0);
						DIO_voidSetPinValue(Number_Port,7,0);
						break;
			case 1:
						DIO_voidSetPinValue(Number_Port,4,1);
						DIO_voidSetPinValue(Number_Port,5,0);
						DIO_voidSetPinValue(Number_Port,6,0);
						DIO_voidSetPinValue(Number_Port,7,0);
						break;
			case 2:
						DIO_voidSetPinValue(Number_Port,4,0);
						DIO_voidSetPinValue(Number_Port,5,1);
						DIO_voidSetPinValue(Number_Port,6,0);
						DIO_voidSetPinValue(Number_Port,7,0);
						break;
			case 3:
						DIO_voidSetPinValue(Number_Port,4,1);
						DIO_voidSetPinValue(Number_Port,5,1);
						DIO_voidSetPinValue(Number_Port,6,0);
						DIO_voidSetPinValue(Number_Port,7,0);
						break;
			case 4:
						DIO_voidSetPinValue(Number_Port,4,0);
						DIO_voidSetPinValue(Number_Port,5,0);
						DIO_voidSetPinValue(Number_Port,6,1);
						DIO_voidSetPinValue(Number_Port,7,0);
						break;
			case 5:
						DIO_voidSetPinValue(Number_Port,4,1);
						DIO_voidSetPinValue(Number_Port,5,0);
						DIO_voidSetPinValue(Number_Port,6,1);
						DIO_voidSetPinValue(Number_Port,7,0);
						break;
			case 6:
						DIO_voidSetPinValue(Number_Port,4,0);
						DIO_voidSetPinValue(Number_Port,5,1);
						DIO_voidSetPinValue(Number_Port,6,1);
						DIO_voidSetPinValue(Number_Port,7,0);
						break;
			case 7:
						DIO_voidSetPinValue(Number_Port,4,1);
						DIO_voidSetPinValue(Number_Port,5,1);
						DIO_voidSetPinValue(Number_Port,6,1);
						DIO_voidSetPinValue(Number_Port,7,0);
						break;
			case 8:
						DIO_voidSetPinValue(Number_Port,4,0);
						DIO_voidSetPinValue(Number_Port,5,0);
						DIO_voidSetPinValue(Number_Port,6,0);
						DIO_voidSetPinValue(Number_Port,7,1);
						break;
			case 9:
						DIO_voidSetPinValue(Number_Port,4,1);
						DIO_voidSetPinValue(Number_Port,5,0);
						DIO_voidSetPinValue(Number_Port,6,0);
						DIO_voidSetPinValue(Number_Port,7,1);
						break;
		}
	}
	
	
	
}