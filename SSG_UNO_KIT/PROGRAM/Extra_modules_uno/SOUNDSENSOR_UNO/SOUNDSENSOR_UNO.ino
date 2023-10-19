//connect O/P of Sound sensor to 7 pin of UNO & Led pin to 12  pin of UNO also connect VCC & GND of sound sensor to 5v & GND
const int ledPin = 12;
const int soundPin = 7;

int soundVal = 0;

void setup ()
{
  pinMode (ledPin, OUTPUT);
  pinMode (soundPin, INPUT);
}
 
void loop ()
{
  soundVal = digitalRead(soundPin);
  if (soundVal == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
 }
