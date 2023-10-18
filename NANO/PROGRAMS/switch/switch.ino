//CONNECT D5 TO SWITCH & D3 TO LED PIN
const int LEDPIN1 = 2;
const int LEDPIN2 = 3;
const int LEDPIN3 = 4;
const int LEDPIN4 = 5;
const int PushButton1 =17;
const int PushButton2 =16;
const int PushButton3 =15;
const int PushButton4 =14;

// This Setup function is used to initialize everything 
void setup()
{
// This statement will declare pin 5 as digital output 
pinMode(LEDPIN1, OUTPUT);
pinMode(LEDPIN2, OUTPUT);
pinMode(LEDPIN3, OUTPUT);
pinMode(LEDPIN4, OUTPUT);

// This statement will declare pin 2 as digital input 
pinMode(PushButton1, INPUT_PULLUP);
pinMode(PushButton2, INPUT_PULLUP);
pinMode(PushButton3, INPUT_PULLUP);
pinMode(PushButton4, INPUT_PULLUP);
}

void loop()
{
int Push_button_state1 = digitalRead(PushButton1);
int Push_button_state2 = digitalRead(PushButton2);
int Push_button_state3 = digitalRead(PushButton3);
int Push_button_state4 = digitalRead(PushButton4);
if ( Push_button_state1 == HIGH )
{ 
digitalWrite(LEDPIN1, HIGH); 
} 
else
{
  digitalWrite(LEDPIN1, LOW);
}
if ( Push_button_state2 == HIGH )
{ 
digitalWrite(LEDPIN2, HIGH); 
} 
else
{
  digitalWrite(LEDPIN2, LOW);
}
if ( Push_button_state3 == HIGH )
{ 
digitalWrite(LEDPIN3, HIGH); 
} 
else
{
  digitalWrite(LEDPIN3, LOW);
}
if ( Push_button_state4 == HIGH )
{ 
digitalWrite(LEDPIN4, HIGH); 
} 
else
{
  digitalWrite(LEDPIN4, LOW);
}
}
