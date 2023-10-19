#define F_CPU 1000000UL			/* Define CPU Frequency e.g. here 8MHz */
#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */
#include <stdlib.h>

#define LCD_Dir  DDRB			/* Define LCD data port direction */
#define LCD_Port PORTB			/* Define LCD data port */
#define RS PB0				/* Define Register Select pin */
#define RW PB1
#define EN PB2 				/* Define Enable signal pin */
#define BL PB3


/*
	Now we successfully initialized LCD & it is ready to accept data in 4-bit mode to display.

To send command/data to 16x2 LCD we have to send higher nibble followed by lower nibble. 
As 16x2 LCD’s D4 - D7 pins are connected as data pins, we have to shift the lower nibble to the right by 4 before transmitting.

Command write function

First, send a Higher nibble of command.
Make RS pin low, RS=0 (command reg.)
Make RW pin low, RW=0 (write operation) or connect it to ground.
Give High to Low pulse at Enable (E).
Send lower nibble of command.
Give High to Low pulse at Enable (E).
*/
void LCD_Command( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);/* Sending upper nibble */
	LCD_Port &= ~ (1<<RS);		/* RS=0, command reg. */
	LCD_Port&=~(1<<RW);
	LCD_Port|=(1<<BL);
	LCD_Port |= (1<<EN);		/* Enable pulse */
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);/* Sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

/*

Wait for 15ms, Power-on initialization time for LCD16x2.
Send 0x02 command which initializes LCD 16x2 in 4-bit mode.
Send 0x28 command which configures LCD in 2-line, 4-bit mode, and 5x8 dots.
Send any Display ON command (0x0E, 0x0C)
Send 0x06 command (increment cursor)

*/
void LCD_Init (void)  /* LCD Initialize function */
{
	LCD_Dir = 0xFF;		/* Make LCD port direction as o/p */
	_delay_ms(20);		/* LCD Power ON delay always >15ms */
	
	LCD_Command(0x33);
	LCD_Command(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_Command(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	LCD_Command(0x0c);	/* Display on cursor off */
	LCD_Command(0x06);	/* Increment cursor (shift cursor to right) */
	LCD_Command(0x01);	/* Clear display screen */
}

/*
	Data write function

First, send a Higher nibble of data.
Make RS pin high, RS=1 (data reg.)
Make RW pin low, RW=0 (write operation) or connect it to ground.
Give High to Low pulse at Enable (E).
Send lower nibble of data.
Give High to Low pulse at Enable (E).
*/

void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);/* Sending upper nibble */
	LCD_Port |= (1<<RS);  /* RS=1, data reg. */
	LCD_Port&=~(1<<RW);
	LCD_Port|= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (data << 4);  /* Sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}

/*

*/

void LCD_String (char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD with xy position */
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_String(str);		/* Call LCD string function */
}

void LCD_Clear()
{
	LCD_Command (0x01);		/* Clear display */
	_delay_ms(2);
	LCD_Command (0x80);		/* Cursor at home position */
}

int main()
{
	char int2string[5];

	LCD_Init();			/* Initialization of LCD*/

	LCD_String("SSG_Embedded_AVR");	/* Write string on 1st line of LCD*/
	LCD_Command(0xC0);		/* Go to 2nd line*/
	LCD_String("Hello World");	/* Write string on 2nd line*/
	_delay_ms(5000);
	while(1){
		for(uint8_t i = 0; i<9999; i++)// lets display an integer value on LCD
		{
			
			itoa(i,int2string,10);
			LCD_String_xy(0,0,"                ");
			LCD_String_xy(0, 3, int2string);
			
			_delay_ms(1000); /* wait for 1 second */
			
			
		}
		
		
	}
}
