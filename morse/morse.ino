#include <LiquidCrystal.h>
int button = 6;
int led = 5;
int buzzer = 4;
int counter = 0;
int cursorPos =0 ;
char morseArray[10];
char dash[1] = {'_'};
char dot[1] = {'.'};
int cycle = 0; 

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup() {
 pinMode(led, OUTPUT);
 pinMode(button, INPUT_PULLUP);
 pinMode(buzzer, OUTPUT);
 lcd.begin(16, 2);
 lcd.print("Morse code beta");
}



void loop() {


  while(digitalRead(button)== LOW)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("length:");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(7,0);
    lcd.print(counter/10);
    counter ++;
    

  }
   if (counter < 40)
    { 
      morseArray[cycle] = dot[0];
   
    }
    if(counter >= 40)
    { 
      morseArray[cycle] = dash[0];
     
    }
   if(counter > 0)
   {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0,1);
    lcd.print(counter);
    lcd.setCursor(5,1);
    lcd.print(morseArray);
    cycle ++;
    lcd.setCursor(11,0);
    lcd.print(cycle);
    counter = 0;
    
    
   }
  }
