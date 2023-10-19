// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (HS oscillator)
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

#define _XTAL_FREQ 4000000  // 4MHz Crystal oscillator frequency (Change this to match your oscillator)

#include <pic16f877a.h>

#define  bcd1 RD4
#define  bcd2 RD5 
#define  bcd3 RD6
#define  bcd4 RD7 

void main()
{
    // Set PORTD as input for BCD inputs
    TRISD = 0x0F;
    
    while(1)
    {
       // Display 0
        bcd1 = 0;
        bcd2 = 0;
        bcd3 = 0;
        bcd4 = 0;
        __delay_ms(1000);
        
        // Display 1
        bcd1 = 1;
        bcd2 = 0;
        bcd3 = 0;
        bcd4 = 0;
        __delay_ms(1000);
        
        // Display 2
        bcd1 = 0;
        bcd2 = 1;
        bcd3 = 0;
        bcd4 = 0;
        __delay_ms(1000);
        
        // Display 3
        bcd1 = 1;
        bcd2 = 1;
        bcd3 = 0;
        bcd4 = 0;
        __delay_ms(1000);
        
        // Display 4
        bcd1 = 0;
        bcd2 = 0;
        bcd3 = 1;
        bcd4 = 0;
        __delay_ms(1000);
        
        // Display 5
        bcd1 = 1;
        bcd2 = 0;
        bcd3 = 1;
        bcd4 = 0;
        __delay_ms(1000);
        
        // Display 6
        bcd1 = 0;
        bcd2 = 1;
        bcd3 = 1;
        bcd4 = 0;
        __delay_ms(1000);
        
        // Display 7
        bcd1 = 1;
        bcd2 = 1;
        bcd3 = 1;
        bcd4 = 0;
        __delay_ms(1000);
        
        // Display 8
        bcd1 = 0;
        bcd2 = 0;
        bcd3 = 0;
        bcd4 = 1;
        __delay_ms(1000);
        
         // Display 9
        bcd1 = 1;
        bcd2 = 0;
        bcd3 = 0;
        bcd4 = 1;
        __delay_ms(1000);
    }
}