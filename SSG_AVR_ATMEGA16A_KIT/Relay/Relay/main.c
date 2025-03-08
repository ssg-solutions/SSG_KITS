/*
 * Relay.c
 *
 * Created: 02-08-2024 11:18:20
 * Author : Asmita Deshpande
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main()
{
	PORTB=0x0f;
	DDRB=0x0b;
	while(1)
	{
		PORTB=0x00;
		_delay_ms(1000);
		PORTB=0x0b;
		_delay_ms(1000);
	}
}
