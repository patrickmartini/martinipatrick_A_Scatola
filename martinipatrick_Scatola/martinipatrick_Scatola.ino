#include <LiquidCrystal.h>


int led = 7;
int ledRgb = 8;
int btn = 9;
int btn_ = 10;
int btn1 = 11;
int bzr = 6;
int value = 0;
LiquidCrystal lcd();

void setup() {
  randomSeed(millis);
  pinMode(led,OUTPUT);
  pinMode(ledRgb,OUTPUT);
  pinMode(btn,INPUT);
  pinMode(bzr,OUTPUT);

}

void loop() {
  controllaBottone(int btn, int value);

}

void controllaBottone(int bottone, int value){
  if (value == HIGH){
    iniziaTest();
  }
}

void iniziaTest(int tempo){
  tempo = random(1,5000);
  delay(tempo);
  digitalWrite(led,HIGH);
  int ris = contatempo(btn_,0);
  digitalWrite(led,LOW);
  lcd.print(ris + "ms");
  delay(3000);
  lcd.clear();
  tempo = random(3000,5000);
  delay(tempo);
  digitalWrite(bzr,HIGH);
  int ris_
}


int contatempo(int value, int cont){
  while(value == LOW)
  {
    cont++;
    delay(1);
  }
  return value;
}
