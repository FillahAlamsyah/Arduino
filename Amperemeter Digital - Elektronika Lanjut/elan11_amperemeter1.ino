//Amperemeter
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

//definisi sensor arus
int sensor = A0;
float R = 10;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Amperemeter");
  delay(1000);
  pinMode(sensor,INPUT);
}
void loop(){
  //mengukur arus
  float adc1 = analogRead(sensor); // output adc 0-1023
  float Vadc1 = 5*adc1/1023; //Volt
  float I_ukur = Vadc1/R; //arus dlm ampere
  float I_mili = I_ukur * 1000; // mA
  
  //menampilkan arus dalam serial
  Serial.print("I ukur : ");
  Serial.print(I_mili);
  Serial.println(" mA");
  delay(1000);
  
  //menampilkan arus dalam LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("I ukur: ");
  lcd.print(I_mili);
  lcd.print(" mA");
  delay(1000);
}