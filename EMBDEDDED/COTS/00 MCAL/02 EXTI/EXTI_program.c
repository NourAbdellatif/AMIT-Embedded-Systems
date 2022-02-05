#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"EXTI_interface.h"
#include		"EXTI_private.h"
#include		"EXTI_config.h"
#ifndef			NULL
#define			NULL		(void*)0
#endif

static void (*EXTI0_CallBack)(void) = NULL;

void	EXTI0_voidInit(void){
	//Sense mode of interrupt
	#if		EXTI0_SENSE_MODE == EXTI_LOW_LEVEL
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
	#elif	EXTI0_SENSE_MODE == EXTI_FALLING_RISING
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
	#elif	EXTI0_SENSE_MODE == EXTI_FALLING_EDGE
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
	#elif	EXTI0_SENSE_MODE == EXTI_RISING_EDGE
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
	
	#else
		#error	"Wrong choice of EXTI0 Sense Mode"
	#endif
	//Disable any interrupts
	CLR_BIT(GICR,6);
	//Clear event (Clear the interrupt flag)
	CLR_BIT(GICR,6);
}

void	EXTI0_voidEnable(void)
{
	SET_BIT(GICR,6);
	
}
void	EXTI0_voidDisable(void)
{
	CLR_BIT(GICR,6);
	
}
// Copy_PF = EXTI_app
void	EXTI0_voidSetCallBack(void (*Copy_PF)(void))
{
	EXTI0_CallBack = Copy_PF;
	
}

void	__vector_1 (void)
{
	//EX_app(); 
	EXTI0_CallBack();
}
