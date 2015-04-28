Receptor y transmisor
=====================

## Receptor

### Conexiones de pines

#### pin nRF24l01->pin Arduino

*   GND  ->  GND
*   VCC  ->  3.3V
*   CE   ->  pin 9
*   CSN  ->  pin 10
*   SCK  ->  pin 13
*   MOSI ->  pin 11
*   MISO ->  pin 12


## Transmisor

### Conexiones de pines

#### pin nRF24l01->pin Arduino

De manera similar al anterior

#### pin nRF24l01->pin Arduino

*   GND  ->  GND
*   VCC  ->  3.3V
*   CE   ->  pin 9
*   CSN  ->  pin 10
*   SCK  ->  pin 13
*   MOSI ->  pin 11
*   MISO ->  pin 12

#### pin Keypad -> pin Arduino
Pines del keypad rotulados del 1 al 8 de izquierda a derecha:

*    pin 1 -> pin A0
*    pin 2 -> pin A1
*    pin 3 -> pin A2
*    pin 4 -> pin A3
*    pin 5 -> pin 5
*    pin 6 -> pin 4
*    pin 7 -> pin 3
*    pin 8 -> pin 2

#### pin LCD -> pin Arduino

*    VSS -> GND
*    VDD ->  5 V
*    RS  ->  pin 8
*    RW  ->  GND
*    E   ->  pin 7
*    D4  ->  pin 5
*    D5  ->  pin 4
*    D6  ->  pin 3
*    D7  ->  pin 2
*    A   ->  5 V
*    K   ->  GND
*    V0  ->  pin central-potenciómetro

### Bibliotecas utilizadas

* RF24: (Necesario para el nRF24l01) https://github.com/maniacbug/RF24
* Keypoad: http://playground.arduino.cc/uploads/Code/keypad.zip
