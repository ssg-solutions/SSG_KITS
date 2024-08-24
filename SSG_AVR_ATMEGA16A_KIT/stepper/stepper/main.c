#define F_CPU 1000000UL	/* Define CPU frequency here 8MHz */
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	
	DDRB = 0xFF;
	_delay_ms(500);;	/* Make all pins of PORTB as output pins */
	
	while (1)		/* Blink PORTB infinitely */
	{
		
		PORTB = 0b00000001;// pin 0 of port c set HIGH
		_delay_ms(10);	/* Delay of 100 milli second */
		PORTB = 0b00000010;// pin 1 of port c set HIGH
		_delay_ms(10);	/* Delay of 100 milli second */
		PORTB = 0b00000100;// pin 2 of port c set HIGH
		_delay_ms(10);	/* Delay of 100 milli second */
		PORTB = 0b00001000;// pin 3 of port c set HIGH
		_delay_ms(10);	/* Delay of 100 milli second */
		
	}
}

