#ifndef		SW_PRIVATE_H
#define		SW_PRIVATE_H



/*				PORT B Registers For SW_0	 			*/
#define			DDRB_REG			*((volatile u8 *)0x37)
#define			PINB_REG			*((volatile u8 *)0x36)


/*				PORT D Registers For SW_1 ,SW_2			*/
#define			DDRD_REG			*((volatile u8 *)0x31)
#define			PIND_REG			*((volatile u8 *)0x30)


#endif