#include<reg51.h>
sbit stepper1=P1^0;
sbit stepper2=P1^1;
sbit stepper3=P1^2;
sbit stepper4=P1^3;
void delay(unsigned int count) { 
    unsigned int i, j; 
    for (i = 0; i < count; i++) 
        for (j = 0; j < 500; j++); 
} 

void main()
{
	delay(50);
while(1)
{
	
stepper1 = 1;
stepper2 = 0;
stepper3 = 0;
stepper4 = 0;
	delay(5);
	stepper1 = 0;
stepper2 = 1;
stepper3 = 0;
stepper4 = 0;
	delay(5);
	stepper1 = 0;
stepper2 = 0;
stepper3 = 1;
stepper4 = 0;
	delay(5);
	stepper1 = 0;
stepper2 = 0;
stepper3 = 0;
stepper4 = 1;
	delay(5);
}
}