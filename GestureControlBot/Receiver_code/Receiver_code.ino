#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[7] = "team14";

void setup() {
  //To start the serial plotter
  Serial.begin(9600);
  radio.begin();
  //set the address
  radio.openReadingPipe(0, address);
  //Set power amplifier level to minimum
  radio.setPALevel(RF24_PA_MAX);
  //Set module as receiver
  radio.startListening();
}

void loop() {
  //Read the data if available in buffer
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println("EMR workshop");
    Serial.println(text);
  }
}