//Connect D0 with LEDPIN1 &TX with PUSHBUTTONPIN1
//Connect D1 with LEDPIN2 &RX with PUSHBUTTONPIN2
//Connect D6 with LEDPIN3 &D5 with PUSHBUTTONPIN3
//Connect D3 with LEDPIN4 &D7 with PUSHBUTTONPIN4
const int LEDPIN1 = 16;
const int LEDPIN2 = 5;
const int LEDPIN3 = 12;
const int LEDPIN4 = 0;


const int PushButton1 =1;
const int PushButton2 =3;
const int PushButton3 =14;
const int PushButton4 =13;


// This Setup function is used to initialize everything 
void setup()
{
// This statement will declare pin 22 as digital output 
pinMode(LEDPIN1, OUTPUT);
pinMode(LEDPIN2, OUTPUT);
pinMode(LEDPIN3, OUTPUT);
pinMode(LEDPIN4, OUTPUT);

// This statement will declare pin 15 as digital input 
pinMode(PushButton1, INPUT_PULLUP);
pinMode(PushButton2, INPUT_PULLUP);
pinMode(PushButton3, INPUT_PULLUP);
pinMode(PushButton4, INPUT_PULLUP);

}

void loop()

{
// digitalRead function stores the Push button state 
// in variable push_button_state
int Push_button_state1 = digitalRead(PushButton1);
int Push_button_state2 = digitalRead(PushButton2);
int Push_button_state3 = digitalRead(PushButton3);
int Push_button_state4 = digitalRead(PushButton4);

if ( Push_button_state1 == LOW )
{ 
digitalWrite(LEDPIN1, HIGH); 


} 
else
{
  digitalWrite(LEDPIN1, LOW);
}

 if ( Push_button_state2 == LOW )
{ 
digitalWrite(LEDPIN2, HIGH); 


} 
else
{
  digitalWrite(LEDPIN2, LOW);
}

 if ( Push_button_state3 == LOW )
{ 
digitalWrite(LEDPIN3, HIGH); 


} 
else
{
  digitalWrite(LEDPIN3, LOW);
}

 if ( Push_button_state4 == LOW )
{ 
digitalWrite(LEDPIN4, HIGH); 


} 
else
{
  digitalWrite(LEDPIN4, LOW);
}
 
}
