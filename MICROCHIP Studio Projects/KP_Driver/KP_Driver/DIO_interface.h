#ifndef		DIO_INTERFACE_H
#define		DIO_INTERFACE_H

void		DIO_voidSetPinDirection(u8 PortID ,u8 PinID ,u8 Direction );
void		DIO_voidSetPinValue(u8 PortID ,u8 PinID ,u8 Value );
u8			DIO_u8GetPinValue(u8 PortID ,u8 PinID );
void		DIO_voidSetPortDirection(u8 PortID , u8 Direction);
void		DIO_voidSetPortValue(u8 PortID , u8 Value);	
u8 			DIO_u8GetPortValue(u8 PortID);
#define		PORTA				0
#define		PORTB				1
#define		PORTC				2
#define		PORTD				3

#define		PIN0				0
#define		PIN1				1
#define		PIN2				2
#define		PIN3				3
#define		PIN4				4
#define		PIN5				5
#define		PIN6				6
#define		PIN7				7

#define		OUTPUT				1
#define		INPUT				0

#define		HIGH				1
#define		LOW					0



#endif