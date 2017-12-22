#ifndef MY_LCD_H
#define MY_LCD_H

#define LCD_LIGHT_ON 1
#define LCD_LIGHT_OFF 0


void LCDWriteCommand(char cmd);
void LCDWriteData(char dat);
void LCDInit();
void LCDClearLCD();
void LCDLigth(char light);
void LCDSetPosition(char line, char col);
void LCDWriteString(char line, char col, char *s);
	


#endif
