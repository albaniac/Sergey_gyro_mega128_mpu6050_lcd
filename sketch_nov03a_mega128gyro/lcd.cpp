#include <avr/io.h>
#include <avr/delay.h>
#include "lcd.h"
#include "common_makros.h"

#define RS 0
#define EN 1
#define RW 2
#define CMDPORT PORTB
#define DATAPORT PORTC

void LCD_ligth(char light)
{
	if (light = LCD_LIGHT_ON)
	{
		UPBIT(PORTA, 7); // on light
	}
	else
	{
		DOWNBIT(PORTA, 7); // off light
	}
}

void lcdpuls()
{
	UPBIT(CMDPORT, EN);
	_delay_ms(10);
	DOWNBIT(CMDPORT, EN);
}

void LCD_Write_Command(char cmd)
{                          

	DOWNBIT(CMDPORT, RS);
	DOWNBIT(CMDPORT, RW);
	DOWNBIT(CMDPORT, EN);

    _delay_ms(1);  
	  
	DATAPORT = cmd;

    _delay_ms(1);

    UPBIT(CMDPORT, EN);

    _delay_ms(1);

    DOWNBIT(CMDPORT, EN);  
}

void LCD_Write_Data(char dat)
{                          
	UPBIT(CMDPORT, RS);
	DOWNBIT(CMDPORT, RW);
	DOWNBIT(CMDPORT, EN);

     _delay_ms(1);  
	  
	DATAPORT = dat;
 
    _delay_ms(1); 

    UPBIT(CMDPORT, EN);

    _delay_ms(1);

    DOWNBIT(CMDPORT, EN); 
}

void LCD_Init()
{ 
	DOWNBIT(CMDPORT, EN);

	_delay_ms(1000);

 	DDRA |= (1 << 7); // podsvetka

	DDRA |= (1 << 6); // parallel data
	PORTA |= (1 << 6); // set parallel

	DDRB |= 0b00000111;

	DDRC = 0xff; // data port for lcd
    
    LCD_Write_Command(0x34);      	//Extended instruction
    _delay_ms(10);
    LCD_Write_Command(0x30);      	//Basic instruction
    _delay_ms(10);
    LCD_Write_Command(0x0C);      	//Display on, cursor off
    _delay_ms(10);
    LCD_Write_Command(0x01);      	//Clear LCD
    _delay_ms(10);
}

void LCD_Clear_lcd(){
    LCD_Write_Command(0x01);        //Clear LCD
    _delay_ms(10);  
}

void LCD_Set_Position(char line, char col)
{                          
   	char  pos;

   	if (line == 0)
     	line = 0x80;
   	else if (line == 1)
   		line =0x90;
   	else if (line == 2)
     	line = 0x88;
   	else if (line == 3)
     	line = 0x98;

   	pos = line + col ;  
   	LCD_Write_Command(pos);     //Set DDRAM Address
}

void LCD_Write_String(char line, char col, char *s) 
{
	
	LCD_Set_Position(line, col);
    
    while(*s != '*')
    {                         
       LCD_Write_Data(*s);
       s++;
    }
}
