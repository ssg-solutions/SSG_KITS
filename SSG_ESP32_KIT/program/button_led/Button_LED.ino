
#define BUTTON1 17 
#define BUTTON2 16
#define BUTTON3 4
#define BUTTON4 15

#define Y    5  
#define R    18
#define G    19
#define B    21

int button_state1 = 0;   
int button_state2 = 0;
int button_state3 = 0;
int button_state4 = 0;

void setup() {
  
  pinMode(Y, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
}

void loop() {
  
  button_state1 = digitalRead(BUTTON1);
  button_state2 = digitalRead(BUTTON2);
  button_state3 = digitalRead(BUTTON3);
  button_state4 =digitalRead(BUTTON4);
  
  if (button_state1 == LOW)       
    digitalWrite(Y, HIGH); 
  else                          
    digitalWrite(Y, LOW);  

  if (button_state2 == LOW)       
    digitalWrite(R, HIGH); 
  else                          
    digitalWrite(R, LOW);  

  if (button_state3 == LOW)       
    digitalWrite(G, HIGH); 
  else                          
    digitalWrite(G, LOW);  

  if (button_state4 == LOW)       
    digitalWrite(B, HIGH); 
  else                          
    digitalWrite(B, LOW);  
    
}
