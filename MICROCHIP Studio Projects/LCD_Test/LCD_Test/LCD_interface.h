#ifndef		LCD_INTERFACE_H
#define		LCD_INTERFACE_H

#define		LCD_CONTROL_PORT				PORTB
#define		LCD_RS							PIN1
#define		LCD_RW							PIN2
#define		LCD_EN							PIN3

#define		LCD_DATA_PORT					PORTA
#define		LCD_MODE						8

void	LCD_voidInit8bit(void);
void	LCD_voidWriteChar8bit(u8 Data);
void	LCD_voidSendCMD8bit(u8 CMD);

void	LCD_voidInit4bit(void);
void	LCD_voidWriteChar4bit(u8 Data);
void	LCD_voidSendCMD4bit(u8 CMD);
void	LCD_voidWriteNumber(u8 Number );
void	LCD_voidWriteCustomChar(u8* HexArray);
void	LCD_voidWriteString(u8 * string);
void	LCD_voidGotoXY(u8 Line, u8 Col);

#endif