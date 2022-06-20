#include <Arduino.h>
#include <TM1637Display.h>
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

const uint8_t ON[] = {0x3f, 0x54, 0x00, 0x00};
const uint8_t OFF[] = {0x3f, 0x71, 0x71, 0x00};
const uint8_t OFF1[] = {0x00, 0x00, 0x00, 0x00};

int lampu = 9 ;
void setup() {
  Serial.begin (9600);
  Serial.println("\n Start");
  pinMode (lampu,OUTPUT);
  display.setBrightness(1);
  display.showNumberDec(0, true);
  delay(500);
  display.setSegments(OFF1);

}

void loop() {
 if (Serial.available()>0)
 {
  int baca = Serial.read ();

  if(baca == 'a')
  {
    digitalWrite(lampu, HIGH);
    Serial.println("Lampu Menyala");
    display.setSegments(ON);

  }
  if(baca == 'b')
  {
    digitalWrite(lampu, LOW);
    Serial.println("Lampu Padam");
    display.setSegments(OFF );

  }
 }

}