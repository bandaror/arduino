#include <LiquidCrystal.h>
int button = 6;
int led = 5;
int buzzer = 4;
int counter = 0;
int cursorPos =0 ;
int morse = [3];
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup() {
 pinMode(led, OUTPUT);
 pinMode(button, INPUT_PULLUP);
 pinMode(buzzer, OUTPUT);
 lcd.begin(16, 2);
 lcd.print("Morse code beta");
}



void loop() {
    
    
  if(digitalRead(button)== LOW)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("length:");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(7,0);
    lcd.print(counter/10);
    counter ++;
     if (counter < 50)
    {
      lcd.setCursor(cursorPos,1);
      lcd.print(".");

    }
    if(counter > 50)
    {
      lcd.setCursor(cursorPos+1,1);
      lcd.print("_");
    }
    
  }
  else
  {
    
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    
    counter = 0;
   
  }
}
