//connect D2,D3,D4 & D5 with M1A,M1B,M2A & M2B
byte  M1A = 2;
byte  M1B = 3;


void setup()   
{                
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
}

void loop()
{ 
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  delay(2000);
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, HIGH);
  delay(2000);
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  delay(2000);

}
  
 
