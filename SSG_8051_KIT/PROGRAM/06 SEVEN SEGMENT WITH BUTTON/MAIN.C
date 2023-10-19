	 /****************************************************
       Lesson  : 6
 	   Neme    : seven segment
	   Details : A seven segment display is connected through a 
	   			 7447 ic which is bcd to 7 segment driver IC.
				 the BCD inputs are connected to port3.4 to
				 port3.7 of the 8051. the table for 1-9 is
				 -----------------------------
				 BCD	|	7 SEGMENT OUTPUT
				 -----------------------------
				 0000	|	0
				 0001	|	1
				 0010	|	2
				 0011	|	3
				 0100	|	4
				 0101	|	5
				 0110	|	6
				 0111	|	7
				 1000	|	8
				 1001	|	9
				 When each button is pressed the display 
				 shows the no of pressed button
******************************************************/
#include<REG51.H>
//Fuction Prototypes
void delay(void);
 
// Program Starts Here
void main()
{
	P2=0xff;
	P0=0X00;
	while(1)
	{
		if((P2 & 0x0f) == 0x0e)
		{
		P0= 0x10;
		delay(); 
		}
		else if ((P2 & 0x0f) == 0x0d)
		{
		P0=0x20;
		delay();
		}
		else if ((P2 & 0x0f) == 0x0b)
		{
		P0=0x30;
		delay();
		}
		else if ((P2 & 0x0f) == 0x07)
		{
		P0=0x40;
		delay();
		}
		else
		P0=0x00;
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