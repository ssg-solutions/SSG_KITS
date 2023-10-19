
byte  M1A = 2;
byte  M1B = 3;
byte  M2A = 4;
byte  M2B = 5;

void setup()   
{                
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
 
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


  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);
  delay(2000);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, HIGH);
  delay(2000);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);
  delay(2000);
 
}
  
 
