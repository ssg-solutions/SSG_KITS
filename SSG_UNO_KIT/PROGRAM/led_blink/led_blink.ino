//connect 9,10,11 & 12 to led pins yellow,red,green & blue
#define LED_PIN_4 12
#define LED_PIN_3 11
#define LED_PIN_2 10
#define LED_PIN_1 9

void setup()
{
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
   pinMode(LED_PIN_4, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN_1, LOW);
  digitalWrite(LED_PIN_2, LOW);
  digitalWrite(LED_PIN_3, LOW);
  digitalWrite(LED_PIN_4, LOW);
  delay(1000);
  digitalWrite(LED_PIN_1, HIGH);
  digitalWrite(LED_PIN_2, HIGH);
  digitalWrite(LED_PIN_3, HIGH);
  digitalWrite(LED_PIN_4, HIGH);
  delay(1000);
  
}
