

/*
 * ATmega32_LED_Blinking.c
 
 */ 

#define F_CPU 1000000UL	/* Define CPU frequency here 8MHz */
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
	DDRC = 0xF0;	/* Make all pins of PORTD as output pins */
	
	while (1)		/* Blink PORTD infinitely */
	{
		
		PORTC = 0x00;
		_delay_ms(500);	/* Delay of 500 milli second */
		PORTC = 0xF0;
		_delay_ms(500);
	}
}
