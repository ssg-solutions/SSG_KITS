 /*
 * File:   stepper_main.c
 * Author: Asmita Deshpande
 *
 * Created on 11 October, 2023, 11:46 AM
 */


#include <xc.h>
#include <stdio.h>
#include "config.h"

#define _XTAL_FREQ  4000000 


#define speed 1 // Speed Range 10 to 1  10 = lowest , 1 = highest

#define steps 250 // how much step it will take

#define clockwise 0 // clockwise direction macro

#define anti_clockwise 1 // anti clockwise direction macro

 //FUNCTION TO OPERATE MOTOR 

void system_init (void); // This function will initialise the ports.

void full_drive (char direction); // This function will drive the motor in full drive mode

void half_drive (char direction); // This function will drive the motor in full drive mode

void wave_drive (char direction); // This function will drive the motor in full drive mode

void ms_delay(unsigned int val);
 

void main(void)

{

system_init();

while(1){

/* Drive the motor in full drive mode clockwise */

for(int i=0;i<steps;i++)

{

            full_drive(clockwise);

}

ms_delay(1000);


/* Drive the motor in wave drive mode anti-clockwise */

for(int i=0;i<steps;i++)

{

            wave_drive(anti_clockwise);

            //full_drive(anti_clockwise);

}

ms_delay(1000);

}

}

/*System Initialising function to set the pin direction Input or Output*/
void system_init (void){

    TRISB = 0x00;     // PORT B as output port

    PORTB = 0x0F;

}

/*This will drive the motor in full drive mode depending on the direction*/
void full_drive (char direction){

    if (direction == anti_clockwise){

        PORTB = 0b00000011;

        ms_delay(speed);

        PORTB = 0b00000110;

        ms_delay(speed);

        PORTB = 0b00001100;

        ms_delay(speed);

        PORTB = 0b00001001;

        ms_delay(speed);

        PORTB = 0b00000011;

        ms_delay(speed);

    }

    if (direction == clockwise){

        PORTB = 0b00001001;

        ms_delay(speed);

        PORTB = 0b00001100;

        ms_delay(speed);

        PORTB = 0b00000110;

        ms_delay(speed);

        PORTB = 0b00000011;

        ms_delay(speed);

        PORTB = 0b00001001;

        ms_delay(speed);

    }
}

/* This method will drive the motor in half-drive mode using direction input */
void half_drive (char direction){

    if (direction == anti_clockwise){

        PORTB = 0b00000001;

        ms_delay(speed);

        PORTB = 0b00000011;

        ms_delay(speed);

        PORTB = 0b00000010;

        ms_delay(speed);

        PORTB = 0b00000110;

        ms_delay(speed);

        PORTB = 0b00000100;

        ms_delay(speed);

        PORTB = 0b00001100;

        ms_delay(speed);

        PORTB = 0b00001000;

        ms_delay(speed);

        PORTB = 0b00001001;

        ms_delay(speed);

    }

    if (direction == clockwise){

       PORTB = 0b00001001;

       ms_delay(speed);

       PORTB = 0b00001000;

       ms_delay(speed);

       PORTB = 0b00001100;

       ms_delay(speed); 

       PORTB = 0b00000100;

       ms_delay(speed);

       PORTB = 0b00000110;

       ms_delay(speed);

       PORTB = 0b00000010;

       ms_delay(speed);

       PORTB = 0b00000011;

       ms_delay(speed);

       PORTB = 0b00000001;

       ms_delay(speed);
    }

}

/* This function will drive the the motor in wave drive mode with direction input*/
void wave_drive (char direction){

    if (direction == anti_clockwise)
    {
        PORTB = 0b00000001;

        ms_delay(speed);

        PORTB = 0b00000010;

        ms_delay(speed);

        PORTB = 0b00000100;

        ms_delay(speed);

        PORTB = 0b00001000;

        ms_delay(speed);

    }
     if (direction == clockwise){

        PORTB = 0b00001000;

        ms_delay(speed);

        PORTB = 0b00000100;

        ms_delay(speed);

        PORTB = 0b00000010;

        ms_delay(speed);

        PORTB = 0b00000001;

        ms_delay(speed);

    }

    

}

/*This method will create required delay*/
void ms_delay(unsigned int val)
{

     unsigned int i,j;

        for(i=0;i<val;i++)

            for(j=0;j<1650;j++);

}