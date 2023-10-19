// In this code, the Timer2 of ATmega32a µC is been used, to update the 4-digit 7 segment display


#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define seg_4 0x10
#define seg_3 0x20
#define seg_2 0x40
#define seg_1 0x80

uint8_t cnt =0;
uint16_t number = 0;

void multi_seg(uint16_t num)
{
	PORTB=((seg_4)|(num/1000));
	_delay_us(100);
	
	num%=1000;
	PORTB=((seg_3)|(num/100));
	_delay_us(100);
	
	num%=100;
	PORTB=((seg_2)|(num/10));
	_delay_us(100);
	
	num%=10;
	PORTB=((seg_1)|(num));
	_delay_us(100);
}

ISR(TIMER2_COMP_vect)
{
	cli();
	cnt++;
	if(cnt>4)
	{
		cnt=0;
		number++;
		if(number >9999)
		number =0;
	}
	sei();
}

int main(void)
{
	DDRB=0xff;
	PORTB=0x00;
	_delay_ms(50);
	
	TCCR2|=((1<<WGM21)|(1<<CS22)|(1<<CS21)|(1<<CS20));// timer2 set in CTC mode and prescaled by 1024
	TIMSK |=(1<<OCIE2);
	OCR2=255;// system frequency is 1MHz, so, 1000000 / 1024 = 976.56 and 976 / 255 = 3.83, so the ISR will get called 4 times per second!
	TCNT2=0;
	sei();
	
	while(1)
	{
		multi_seg(number);
	}
}
