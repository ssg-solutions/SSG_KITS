/*
 * lcd_chk_m16.c
 *
 * Created: 31-07-2024 15:13:41
 * Author : Asmita Deshpande
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"


int main(void)
{
    /* Replace with your application code */
	uint8_t i=0;
	// enable the backlight
	DDRB|=(1<<PB3);// 
	PORTB|=(1<<PB3);
	
	
	LCDInit(LS_NONE);
	LCDWriteString("LCD_Initialised!");
	_delay_ms(3000);
	
    while (1) 
    {
		LCDClear();
		LCDWriteString("AVR_Rocks!");
		LCDGotoXY(0,1);
		LCDWriteString("i=");
		LCDWriteInt(i,4);
		
		i++;
		if(i>255)
		i=0;
		_delay_ms(1000);
    }
}

