#include <LiquidCrystal.h>

int led = 4;
int ledRgbV = 7;
int ledRgbR = 1;
int btnInizio = 2;
int btnLed = 3;
int btnBuzzer = 5;
int buzzer = 6;
int value = 0;

LiquidCrystal lcd(12,13,8,9,10,11);

void setup() {
  digitalWrite(buzzer,HIGH);
  randomSeed(millis);
  pinMode(led,OUTPUT);
  pinMode(ledRgbV,OUTPUT);
  pinMode(ledRgbR,OUTPUT);
  pinMode(btnInizio,INPUT);
  pinMode(btnLed,INPUT);
  pinMode(btnBuzzer,INPUT);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16,2);

}

void loop() {
  controllaBottone(digitalRead(btnInizio));
}

int controllaBottone(int value){
  if (value == HIGH){
    eseguiTest(1000);
  }
}
void eseguiTest(int tempo){
  reset();
  lcd.print("Inizio Test");
  lcd.setCursor(0,1);
  lcd.print("Riflessi"); 
  delay(1000);
  lcd.clear();
  delay(random(1,5000));
  digitalWrite(led,HIGH);
  int tempo1 = contatempo(btnLed,0);
  digitalWrite(led,LOW);
  lcd.setCursor(0,0);
  lcd.print("Tempo Led");
  lcd.setCursor(0,1);
  lcd.print(" = " + (String)tempo1 + " ms");
  delay(1000);
  lcd.clear();
  delay(random(1,5000));
  digitalWrite(buzzer,LOW);
  int tempo2 = contatempo(btnBuzzer,0);
  digitalWrite(buzzer,HIGH);
  lcd.setCursor(0,0);
  lcd.print("Tempo Buzzer");
  lcd.setCursor(0,1);
  lcd.print(" = " +(String)tempo2 + " ms");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tempo1 = " + (String)tempo1 + " ms");
  lcd.setCursor(0,1);
  lcd.print("Tempo2 = " + (String)tempo2 + " ms");
  if (tempo1 == 0 && tempo2 == 0){
    analogWrite(ledRgbR,255);
    lcd.print("ERRORE");
  }
  else if
  (tempo1 < 250 && tempo2 < 250){
    analogWrite(ledRgbV,255);
  }else{
    analogWrite(ledRgbR,255);
  }
}
}

int contatempo(int button, int contatore){
  while(digitalRead(button) == LOW)
  {
    contatore++;
    delay(1);
  }
  return contatore;
}

void reset(){
  analogWrite(ledRgbV,0);
  analogWrite(ledRgbR,0);
  lcd.clear();
}
