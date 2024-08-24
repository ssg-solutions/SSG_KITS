//Connect P1.24 to Switch1
//Connect P1.25 to Switch2
//Connect P1.26 to Switch3
//Connect P1.16 to LED1
//Connect P1.17 to LED2
//Connect P1.18 to LED3

#include <lpc214x.h>

#define Switch1PinNumber 24
#define Switch2PinNumber 25
#define Switch3PinNumber 26
#define Led1PinNumber    16
#define Led2PinNumber    17
#define Led3PinNumber    18

/* start the main program */
int main()
{
    unsigned int switchStatus1, switchStatus2, switchStatus3;

    PINSEL2 = 0x000000; //Configure the PORT1 Pins as GPIO;

    IODIR1 = ((1<<Led1PinNumber) | (1<<Led2PinNumber) | (1<<Led3PinNumber) | (0<<Switch1PinNumber) | (0<<Switch2PinNumber) | (0<<Switch3PinNumber));
    // LED pins as output and Switch pins as input

    while(1)
    {
        /* Read the switch status */
        switchStatus1 = (IOPIN1>>Switch1PinNumber) & 0x01;
        switchStatus2 = (IOPIN1>>Switch2PinNumber) & 0x01;
        switchStatus3 = (IOPIN1>>Switch3PinNumber) & 0x01;

        /* Turn ON/OFF LEDs depending on switch status */
        if(switchStatus1 == 1)
        {
            IOPIN1 |= (1<<Led1PinNumber);
        }
        else
        {
            IOPIN1 &= ~(1<<Led1PinNumber);
        }

        if(switchStatus2 == 1)
        {
            IOPIN1 |= (1<<Led2PinNumber);
        }
        else
        {
            IOPIN1 &= ~(1<<Led2PinNumber);
        }

        if(switchStatus3 == 1)
        {
            IOPIN1 |= (1<<Led3PinNumber);
        }
        else
        {
            IOPIN1 &= ~(1<<Led3PinNumber);
        }
    }
}