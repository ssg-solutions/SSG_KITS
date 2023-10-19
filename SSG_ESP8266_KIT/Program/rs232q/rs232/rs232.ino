 
#include <SoftwareSerial.h>
const byte txPin = 4;
const byte rxPin = 5;
SoftwareSerial max3232(rxPin, txPin);
  
void setup() {

  Serial.begin(9600L);

  pinMode(txPin, OUTPUT);
  pinMode(rxPin, INPUT);

  max3232.begin(9600);
  
  while (!max3232.isListening()) {
    Serial.println("Waiting for MAX3232 to start listening...");
    delay(1000);
  }
  Serial.println("Good, MAX3232 is listening");

}


void loop() {

  Serial.println("Waiting for data on Dylos");

  for (int loops = 0; loops < 120; ++loops) {
    if (max3232.available()) break;
    delay(1000);
  }

  char result[100] = "-1, -1";
  if (max3232.available()) {
    Serial.println("reading Max3232...");
    int i = 0;
    while (max3232.available()) {
      result[i++] = max3232.read();
    }
    result[i] = '\n'; // Just to check it is terminated
  }
  else {
    Serial.println("Timed out");
  }
  
  Serial.println(result);
  
}
