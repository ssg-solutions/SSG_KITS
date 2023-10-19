/*
 * File:   main.c
 * Author: Asmita Deshpande
 *
 * Created on 7 October, 2023, 2:18 PM
 */


#define _XTAL_FREQ 4000000

#include <xc.h>

void init_config(void);
// CONFIG
#pragma config FOSC = XT      // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#define LED_ARRAY_DDR TRISC
#define LED_ARRAY     PORTC

int main()
{
    init_config();
    unsigned int delay;
    unsigned char led_mask = 0b00000001; // Start with RC0 (bit 0)

    while(1)
    {LED_ARRAY = led_mask;
        led_mask <<= 1; // Shift the mask to the left
        if (led_mask == 0b00010000) // If all LEDs have been lit, reset to RC0
            led_mask = 0b00000001;

        for(delay = 10000; delay > 0; delay--);
    }
}
void init_config(void)
{
   LED_ARRAY_DDR = 0X00;
   LED_ARRAY = 0x00;
}