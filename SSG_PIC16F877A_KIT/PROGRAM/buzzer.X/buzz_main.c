/*
 * File:   buzz_main.c
 * Author: Asmita Deshpande
 *
 * Created on 28 September, 2023, 1:56 PM
 */


// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 4000000  // 20MHz crystal oscillator frequency

void main() {
    TRISD0 = 0;  // Set RB0 as an output
    RD0 = 0;     // Initially, turn off the buzzer

    while (1) {
        RD0 = 1;     // Turn on the buzzer (active high)
        __delay_ms(5000); // Delay for 500 ms (adjust as needed)
        RD0 = 0;     // Turn off the buzzer
        __delay_ms(5000); // Delay for 500 ms (adjust as needed)
    }
}
