// Connect CLK_PIN=13, DATA_PIN=11, CS_PIN=3,VCC=5V & GND=GND of Arduino UNO Board
// Including the required Arduino libraries
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Uncomment according to your hardware type
//#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

// Defining size, and output pins
#define MAX_DEVICES 1
#define CS_PIN 3

// Create a new instance of the MD_Parola class with hardware SPI connection
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  // Intialize the object
  myDisplay.begin();

  // Set the brightness of the display (0-15)
  myDisplay.setIntensity(2);

  // Clear the display
  myDisplay.displayClear();
}

void loop() {
  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("S");
  delay(650);

  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("S");
  delay(650);

  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("G");
  delay(650);

  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("S");
  delay(650);

  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("O");
  delay(650);

  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("L");
  delay(650);

  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("U");
  delay(650);

  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("T");
  delay(650);

  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("I");
  delay(650);

  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("O");
  delay(650);

  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("N");
  delay(650);


  myDisplay.setTextAlignment(PA_LEFT);
  myDisplay.print("S");
  delay(650);


//  myDisplay.setTextAlignment(PA_LEFT);
//  myDisplay.print("T");
//  delay(1500);
}
