/*
 * File:   dc_main.c
 * Author: Asmita Deshpande
 *
 * Created on 11 October, 2023, 12:49 PM
 */


// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic.h>

#define MOTOR1 RB3
#define MOTOR2 RB4

void main() 
{
    unsigned int i;
    TRISB = 0x00;
    
    while(1)
    {
      MOTOR1 = 1;
      MOTOR2 = 0;
      
      for (i=0; i<60; i++);
      
      MOTOR1 = 0;
      MOTOR2 = 1;
    }
}