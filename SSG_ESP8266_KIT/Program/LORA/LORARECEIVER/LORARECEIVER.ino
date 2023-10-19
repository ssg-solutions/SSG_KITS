////Connect D8,D7,D6,D5,D0 & D1 to LORA SX1278---NSS,MOSI,MISO,SCK,RST & DIO0 respectively
//======================================================================//

#include <SPI.h>
#include <LoRa.h>

//======================================================================//

#define PIN_LORA_COPI   13
#define PIN_LORA_CIPO   12
#define PIN_LORA_SCK    14
#define PIN_LORA_CS     15
#define PIN_LORA_RST    16
#define PIN_LORA_DIO0   5

#define LORA_FREQUENCY  433E6

//======================================================================//

void setup() {
  Serial.begin (115200);
  while (!Serial);
  delay (1500);
  Serial.println ("LoRa Receiver");

  LoRa.setPins (PIN_LORA_CS, PIN_LORA_RST, PIN_LORA_DIO0);
  LoRa.setSPIFrequency (20000000);

  if (!LoRa.begin (LORA_FREQUENCY)) {
    Serial.println ("Starting LoRa failed!");
    while (1);
  }
  else {
    Serial.print ("LoRa initialized with frequency ");
    Serial.println (LORA_FREQUENCY);
  }
}

//======================================================================//

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  
  if (packetSize) {
    // received a packet
    Serial.print ("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print ((char) LoRa.read());
    }

    // print RSSI of packet
    Serial.print ("' with RSSI ");
    Serial.println (LoRa.packetRssi());
  }
}

//======================================================================//
