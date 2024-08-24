/*
 * led.c
 *
 * Created: 01-08-2024 14:00:48
 * Author : Asmita Deshpande
 */ 

#include <avr/io.h>

#define F_CPU 1000000UL //cpu frequency
#include <util/delay.h>

int main(void)
{
	PORTC = 0x00; 
	
    /* Replace with your application code */
    while (1) 
    {
		PORTC =~ PORTC;
		_delay_ms(500);
    }
}

