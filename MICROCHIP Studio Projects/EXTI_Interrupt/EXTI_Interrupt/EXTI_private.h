#ifndef		EXTI_PRIVATE_H
#define		EXTI_PRIVATE_H

#define			MCUR_REG			*((volatile u8 *)0x55)
#define			MCUCSR_REG			*((volatile u8 *)0x54)
#define			GICR_REG			*((volatile u8 *)0x5B)
#define			GIFR_REG			*((volatile u8 *)0x5A)

#define			EXTI_FALLING_EDGE		1
#define			EXTI_RISING_EDGE		3
#define			EXTI_FALLING_RISING		5
#define			EXTI_LOW_LEVEL			7

#endif