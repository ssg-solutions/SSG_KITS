//connect pin 9 to buzzer sin pin
int buzzer_pin = 9;

void setup()
{ 
  pinMode(buzzer_pin,OUTPUT);
  
}
void loop()
{
  digitalWrite(buzzer_pin,HIGH);
  delay(2000);
  digitalWrite(buzzer_pin,LOW);
  delay(2000);
}
