//connect pin 13 to led & pin 2 to switch
#define Y  8
#define R  9
#define G  10
#define B  11

#define buttonState1  4
#define buttonState2  5
#define buttonState3  6
#define buttonState4  7

void setup() {
  pinMode(buttonState1, INPUT_PULLUP);
  pinMode(buttonState2, INPUT_PULLUP);
  pinMode(buttonState3, INPUT_PULLUP);
  pinMode(buttonState4, INPUT_PULLUP);
  pinMode(Y, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

}

void loop() {
 if (digitalRead(buttonState1) == LOW)       
    digitalWrite(Y, HIGH); 
  else                          
    digitalWrite(Y, LOW);  

 if (digitalRead(buttonState2) == LOW)       
    digitalWrite(R, HIGH); 
  else                          
    digitalWrite(R, LOW);  

 if (digitalRead(buttonState3) == LOW)       
    digitalWrite(G, HIGH); 
  else                          
    digitalWrite(G, LOW);  

 if (digitalRead(buttonState4) == LOW)       
    digitalWrite(B, HIGH); 
  else                          
    digitalWrite(B, LOW);   
}
