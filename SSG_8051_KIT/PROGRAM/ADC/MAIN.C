#include<reg51.h>

#define input P1 //Input port (read values of ADC)
#define output P2 // Output port (connected to LED's)

void delay(unsigned intmsec);

voidadc();

sbit wr = P3 ^ 6; // Write pin.
sbit rd = P3 ^ 7; // Read pin.
sbit intr = P3 ^ 4; // Interrupt pin.

void main()
{
  input = 0xff; // Declare port 1 as input port.
  output = 0x00; // Declare port 0 as output port.

  while (1)
  {
    adc();
  }
}

void delay(unsigned int msec) // Delay function
{
  int i, j;

  for (i = 0; i < msec; i++){
    for (j = 0; j < 1275; j++){
     
    }
  }
}

voidadc() // Reading values from ADC and display on the LED's
{
  rd = 1;
  wr = 0;

  delay(10);

  wr = 1;

  while (intr == 1);
  
  rd = 0;

  output = input;

  delay(10);

  intr = 1;
}