//CONNECT A0 & 12 pin of UNO with D0 pin of LDR & LED pin also connect GND=GND & VCC=5V of LDR
// Interfacing Arduino uno with LDR sensor
#define ledPin 12
//const int ledPin = 1; // digital pin 5 
const int ldrPin = A0; // analog pin 0
void setup() { // The setup() function will only run once, after each powerup or reset of the Arduino board.
Serial.begin(9600);
pinMode(ledPin, OUTPUT); // Here LED is determined as an output or an indicator.
pinMode(ldrPin, INPUT); // Here LDR sensor is determined as input.
}
void loop() { // Void loop is ran again and again and contains main code.
int ldrStatus = analogRead(ldrPin);
if (ldrStatus > 1000) 
{
digitalWrite(ledPin, HIGH); // If LDR senses darkness led pin high that means led will glow.
Serial.print("Darkness over here");
Serial.println(ldrStatus);
} else {
digitalWrite(ledPin, LOW); // If LDR senses light led pin low that means led will stop glowing.
Serial.print("There is sufficient light");
Serial.println(ldrStatus);
}
}
