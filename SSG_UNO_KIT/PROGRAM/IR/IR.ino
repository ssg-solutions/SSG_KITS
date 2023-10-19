//connect 7 TO IR PROXI DOUT & 6 TO LED PIN
int IRSensor = 7; 

int LED = 6; 

void setup()

{
Serial.begin(115200); // Init Serila at 115200 Baud
Serial.println("Serial Working"); // Test to check if serial is working or not
pinMode(IRSensor, INPUT); // IR Sensor pin INPUT
pinMode(LED, OUTPUT); // LED Pin Output
}
void loop()
{
int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input
if (sensorStatus == 1) // Check if the pin high or not
{
// if the pin is high turn off the onboard Led
 digitalWrite(LED,LOW); // LED LOW
Serial.println("OBJECT DETECTED"); // print Motion Detected! on the serial monitor window
}
else
  {
    //else turn on the onboard LED
    digitalWrite(LED, HIGH); // LED High
    Serial.println(" OBJECT NOT DETECTED"); // print Motion Ended! on the serial monitor window
  }
delay(500);
}
