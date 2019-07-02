#include <LiquidCrystal.h>
int button = 6;
int led = 5;
int buzzer = 4;
int counter = 0;
int cursorPos =0 ;
char morseArray[6];
char dash[1] = {'-'};
char dot[1] = {'.'};
int cycle = 0;
struct LM{
 char l;
 char m[4];
};
//char letters[] =
//"A  .-,B  -...,C  -.-.,D  -..,E  .,F  ..-.,G  --.,H  ....,I  ..,J  .---,K  -.-,L  .-..,M  --,N  -.,O  ---,P  .--.,Q  --.-,R  .-.,S  ...,T  -,U  ..-,V  ...-,W  .--,X  -..-,Y  -.--,Z  --..";
static const struct {const char letter, *code;} morseMap[] ={
{'A', ".-"},
{'B', "-..."},
};
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup() {
 pinMode(led, OUTPUT);
 pinMode(button, INPUT_PULLUP);
 pinMode(buzzer, OUTPUT);
 lcd.begin(16, 2);
 lcd.print("Morse code beta");
 Serial.begin(9600);



}

//Stream.read("c:/Users/tuba/Documents/GitHub/arduino/morsetext.txt");

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
      morseArray[cycle] = dot[cycle-1];

    }
    if(counter >= 40)
    {
      morseArray[cycle] = dash[cycle -1];

    }
   if(counter > 0)
   {
    LM variable = {'A', ".-"};
    if(variable.m == morseArray)
    {
      Serial.println(variable.l);
    }
    else
    {
      Serial.println(morseArray);
      Serial.println(variable.m);
    }
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0,1);
    lcd.print(counter);
    lcd.setCursor(5,1);
    lcd.print(morseArray);
    Serial.println("The array and cycle: ");
    Serial.println(cycle+1);
    Serial.println(morseArray);
    //Serial.println(letters);

    if(cycle<4)
    {
      cycle = cycle+1;
    }
    else
    {
      cycle = 0;

    }
    lcd.setCursor(11,0);
    lcd.print(cycle);


    counter = 0;



   }
  }
