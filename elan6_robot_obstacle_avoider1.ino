//definisi pin
const int pintrig = A0;
const int pinecho = A1;
int motorkiri1 = 13;
int motorkiri2 = 12;
int motorkanan1 = 9;
int motorkanan2 = 8;
int pwm12 = 11;
int pwm34 = 10;

void setup(){
  pinMode(motorkiri1, OUTPUT);
  pinMode(motorkiri2, OUTPUT);
  pinMode(motorkanan1, OUTPUT);
  pinMode(motorkanan2, OUTPUT);
  pinMode(pwm12, OUTPUT);
  pinMode(pwm34, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  long duration, cm;
  //mengeluarkan sinyal ultrasonik
  pinMode(pintrig, OUTPUT);
  digitalWrite(pintrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pintrig, LOW);
  //menerima sinyal ultrasonik
  pinMode(pinecho, INPUT);
  //selang waktu mengirim dan menerima sinyal
  duration = pulseIn(pinecho, HIGH);
  
  //konversi dari duration menjadi cm
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.println(" cm : ");
  
  //pengaturan kecepatan motor
  analogWrite(pwm12,255); 
  analogWrite(pwm34,255);
  
  //JIKA ADA PENGHALANG KURANG DARI 25 cm
  if(cm<=25){
      digitalWrite(motorkiri1,LOW); 
      digitalWrite(motorkiri2,HIGH);
      digitalWrite(motorkanan1,HIGH);
      digitalWrite(motorkanan2,LOW);
      Serial.println("ADA PENGHALANG MAKA BELOK KANAN");
    }
  //JIKA TIDAK ADA PENGHALANG
  else
    {
      digitalWrite(motorkiri1,LOW); 
      digitalWrite(motorkiri2,HIGH);
      digitalWrite(motorkanan1,LOW);
      digitalWrite(motorkanan2,HIGH);
      Serial.println("TIDAK ADA PENGHALANG MAKA MAJU");
    }
}
long microsecondsToCentimeters(long microseconds){
  return microseconds/29/2;
}