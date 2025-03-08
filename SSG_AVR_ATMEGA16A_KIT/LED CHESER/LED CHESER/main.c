
/*
 * ATmega32_LED_Blinking.c
 
 */ 

#define F_CPU 1000000UL	/* Define CPU frequency here 8MHz */
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
   
    DDRC = 0b11110000; 
    _delay_ms(500);;	/* Make all pins of PORTB as output pins */
	
	while (1)		/* Blink PORTB infinitely */
    {
	
	PORTC = 0b10000000;// pin 0 of port c set HIGH
	_delay_ms(100);	/* Delay of 100 milli second */
	PORTC = 0b01000000;// pin 1 of port c set HIGH
	_delay_ms(100);	/* Delay of 100 milli second */
	_delay_ms(100);	/* Delay of 100 milli second */
	PORTC = 0b00100000;// pin 2 of port c set HIGH
	_delay_ms(100);	/* Delay of 100 milli second */
	PORTC = 0b00010000;// pin 3 of port c set HIGH
	_delay_ms(100);	/* Delay of 100 milli second */
	
    }
}

