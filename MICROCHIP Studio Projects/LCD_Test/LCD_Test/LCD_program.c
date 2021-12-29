#define			F_CPU		16000000UL

#include		"Std_Types.h"
#include		"Bit_Math.h"

#include		"DIO_interface.h"

#include		"LCD_interface.h"
//#include		"LCD_private.h"

#include		<util/delay.h>

void	LCD_voidInit8bit(void){
	
	/* 		After Power ON		*/
	_delay_ms(35);
	/*		Function Set 2 lines of Display and Font Size 5*7	*/
	LCD_voidSendCMD8bit(0x38);
	_delay_ms(1);
	/*		Display ON/OFF Control Display ON, Cursor OFF		*/
	LCD_voidSendCMD8bit(0x0C);
	_delay_ms(1);
	/*		Display Clear										*/
	LCD_voidSendCMD8bit(0x01);
	_delay_ms(2);
	/*		Entry Mode Display  Cursor Increases				*/
	LCD_voidSendCMD8bit(0x06);
}
void	LCD_voidWriteChar8bit(u8 Data){
	/*1-RS=1 to send Char										*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,HIGH);
	/*2-RW=0 to write Char										*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);
	/*3-EN must be latched (EN=1)								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
	/*4-Send CMD								*/
	DIO_voidSetPortValue(LCD_DATA_PORT,Data);
	/*3-EN must be latched (EN=0)								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);
}
void	LCD_voidSendCMD8bit(u8 CMD){
	/*1-RS=0 to send CMD										*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,LOW);
	/*2-RW=0 to write CMD										*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);
	/*3-EN must be latched (EN=1)								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
	/*4-Send CMD								*/
	DIO_voidSetPortValue(LCD_DATA_PORT,CMD);
	/*3-EN must be latched (EN=0)								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);
	
}
void	LCD_voidInit4bit(void){
	_delay_ms(100);
	LCD_voidSendCMD4bit(0x33);
	LCD_voidSendCMD4bit(0x32);
	LCD_voidSendCMD4bit(0x28);
	
	LCD_voidSendCMD4bit(0x0C);
	LCD_voidSendCMD4bit(0x01);
	LCD_voidSendCMD4bit(0x06);
	LCD_voidSendCMD4bit(0x02);
}
void	LCD_voidWriteChar4bit(u8 Data)
{
	u8 temp = 0;
	/*	1-	RS = 1	to Send CMD								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,HIGH);
	/*	2-	RW = 0	to Write CMD							*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);
	/*	3-	En must be latched (EN = 1)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(1);
	/*	4-	Assign the High Nibble of Data without change in the low Nibble in PORT	*/
	temp = ((Data & 0xF0) | (DIO_u8GetPortValue(LCD_DATA_PORT) & 0x0F));
	DIO_voidSetPortValue(LCD_DATA_PORT,temp);
	/*	5-	En must be latched (EN = 0)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(1);
	/*	6-	En must be latched (EN = 1)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(1);
	/*	7-	Assign the LOW Nibble of Data without change in the low Nibble in PORT	*/
	temp = ((Data << 4) | (DIO_u8GetPortValue(LCD_DATA_PORT) & 0x0F));
	DIO_voidSetPortValue(LCD_DATA_PORT,temp);
	/*	8-	En must be latched (EN = 0)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(1);
}
void	LCD_voidSendCMD4bit(u8 CMD)
{
	
	u8 temp = 0;
	/*	1-	RS = 0	to Send CMD								*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,LOW);
	/*	2-	RW = 0	to Write CMD							*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,LOW);
	/*	3-	En must be latched (EN = 1)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(1);
	/*	4-	Assign the High Nibble of Data without change in the low Nibble in PORT	*/
	temp = ((CMD & 0xF0) | (DIO_u8GetPortValue(LCD_DATA_PORT) & 0x0F));
	DIO_voidSetPortValue(LCD_DATA_PORT,temp);
	/*	5-	En must be latched (EN = 0)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(1);
	/*	6-	En must be latched (EN = 1)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(1);
	/*	7-	Assign the LOW Nibble of Data without change in the low Nibble in PORT	*/
	temp = ((CMD << 4) | (DIO_u8GetPortValue(LCD_DATA_PORT) & 0x0F));
	DIO_voidSetPortValue(LCD_DATA_PORT,temp);
	/*	8-	En must be latched (EN = 0)						*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(1);
}
// Warning avoid (u8*) ""
void	LCD_voidWriteString(u8 * string)
{
	u8 Local_u8Val = 0;
	while(string[Local_u8Val] != '\0'){
		switch(LCD_MODE){
			case 4:	LCD_voidWriteChar4bit(string[Local_u8Val]);break;
			case 8: LCD_voidWriteChar8bit(string[Local_u8Val]);break;
		}
		_delay_ms(100);
		Local_u8Val++;
	}
	
}

void	LCD_voidGotoXY(u8 Line, u8 Col){
	if(Line==0)
	{
		switch(LCD_MODE){
			case 4:	LCD_voidSendCMD4bit((0x80+Col));break;
			case 8: LCD_voidSendCMD8bit((0x80+Col));break;
		}
	}
	else if(Line==1){
		switch(LCD_MODE){
			case 4:	LCD_voidSendCMD4bit((0xC0+Col));break;
			case 8: LCD_voidSendCMD8bit((0xC0+Col));break;
		}
	}

}
void	LCD_voidWriteNumber(u8 Number){
	if(LCD_MODE==4){
		LCD_voidWriteChar4bit(((Number/100)%10)+0x30);
		LCD_voidWriteChar4bit(((Number/10)%10)+0x30);
		LCD_voidWriteChar4bit((Number%10)+0x30);
	}
	else if(LCD_MODE==8){
		LCD_voidWriteChar8bit(((Number/100)%10)+0x30);
		LCD_voidWriteChar8bit(((Number/10)%10)+0x30);
		LCD_voidWriteChar8bit((Number%10)+0x30);
	}
	
}
void	LCD_voidWriteCustomChar(u8* HexArray){
	u8 Local_u8Variable_Arraysize = 8;
	u8 Local_u8Variable_Index = 0;
	u8	Local_u8Variable_AddChar = 0x40;
	if(LCD_MODE==4){
		LCD_voidSendCMD4bit(Local_u8Variable_AddChar);
		while(Local_u8Variable_Index<Local_u8Variable_Arraysize){
			LCD_voidWriteChar4bit(HexArray[Local_u8Variable_Index]);
			Local_u8Variable_Index++;
		}
		Local_u8Variable_AddChar+=8;
		LCD_voidSendCMD4bit(0x80);
	}
	else if(LCD_MODE==8){
		LCD_voidSendCMD8bit(Local_u8Variable_AddChar);
		while(Local_u8Variable_Index<Local_u8Variable_Arraysize){
			LCD_voidWriteChar8bit(HexArray[Local_u8Variable_Index]);
			Local_u8Variable_Index++;
		}
		Local_u8Variable_AddChar+=8;
		LCD_voidSendCMD8bit(0x80);
	}
}
