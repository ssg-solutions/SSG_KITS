


#define LED RED_LED
#define LED GREEN_LED

//see pins_energia.h for more LED definitions
//#define LED GREEN_LED
  
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(RED_LED, OUTPUT);  
  pinMode(GREEN_LED, OUTPUT);    
}

// the loop routine runs over and over again forever:
void loop() {
   
  digitalWrite(RED_LED, HIGH);
  delay(1000);              
  digitalWrite(RED_LED, LOW);    
  delay(1000); 

   digitalWrite(GREEN_LED, HIGH);
  delay(1000);              
  digitalWrite(GREEN_LED, LOW);    
  delay(1000); 
           
}
