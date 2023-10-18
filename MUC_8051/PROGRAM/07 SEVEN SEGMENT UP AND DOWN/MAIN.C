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
				 WHEN SW1 IS PRESSED THE COUNTER IN INCREMENTED 
				 WHEN SW2 IS PRESED THE COUNTER IS DECREMENTED
******************************************************/
#include<REG51.H>
//Fuction Prototypes
void delay(void);
sbit sw1=P2^0;
sbit sw2=P2^1;
void delayms(unsigned int tt); 
// Program Starts Here
void main()
{
	unsigned char a,b;
	P2=0xff;
	a=0;
	while(1)
	{
		if(sw1 == 0)
		{
		    delayms(20);
			while(sw1==0);
			a++;
			b=a>>4;
		 	b |= a<<4;
		 							 
		}
		else if (sw2 == 0)
		{
			delayms(20);
			while(sw2==0);
			if(a>0)
			a--;
			b=a>>4;
		 	b |= a<<4;
		 			
		}
		P0 = b ;
		
	}
}

void delayms(unsigned int tt)
{
 	unsigned int a,b;
 	for(a=0;a<tt;a++)
		{
			for(b=0;b<1275;b++)
			;
		}
}