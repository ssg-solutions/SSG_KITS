/*
 * BUTTON.c
 *
 * Created: 02-08-2024 12:19:45
 * Author : Asmita Deshpande
 */ 


#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	//unsigned char i;
	
	
	DDRA=0x00;
	PORTA =0xff;
	DDRC=0xff;
	PORTC=0xff;
	// makes the Port 1 as input port
	while(1)
	{
		int i;
		i = PINA;
		i = i & 0x0f;
		if (i == 0x0e)
		{
			PORTC=0xef;
		}
		if (i == 0x0d)
		{
			PORTC=0xdf;
		}
		if (i == 0x0b)
		{
			PORTC=0xbf;
		}
		if (i == 0x07)
		{
			PORTC=0x7f;
		}
		
		
		
	}
}


