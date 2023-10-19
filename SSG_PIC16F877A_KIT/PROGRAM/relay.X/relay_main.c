/*
 * File:   relay_main.c
 * Author: Asmita Deshpande
 *
 * Created on 11 October, 2023, 12:59 PM
 */


// CONFIG

#pragma config FOSC = XT       // Oscillator Selection bits (HS oscillator)

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)

#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)

#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)

#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)

#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)

#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


 


#include <xc.h>

// Hardware related definition
#define _XTAL_FREQ 4000000 // Crystal Frequency, used in delay
#define RELAY RB0

void main(void)
{
   RELAY = 0;
   
   TRISB0 = 0x00;
   

    while(1) {
        // Toggle the relay state based on the LED state
        
        RELAY = 1;
         __delay_ms(500);
         RELAY = 0;
         __delay_ms(500);
    }
    return;
}

