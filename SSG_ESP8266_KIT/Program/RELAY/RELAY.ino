//connect D3 with SIG Pin

int RELAY1 = 0; // Assign LED pin i.e: D3 on NodeMCU
void setup() 
{

// initialize GPIO 5 as an output
 pinMode(RELAY1, OUTPUT);
}
// the loop function runs over and over again forever
void loop()
{
 digitalWrite(RELAY1, HIGH); // turn the LED on
 delay(1000); // wait for a second
digitalWrite(RELAY1, LOW); // turn the LED off
delay(1000); // wait for a second
}
