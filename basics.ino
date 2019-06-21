int button = 8;
int led = 7;
void setup() {
 pinMode(led, OUTPUT);
 pinMode(button, INPUT_PULLUP);

}

void loop() {
  if(digitalRead(button)== LOW)
  {
    digitalWrite(led, HIGH);
    
  }
  else
  {
    digitalWrite(led, LOW);
    
  }
}
