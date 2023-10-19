/****************************************************
       Lesson  : 2
 	   Neme    : LEd chaser
	   Details : 8 leds are connection to Port2 of the 8051 
	             the Annode are common to VCC while the cathode 
				 are connected to each pin of the PORT2
				 the rate of chasing can be adjusted by 
				 changin the delay rate
******************************************************/
#include<REG51.H>
//Fuction Prototypes
void delay(void);
 
// Program Starts Here
void main()
{
	unsigned char a;
	a=0xef;
	
	while(1)
	{
	 P2= a;
	 a = a<<1;
	 if (a==0xf0)
	 a=0xef;

	 
	 delay();
	 }
}

void delay(void)
{
 	unsigned int a,b;
 	for(a=0;a<1000;a++)
		{
			for(b=0;b<50;b++)
			;
		}
}