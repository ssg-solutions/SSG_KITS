//connect D2,D3,D4 &D5 with B1,B2,B3 & B4 respectively

void setup() 
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() 
{

  digitalWrite(2, LOW);   
  digitalWrite(3, LOW);  
  digitalWrite(4, LOW);  
  digitalWrite(5, HIGH);  
  delay(2);

  digitalWrite(2, LOW);   
  digitalWrite(3, LOW);  
  digitalWrite(4, HIGH);  
  digitalWrite(5, HIGH);  
  delay(2);

  digitalWrite(2, LOW);   
  digitalWrite(3, LOW);  
  digitalWrite(4, HIGH);  
  digitalWrite(5, LOW);  
  delay(2);

  digitalWrite(2, LOW);   
  digitalWrite(3, HIGH);  
  digitalWrite(14, HIGH);  
  digitalWrite(5, LOW);  
  delay(2);

  digitalWrite(2, LOW);   
  digitalWrite(3, HIGH);  
  digitalWrite(4, LOW);  
  digitalWrite(5, LOW);  
  delay(2);

  digitalWrite(2, HIGH);   
  digitalWrite(3, HIGH);  
  digitalWrite(4, LOW);  
  digitalWrite(5, LOW);  
  delay(2);

  digitalWrite(2, HIGH);   
  digitalWrite(3, LOW);  
  digitalWrite(4, LOW);  
  digitalWrite(5, LOW);  
  delay(2);

  digitalWrite(2, HIGH);   
  digitalWrite(3, LOW);  
  digitalWrite(4, LOW);  
  digitalWrite(5, HIGH);  
  delay(2);
 
}
