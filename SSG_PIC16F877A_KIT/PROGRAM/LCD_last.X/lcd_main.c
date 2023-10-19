/*
 * File:   lcd_main.c
 * Author: Asmita Deshpande
 *
 * Created on 10 October, 2023, 10:05 PM
 */




#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "config.h"

#define RS RB0
#define RW RB1
#define EN RB2
#define D4 RB4
#define D5 RB5
#define D6 RB6
#define D7 RB7

#include "lcd.h"

void main()
{
    TRISB = 0x00;
    Lcd_Init();
    while(1)
    {
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("Welcome");
        
        __delay_ms(2000);
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("All");
        
        Lcd_Clear();
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("..Hello World..");
        
        for(int i=0; i<14; i++)
        {
            __delay_ms(350);
            Lcd_Shift_Right();
        }
        
        for(int i=0; i<14; i++)
        {
            __delay_ms(350);
            Lcd_Shift_Left();
        }
    }
}