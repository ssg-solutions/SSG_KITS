//Connect TX2 to RX of GSM & RX2 to TX of GSM

void setup() {
  Serial.begin(9600);  
  Serial.begin(9600);
  delay(3000);
  test_sim800_module();
  send_SMS();
}
void loop() {
  updateSerial();
}
void test_sim800_module()
{
  Serial.println("AT");
  updateSerial();
  Serial.println();
  Serial.println("AT+CSQ");
  updateSerial();
  Serial.println("AT+CCID");
  updateSerial();
  Serial.println("AT+CREG?");
  updateSerial();
  Serial.println("ATI");
  updateSerial();
  Serial.println("AT+CBC");
  updateSerial();
}
void updateSerial()
{
  delay(500);
  while (Serial.available())
  {
    Serial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while (Serial.available())
  {
    Serial.write(Serial.read());//Forward what Software Serial received to Serial Port
  }
}
void send_SMS()
{
  Serial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  Serial.println("AT+CMGS=\"08482937644\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  Serial.print("Ssg"); //text content
  updateSerial();
Serial.println();
  Serial.println("Message Sent");
  Serial.write(26);
}
