/*
 * buzzer.c
 *
 * Created: 02-08-2024 11:20:29
 * Author : Asmita Deshpande
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
	PORTD=0x00;
	DDRD=0xfd;
	while(1)
	{
		PORTD=0x00;
		_delay_ms(1000);
		PORTD=0xfd;
		_delay_ms(1000);
	}
}