#include <reg51.h> 
 
// Define stepper motor control pins 
sbit Coil1 = P1^0;  // Control pin 1 
sbit Coil2 = P1^1;  // Control pin 2 
sbit Coil3 = P1^2;  // Control pin 3 
sbit Coil4 = P1^3;  // Control pin 4 
 
// Delay function 
void delay(unsigned int count) { 
    unsigned int i, j; 
    for (i = 0; i < count; i++); 
        for (j = 0; j < 500; j++); 
} 
 
// Stepper motor sequence 
void stepperSequence() { 
    Coil1 = 1; 
    Coil2 = 0; 
    Coil3 = 0; 
    Coil4 = 0; 
    delay(10); 
     
    Coil1 = 0; 
    Coil2 = 1; 
    Coil3 = 0; 
    Coil4 = 0; 
    delay(10); 
     
    Coil1 = 0; 
    Coil2 = 0; 
    Coil3 = 1; 
    Coil4 = 0; 
    delay(10); 
     
    Coil1 = 0; 
    Coil2 = 0; 
    Coil3 = 0; 
    Coil4 = 1; 
    delay(10); 
} 
 
void main() { 
    while (1) { 
        stepperSequence(); 
    } 
}
END