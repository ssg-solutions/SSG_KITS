//connect D1,D2,D4 &D3 with LED PINS

int LED1 = 0; // Assign LED pin i.e: D3 on NodeMCU
int LED2 = 5; // Assign LED pin i.e: D1 on NodeMCU
int LED3 = 4; // Assign LED pin i.e: D2 on NodeMCU
int LED4 = 2; // Assign LED pin i.e: D4 on NodeMCU


void setup() {

// initialize GPIO 5 as an output

pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);


}

// the loop function runs over and over again forever

void loop() {
 digitalWrite(LED1, HIGH); // turn the LED on
 digitalWrite(LED2, HIGH); // turn the LED on
 digitalWrite(LED3, HIGH); // turn the LED on
 digitalWrite(LED4, HIGH); // turn the LED on
delay(1000); // wait for a second
digitalWrite(LED1, LOW); // turn the LED off
digitalWrite(LED2, LOW); // turn the LED off
digitalWrite(LED3, LOW); // turn the LED off
digitalWrite(LED4, LOW); // turn the LED off
delay(1000); // wait for a second
}
