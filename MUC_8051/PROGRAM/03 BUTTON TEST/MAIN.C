/****************************************************
       Lesson  : 3
 	   Neme    : Button Test
	   Details : 8 buttons are connected to port1, 
	             the initial value of the port is HIGH(1)
				 when the button is prssed the value is LOW(0)
	   			 8 leds are connection to Port2 of the 8051 
	             the Annode are common to VCC while the cathode 
				 are connected to each pin of the PORT2
				 when each button is pressed the same currospond 
				 led at port2 is glow.
******************************************************/
#include<REG51.H>
//Fuction Prototypes
void delay(void);
 
// Program Starts Here
void main()
{
	P2 = 0xFF; // makes the Port 1 as input port
	while(1)
	{
	    if((P2 & 0x0f) == 0x0e)
		{
		P2= (P2 & 0x0f)| 0xe0;
		delay(); 
		}
		else if ((P2 & 0x0f) == 0x0d)
		{
		P2=(P2 & 0x0f)|0xd0;
		delay();
		}
		else if ((P2 & 0x0f) == 0x0b)
		{
		P2=(P2 & 0x0f)|0xb0;
		delay();
		}
		else if ((P2 & 0x0f) == 0x07)
		{
		P2=(P2 & 0x0f)|0x70;
		delay();
		}
		
		P2=0xff;
	 }
}

void delay(void)
{
 	unsigned int a,b;
 	for(a=0;a<10;a++)
		{
			for(b=0;b<120;b++)
			;
		}
}