//CONNECT D2 TO PIR OUT D3 TO LED PIN
void setup() {
  pinMode(2, INPUT);//define arduino pin
  pinMode(3, OUTPUT);//define arduino pin
  Serial.begin(9600);//enable serial monitor
}
void loop() {
  bool value = digitalRead(2);//get value and save it boolean veriable
  if (value == 1) { //check condition
    digitalWrite(3,HIGH);//LED on
    Serial.println("MOTION DETECTED");//print serial monitor ON
  } else {
    //Serial.println("OFF");//print serial monitor OFF
    digitalWrite(3,LOW);//LED off
    Serial.println("MOTION NOT DETECTED");//print serial monitor ON
  }
  delay(1000);

}
