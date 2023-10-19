//Connect P0.7 Pin to Buzzer signal & GND to Ground of LPC2148.
#include  <lpc214x.h>  
#define BUZZ 7 
void Delay(void);
void Wait(void);
 void main()
{
PINSEL0 = 0x00;
//Configure Port0.7 as GPIO 
IODIR0 = 3 << BUZZ;
//Configure Port0.7 as O/P pin 
while(1)
{
IOSET0 = 1 << BUZZ;
Delay();
IOCLR0 = 1 << BUZZ;
 Delay();
}
}
void Delay()
{
unsigned int i,j;
for(i=0;i<1000;i++)
for(j=0;j<700;j++);
}
