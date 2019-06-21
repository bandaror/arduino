int button = 6;
int led = 5;
int buzzer = 4;



void setup() {
 pinMode(led, OUTPUT);
 pinMode(button, INPUT_PULLUP);
 pinMode(buzzer, OUTPUT);
}



void loop() {
  if(digitalRead(button)== LOW)
  {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);

  }
}
