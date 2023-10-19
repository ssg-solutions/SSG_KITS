//Connect  P0.0 & P0.1 to M1A & M1B
#include<lpc214x.h>
#define bit(x) (1<<x)
#define delay for(i=0;i<=100000;i++)
unsigned int i;
int main()
{
    IO0DIR=0xf;                     //Declaring as a output
    IO0PIN=0;                           //Clear all IO Pins in P0
    VPBDIV=0x01;                    //PCLK = 60MHz
    while(1) {
        /*Forward*/
        IO0SET=bit(0);          //IN1 = 1
        IO0CLR=bit(1);          //IN2 = 0
        delay;delay;
        /*Off*/
        IO0CLR=bit(0)|bit(1); //IN1 = IN2 = 0
        delay;delay;
        /*Reverse*/
        IO0SET=bit(1);          //IN2 = 1
        IO0CLR=bit(0);          //IN0 = 1
        delay;delay;
        /*Off*/
        IO0CLR=bit(0)|bit(1); //IN1 = IN2 = 0
        delay;delay;
    }
}