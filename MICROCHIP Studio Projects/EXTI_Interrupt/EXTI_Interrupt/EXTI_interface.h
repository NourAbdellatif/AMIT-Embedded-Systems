#ifndef		EXTI_INTERFACE_H
#define		EXTI_INTERFACE_H

void	EXTI0_voidInit(void);

void	EXTI0_voidEnable(void);
void	EXTI0_voidDisable(void);
void	EXTI0_voidSetCallBack(void (*Copy_PF)(void));

void	__vector_1 (void) __attribute__((signal,used));





#endif