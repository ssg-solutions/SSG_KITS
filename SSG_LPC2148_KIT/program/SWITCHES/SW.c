//Connect P1.24  to Switch
//Connect P1.16  to LED
#include <lpc214x.h>   

#define SwitchPinNumber 24
#define LedPinNumber    16

/* start the main program */
int main() 
{
    unsigned int  switchStatus;

    PINSEL2 = 0x000000; //Configure the PORT1 Pins as GPIO;
    
    IODIR1 = ((1<<LedPinNumber) | (0<<SwitchPinNumber)); // LED pin as output and Switch Pin as input //Configure P1.24 - P1.31 as Input & P1.16 - P1.23 as Output


  while(1)
    {

     /* Turn On all the leds and wait for one second */ 
       switchStatus = (IOPIN1>>SwitchPinNumber) & 0x01 ;  // Read the switch status
       
       if(switchStatus == 1)                 //Turn ON/OFF LEDs depending on switch status
       {  
         IOPIN1 = (1<<LedPinNumber);
       }
       else
       {
         IOPIN1 = (0<<LedPinNumber);
       }      
    }
}

