//Connect P0.0 ,P0.1 ,P0.4 ,P0.5 ,P0.6 ,P0.7 ,P0.8,P0.9 to A,B,C,D,E ,F,G ,H respectively.
//Connect H to GND.
//Connect P0.16 ,P0.17 (OR P0.18 ,P0.19 ,P0.20 ,P0.21 ,P0.22) to  S1,S2 respectively.



//INTERFACING SINGLE SEVEN SEGMENT MODULE WITH LPC2148


#include<lpc214x.h>            //Header file for LPC214x Series microcontrollers

void delay(int );              //Function declaration for delay

int i;                         //Variable declared as integer
																	 // 0x100,0x1E1,0x90,0xC0,0x61,0x42,0x02,0x1E0,0x000,0x40
unsigned int a[]={0x100,0x1E1,0x90,0xC0,0x61,0x42,0x02,0x1E0,0x000,0x40}; //integer array with numbers for display

int main()

{ 

    IO0DIR=IO0DIR|0xffffffff;              //Sets direction as output for PORT 0 pins

    while(1)

    {

        for(i=0;i<=9;i++)

        {

            IO0SET=IO0SET|a[i];           //sets corresponding pins HIGH

            delay(9000);                  //Calls delay function

            IO0CLR=IO0CLR|a[i];           //Sets corresponding pins LOW

        }

    }

    return 0;

}


void delay(int k)              //Function for making delay

{

    int i,j;

    for(i=0;i<k;i++)

    for(j=0;j<=1000;j++);

}
