//connect A0 pin of UNO to   A0 of AOI and VCC=5V ,GND=GND
 //OLED Display libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels
#define OLED_RESET 4  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int SensorPin = A0;// Sensor pin connected to Analog pin "A0"
int RedLed = 7;    // Red LED pin connected to Digital pin "D7"
int GreenLed = 8;  // Green LED pin connected to Digital pin "D8"
int Buzzer = 9;    // Buzzer pin connected to Digital pin "D9"

int SensorVal = 0;

void setup()
{
  pinMode(SensorPin, INPUT); // initialize digital pin SensorPin as an input.
  pinMode(RedLed, OUTPUT);   // initialize digital pin RedLed as an output.
  pinMode(GreenLed, OUTPUT); // initialize digital pin GreenLed as an output.
  pinMode(Buzzer, OUTPUT);   // initialize digital pin Buzzer as an output.
  //Start serial communication between arduino and your computer
  Serial.begin(9600);
  //initialize with the I2C addr 0x3C (128x64)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  delay(10);
  // Print text on display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("ELECTRODUIN0"); // Print text
  display.display();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30,19);
  display.println("Smoke");
  display.display();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(15,35);
  display.println("Detector");
  display.display();
  delay(2000);

}


  void loop()
  {
    // Read Senso value
    SensorVal = analogRead(SensorPin);
    // Print Senso value on Serial Monitor Window
    Serial.print("Air Quality: ");  
    Serial.print(SensorVal);
    Serial.println("  PPM");   
    Serial.println();
    //Print Senso value or Air Quality Index on OLED Display
    display.clearDisplay();
    display.setCursor(0,0);  //oled display
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.println("Air Quality Index");
    display.setCursor(0,18);  //oled display
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.print(SensorVal);
    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.println(" PPM");
    display.display();
    //delay(2000);
    // when Smoke level value less than 400PPM
    if (SensorVal<200)
     {
      Serial.print(" | Fresh Air!");
      digitalWrite(GreenLed,HIGH); // turn the Green LED on
      digitalWrite(RedLed,LOW);    // turn the Red LED off
      digitalWrite(Buzzer,LOW);    // turn the Buzzer off 
      // Print text on OLED Display
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,45);
      display.println("Fresh Air"); // Print text
      display.display();
      delay(2000);
     }
    // when Smoke level value greater than 400PPM   
    else if( SensorVal>250)
     {
      Serial.print(" | Smoke detected!");
      digitalWrite(GreenLed,LOW);  // turn the Green LED off
      digitalWrite(RedLed,HIGH);   // turn the Red LED on
      digitalWrite(Buzzer,HIGH);   // turn the Buzzer on
      // Print text on OLED Display
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,45);
      display.println("Smoke/Fire"); // Print text
      display.display();
      delay(2000);
     }
    }
