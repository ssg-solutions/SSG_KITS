/****************************************************
       Lesson  : 1
 	   Neme    : LEd Blink
	   Details : 8 leds are connection to Port2 of the 8051 
	             the Annode are common to VCC while the cathode 
				 are connected to each pin of the PORT2
				 the rate of blinking can be adjusted by 
				 changin the delay rate
******************************************************/
#include<REG51.H>
//Fuction Prototypes
void delay(void);
 
// Program Starts Here
void main()
{
	P2 = 0x00; // Leds are ON
	delay();
	P2 = 0xff; // Leds are OFF
	delay(); 
}

void delay(void)
{
 	unsigned int a,b;
 	for(a=0;a<1000;a++)
		{
			for(b=0;b<120;b++)
			;
		}
}