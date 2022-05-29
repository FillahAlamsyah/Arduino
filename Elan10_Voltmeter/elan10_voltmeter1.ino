//voltmeter
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//sensor tegangan
int sensor = A0;
float R1 = 100000;
float R2 = 1000;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Voltmeter");
  delay(500);
  pinMode(sensor, INPUT);
}

void loop()
{
  //mengukur tegangan
  float adc = analogRead(sensor);
  float Vadc = 5*adc/1023;
  float V_ukur = Vadc*(R1+R2)/R2;
  
  // menampilkan tegangan dalam serial
  Serial.print("V ukur : ");
  Serial.print(V_ukur);
  Serial.println(" Volt");
  delay(1000);
  
  //menampilkan tegangan dalam LCD
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("V ukur:");
  lcd.print(V_ukur);
  lcd.print(" V");
  delay(1000);
}