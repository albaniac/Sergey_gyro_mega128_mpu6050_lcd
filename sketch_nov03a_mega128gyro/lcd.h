#ifndef MY_LCD_H
#define MY_LCD_H

#define LCD_LIGHT_ON 1
#define LCD_LIGHT_OFF 0


void LCD_Write_Command(char cmd);
void LCD_Write_Data(char dat);
void LCD_Init();
void LCD_ligth(char light);
void LCD_Set_Position(char line, char col);
void LCD_Write_String(char line, char col, char *s);
	


#endif
