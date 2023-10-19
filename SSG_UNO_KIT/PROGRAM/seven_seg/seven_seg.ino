
const uint8_t BCD_A = 3;
const uint8_t BCD_B = 4;
const uint8_t BCD_C = 5;
const uint8_t BCD_D = 6;

const unsigned long DisplayPeriod = 1000;

void setup() {
   pinMode(BCD_A, OUTPUT);
   pinMode(BCD_B, OUTPUT);
   pinMode(BCD_C, OUTPUT);
   pinMode(BCD_D, OUTPUT);
}

void loop() {
   static uint8_t count = 0;  // display count
   static unsigned long previousDisplayTime = 0;
   unsigned long currentTime = millis();

   
   if (currentTime - previousDisplayTime >= DisplayPeriod) {  // check if time to update display
      displayWrite(count);  // update display
      count++;  // increase counter
      if (count == 10) count = 0;  // reset to 0 if count exceeds 9
      previousDisplayTime = currentTime;
   }
}

void displayWrite(uint8_t value) {
   digitalWrite(BCD_A, bitRead(value, 0));  // BCD LSB
   digitalWrite(BCD_B, bitRead(value, 1));
   digitalWrite(BCD_C, bitRead(value, 2));
   digitalWrite(BCD_D, bitRead(value, 3));  // BCD MSB
}
