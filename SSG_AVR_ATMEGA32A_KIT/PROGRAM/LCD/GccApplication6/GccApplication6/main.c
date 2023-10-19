/*
 * GccApplication6.c
 *
 * Created: 12/14/2022 3:32:25 PM
 * Author : Praful
 */ 

//#include <avr/io.h>


/*  
   LCD16x2 4 bit ATmega16 interface
   http://www.electronicwings.com
*/

//#ifndef F_CPU
#define F_CPU 1000000UL // 16 MHz clock speed
//#endif
#define D4 eS_PORTB4
#define D5 eS_PORTB5
#define D6 eS_PORTB6
#define D7 eS_PORTB7
//#define RS eS_PORTB0
//#define EN eS_PORTB2
//#define E  eS_PORTB3
#define Back_light PORTB
//#define EN PB2
//#define F_CPU 8000000UL					/* Define CPU Frequency e.g. here its 8MHz */
		/* Include inbuilt defined Delay header file */
//#include "lcd.h" //Can be download from the bottom of this article
#include <avr/io.h>						/* Include AVR std. library file */
#include <util/delay.h>
#define LCD_Dir DDRB					/* Define LCD data port direction */
#define LCD_Port PORTB					/* Define LCD data port */
#define RS PB0							/* Define Register Select (data reg./command reg.) signal pin */
#define EN PB2 							/* Define Enable signal pin */
#define BL PB3

void LCD_Command( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0); /* sending upper nibble */
	LCD_Port &= ~ (1<<RS);				/* RS=0, command reg. */
	LCD_Port |= (1<<EN);				/* Enable pulse */
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);  /* sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}


void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0); /* sending upper nibble */
	LCD_Port |= (1<<RS);				/* RS=1, data reg. */
	LCD_Port|= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port = (LCD_Port & 0x0F) | (data << 4); /* sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_Init (void)					/* LCD Initialize function */
{
	
	LCD_Dir = 0xFF;						/* Make LCD command port direction as o/p */
	_delay_ms(20);						/* LCD Power ON delay always >15ms */
	LCD_Port |= (1<<BL);
	LCD_Command(0x33);
	LCD_Command(0x32);		    		/* send for 4 bit initialization of LCD  */
	LCD_Command(0x28);              	/* Use 2 line and initialize 5*7 matrix in (4-bit mode)*/
	LCD_Command(0x0c);              	/* Display on cursor off*/
	LCD_Command(0x06);              	/* Increment cursor (shift cursor to right)*/
	LCD_Command(0x01);              	/* Clear display screen*/
	_delay_ms(2);
	LCD_Command (0x80);					/* Cursor 1st row 0th position */
}


void LCD_String (char *str)				/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)				/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);		/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);		/* Command of first row and required position<16 */
	LCD_String(str);					/* Call LCD string function */
}

void LCD_Clear()
{
	LCD_Command (0x01);					/* Clear display */
	_delay_ms(2);
	LCD_Command (0x80);					/* Cursor 1st row 0th position */
}
 
int main()
{

	LCD_Init();							/* Initialization of LCD*/

	LCD_String("SSG");		/* Write string on 1st line of LCD*/
	LCD_Command(0xc0);					/* Go to 2nd line*/
	LCD_String("Hello World");			/* Write string on 2nd line*/
	while(1);
}
 

