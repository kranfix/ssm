/* pin nRF24l01→pin Arduino
   1.- GND→GND
   2.- VCC→ 3.3V
   3.- CE→pin 9
   4.- CSN→pin 10
   5.- SCK→pin 13
   6.- MOSI→pin 11
   7.- MISO→pin 12
   
  Pines del keypad rotulados del 1 al 8 de izquierda a derecha:
pin Keypad→pin Arduino
   1.- pin 1→pin A0
   2.- pin 2→pin A1
   3.- pin 3→pin A2
   4.- pin 4→pin A3
   5.- pin 5→pin 5
   6.- pin 6→pin 4
   7.- pin 7→pin 3
   8.- pin 8→pin 2

pin LCD→pin Arduino
   1.- VSS→GND
   2.- VDD→5 V
   3.- RS→pin 8
   4.- RW→GND
   5.- E→pin 7
   6.- D4→pin 5
   7.- D5→pin 4
   8.- D6→pin 3
   9.- D7→pin 2
   10.- A→5 V
   11.- K→GND
   12.- V0→ pin central-potenciómetro


 */


#include <SPI.h>
#include <Keypad.h>
#include <nRF24L01.h>
#include <RF24.h>
#define CE_PIN   9
#define CSN_PIN 10
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 7, 5, 4, 3, 2);

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(CE_PIN, CSN_PIN);
int joystick;  
void setup() 
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  lcd.begin(16, 2);
}
int k=0;
void loop()
{
  char customKey = customKeypad.getKey();
    
  if (customKey){
    Serial.println(customKey);
      if(k<16){
        lcd.print(customKey);
        Serial.print(customKey);
      }
      else
      {
        lcd.setCursor(k-16,1);
        lcd.print(customKey);
      }
      k++;
  }
  radio.write( &customKey, sizeof(customKey) );
}

