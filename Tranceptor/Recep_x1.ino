/*
pin nRF24l01→pin Arduino
   1.- GND→GND
   2.- VCC→ 3.3V
   3.- CE→pin 9
   4.- CSN→pin 10
   5.- SCK→pin 13
   6.- MOSI→pin 11
   7.- MISO→pin 12

*/


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN   9
#define CSN_PIN 10

const uint64_t pipe = 0xE8E8F0F0E1LL; 

RF24 radio(CE_PIN, CSN_PIN); 
char joystick;  
void setup()
{
  Serial.begin(9600);
  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}

void loop()
{
  while ( !radio.available() ){};
  radio.read( &joystick, sizeof(joystick) );
  if(joystick!=0){
  Serial.print(joystick);
  }
}

