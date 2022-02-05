#include	"Std_Types.h"
#include	"Bit_Math.ht"

#include	"DIO_interface.h"
#include	"GIE_interface.h"
#include	"EXTI_interface.h"


#include	<util/delay.h>

void	EXTI_app	(void)
{
	// Toggle LED
	
}

int main(void)
{
	EXTI0_voidSetCallBack(EXTI_app);
	//DIO initialization
	//Sense Mode
	EXTI0_voidInit();
	//PIE enable
	EXTI0_voidEnable();
	//GIE enable
	GIE_voidEnable();
	while(1)
	{
		
		
	}
	
	return 0;
}