//Connect P0.12 ,P0.13 ,P0.14 & P0.15  TO  LED PINS.
    	
#include <lpc214x.h>            //include header files for LPC-214x series


void delay()
{
int i,j;
 for(i=0;i<2000;i++)
for(j=0;j<2000;j++);
}

void main()
{
PINSEL0=0;
PINSEL1=1;
IODIR0=0xFF<<12; //P0.12 to P0.19 as output pins
while(1)
{
IOSET0=0xFF<<12;  //LED ON
delay();
IOCLR0=0xFF<<12;//LED OFF
delay();
}
}



