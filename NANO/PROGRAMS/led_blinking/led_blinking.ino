//connect D2,D3,D4 & D5 WITH blue,green,red & yellow leds respectively

void setup() 
{
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() 
{
  digitalWrite(2, HIGH);  
  delay(100);                      
  digitalWrite(2, LOW);   
  delay(100);  

  digitalWrite(3, HIGH);  
  delay(100);                      
  digitalWrite(3, LOW);   
  delay(100); 

  digitalWrite(4, HIGH);  
  delay(100);                      
  digitalWrite(4, LOW);   
  delay(100); 

  digitalWrite(5, HIGH);  
  delay(100);                      
  digitalWrite(5, LOW);   
  delay(100); 
}
