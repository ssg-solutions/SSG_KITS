// 4 seven seg displays have been interfaced with the atmega32a µC at PORT B in multiplexed manner via a BCD decoder IC SN74LS47
// this code displays a single number at a time on 4 digit seven seg display 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

// control bit of seven seg are  connected at MSB of PORTB, while DATA bits in BCD fashion are connected at LSB of PORTB
#define seg_4 0x10	// 
#define seg_3 0x20
#define seg_2 0x40
#define seg_1 0x80

 

int main(void)
{
	DDRB=0xff;
	PORTB=0x00;
	uint16_t num = 1234;
	while(1)
	{
		
		num = 1234;
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
}