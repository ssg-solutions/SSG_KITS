/*
 * File:   main.c
 * Author: Asmita Deshpande
 *
 * Created on 11 October, 2023, 10:03 PM
 */// PIC16F877A Configuration Bit Settings
// 'C' source line config statements
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
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

#define _XTAL_FREQ 4000000

void servo0(){
 unsigned int i;
 for(i=0;i<50;i++)
 {
PORTAbits.RA4 = 1;  
__delay_us(800);
 PORTAbits.RA4 = 0;
 __delay_us(19200);}}

void servo90(){
unsigned int i;
 for(i=0;i<50;i++)
 {
PORTAbits.RA4 = 1; 
__delay_us(1500);
PORTAbits.RA4 = 0; 
__delay_us(18500);
 }}

void servo180(){
unsigned int i;
for(i=0;i<50;i++)
 {
PORTAbits.RA4 = 1; 
__delay_us(2200);
PORTAbits.RA4 = 0;
__delay_us(17800);
}}

void main() {
  TRISA4=0x00;
  PORTAbits.RA4 = 0; // Ensure RA4 is initially low

  
  while(1){
   __delay_ms(1000);
  servo0();
  __delay_ms(1000);
  servo90();
  __delay_ms(1000);
  servo180();
  __delay_ms(1000);
  }}