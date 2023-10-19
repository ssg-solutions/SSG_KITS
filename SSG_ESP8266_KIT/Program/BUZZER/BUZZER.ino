//connect D1, with BUZZER PINS


int BUZZER = 5; // Assign LED pin i.e: D1 on NodeMCU


void setup() {

// initialize GPIO 5 as an output


pinMode(BUZZER, OUTPUT);



}

// the loop function runs over and over again forever

void loop() {

 digitalWrite(BUZZER, HIGH); // turn the LED on

delay(1000); // wait for a second

digitalWrite(BUZZER, LOW); // turn the LED off

delay(1000); // wait for a second
}
