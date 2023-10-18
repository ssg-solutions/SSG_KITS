
//D4 TO DHT11 PIN
#include <dht.h>  // Include DHT11 library
#define DATApin 4  // Defines Arduino pin which is connected to the sensor

dht DHT;      // Creates a DHT object

void setup() 
 {
  //Sets the baud for serial data transmission between Arduino and your computer
  Serial.begin(9600);
 }

void loop() 
 {
  // Read data from Sensor
  int readData = DHT.read11(DATApin);

  float TC = DHT.temperature;  // Read Temperature in Degree Celsius unit
  float TF = ((TC*9.0)/5.0+32.0); // Convert Celsius to Fahrenheit unit
  
  float h = DHT.humidity;   // Read humidity

  //Print Tempareture Value on Serial Monitor Window
  Serial.print("Temperature = ");
  Serial.print(TC);  // Temperature value in Degree Celsius
  Serial.print("°C | ");
  Serial.print(TF);  // Temperature value in Fahrenheit
  Serial.println("°F ");

  //Print Humidity Value on Serial Monitor Window
  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println("% ");
  Serial.println("");

  delay(2000); // wait two seconds
}
