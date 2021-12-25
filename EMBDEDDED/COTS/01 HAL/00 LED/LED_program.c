#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"
#include		"DIO_private.h"

#include		"LED_interface.h"
#include 		<util/delay.h>
void		LED_voidLedOn(u8 LedID){
	if(LedID==2 || LedID==3 || LedID==7){
		if(LedID==2){
			DIO_voidSetPinDirection(LED0_Port,LED0,OUTPUT);
			DIO_voidSetPinValue(LED0_Port,LED0,HIGH);
		}
		else if(LedID==3){
			DIO_voidSetPinDirection(LED2_Port,LED2,OUTPUT);
			DIO_voidSetPinValue(LED2_Port,LED2,HIGH);
		}
		else{
			DIO_voidSetPinDirection(LED1_Port,LED1,OUTPUT);
			DIO_voidSetPinValue(LED1_Port,LED1,HIGH);
		}
	}
}

void		LED_voidLedOff(u8	LedID){
	if(LedID==2 || LedID==3 || LedID==7){
		if(LedID==2){
			DIO_voidSetPinValue(LED0_Port,LED0,LOW);
		}
		else if(LedID==3){
			DIO_voidSetPinValue(LED2_Port,LED2,LOW);
		}
		else{
			DIO_voidSetPinValue(LED1_Port,LED1,LOW);
		}
	}
}
void		LED_voidFlashLed(u8	LedID,u16 duration){
	if(LedID==2 || LedID==3 || LedID==7){
		if(LedID==2){
			DIO_voidSetPinDirection(LED0_Port,LED0,OUTPUT);
			DIO_voidSetPinValue(LED0_Port,LED0,HIGH);
			_delay(duration*1000);
			DIO_voidSetPinValue(LED0_Port,LED0,LOW);
			_delay(duration*1000);
		}
		else if (LedID==3){
			DIO_voidSetPinDirection(LED0_Port,LED2,OUTPUT);
			DIO_voidSetPinValue(LED2_Port,LED2,HIGH);
			_delay(duration*1000);
			DIO_voidSetPinValue(LED2_Port,LED2,LOW);
			_delay(duration*1000);
		}
		else{
			DIO_voidSetPinDirection(LED0_Port,LED1,OUTPUT);
			DIO_voidSetPinValue(LED2_Port,LED1,HIGH);
			_delay(duration*1000);
			DIO_voidSetPinValue(LED2_Port,LED1,LOW);
			_delay(duration*1000);
		}
	
	}
	
	
}