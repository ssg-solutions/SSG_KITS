#include<REG51.H>
//Fuction Prototypes
void delay(void);
 
// Program Starts Here
void main()
{
	P1 = 0x00; // Leds are ON
	delay();
	P1 = 0xff; // Leds are OFF
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