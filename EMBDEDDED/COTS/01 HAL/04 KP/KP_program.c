#define			F_CPU		16000000UL

#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"

#include		"KB_interface.h"
//#include		"LCD_private.h"

#include		<util/delay.h>
static u8	KP_u8arr [4][4] = {
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','+'},
	{'.','0','=','-'}
	};

u8		KP_u8GetPressedKey(void)
{
	u8 Local_u8Val = 0xFF;
	// Deactivate Column and Row
	DIO_voidSetPortValue(KP_PORT,0xFF);
	for(u8 Col=0;Col<4;Col++){
		// Send Sequence (Activate Column)
		DIO_voidSetPinValue(KP_PORT,Col,LOW);
		// Check which Rows
		for(u8 Row=4;Row<8;Row++)
		{
			if((DIO_u8GetPinValue(KP_PORT,Row)==0)
			{
				Local_u8Val = KP_u8arr[Col][Row-4];
				// Bouncing
				_delay_ms(5);	
			}
			
		}
		
		
		// Return Sequence
		DIO_voidSetPinValue(KP_PORT,Col,HIGH);
	}
	return Local_u8Val;
	
}