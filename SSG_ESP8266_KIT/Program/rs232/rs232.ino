/*
 * There are three serial ports on the ESP known as U0UXD, U1UXD and U2UXD.
 * 
 * U0UXD is used to communicate with the ESP32 for programming and during reset/boot.
 * U1UXD is unused and can be used for your projects. Some boards use this port for SPI Flash access though
 * U2UXD is unused and can be used for your projects.
 * 
*/
//connect SRX to TX2 & STX to RX2 AND using RS232 cable send data from XTU terminal to Serial Monier.
//select proper port & baudrate ie9600 for XCTU
//baudrate 115200 to serial moniter
#define RX 3
#define TX 1

void setup() {
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(115200);
  //Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial.begin(9600, SERIAL, RX, TX);
  Serial.println("Serial Txd is on pin: "+String(TX));
  Serial.println("Serial Rxd is on pin: "+String(RX));
}

void loop() { //Choose Serial1 or Serial2 as required
  while (Serial.available()) {
    Serial.print(char(Serial.read()));
  }
}
