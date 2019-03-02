int led = 6;
int bottone = 7;
int statobottone = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(bottone, INPUT);
}
void loop() {
  statobottone = digitalRead(bottone);
  if (statobottone == HIGH)
  {
   digitalWrite(led, HIGH);
   delay(5000);
   digitalWrite(led, LOW);
  }
  else
  {
   digitalWrite(led, LOW);
  }
    
}
  
