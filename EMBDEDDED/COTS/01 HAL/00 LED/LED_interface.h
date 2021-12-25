#ifndef		LED_INTERFACE_H
#define		LED_INTERFACE_H

void		LED_voidLedOn(u8 LedID);
void		LED_voidLedOff(u8	LedID);
void		LED_voidFlashLed(u8	LedID,u16 duration);


#define		LED0		2
#define		LED0_Port	2
#define		LED1		7
#define		LED1_Port	2
#define		LED2		3		
#define		LED2_Port	3

#endif