// This code demonstrates the 4x4 keypad array interfaced with ATmega32a µC at PORTB, 
// Since, the output response of the key_presses are being displayed on the hardwired 7 segment display which is using BCD decoder, 
// it can only display the output in proper form upto 0-9 digits, the rest of the key_responses are displayed in terms of symbols as follows:
/*
			DCBA		BCD_output_responses on 7 seg display
			0000		    0
			0001			1
			0010			2
			0011			3
			0100			4
			0101			5
			0110			6	
			0111			7
			1000			8
			1001			9
							 _
			1010			|_   (A)
							 _
			1011			 _|  (B)
			
			1100			|_|  (C)
							 _
			1101			|_
							 _   (D)
							 
			1110			|_	 (E)
							|_		
			
			1111				 (F)
			

*/
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t GetKeyPressed() 
{
	uint8_t r,c;
	PORTB|= 0XF0;
	for(c=0;c<4;c++)
	{
		DDRB&=~(0XFF);
		DDRB|=(0X01 << c);
		for(r=0;r<4;r++)
		{
			if(!(PINB & (0X10 << r)))
			{
				return (r+(c*4));
			}
		}
	}
	return 0XFF;//Indicate No key pressed
}
int main(void)
{
	DDRC|=((1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3));
	PORTC&=~((1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3));
	char array_1[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	uint8_t key;
	while(1)
	{
		key=GetKeyPressed(); //Get the keycode of pressed key
		PORTC=array_1[key];
	}
}

