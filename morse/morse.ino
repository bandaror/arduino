//morse code translatot by andras csuri 2019
//try strings and find a suitable collection type0
#include <LiquidCrystal.h>
int button = 6;
int led = 5;
int buzzer = 4;
int counter = 0;
int cursorPos =0 ;
char morseArray[6];
char tempArray[6];
char dash[1] = {'-'};
char dot[1] = {'.'};
int cycle = 0;          //to mark a cycle of a letter (can be len 4 max)
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

//when the button is pressed the lcd will reset and write " length", lit the led and buzz the buzzer, then mark the actual state of the counter in miliseconds divided by ten (so thenth of seconds), also will increase the counter till the button is pressed
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
  //if the counter is less then 400 miliseconds (40 centiseconds) the array will add a dot at the actual position of the cycle
   if (counter < 40) //the short signal
    {
      morseArray[cycle] = dot[cycle-1];

    }
  //if the counter is more than 40 centisecond the array will add a dash to the actual cycle position
    if(counter >= 40 and counter < 150)  //the long signal
    {
      morseArray[cycle] = dash[cycle -1];

    }

//this is when we finish with a letter(the cycle) -holding the button longer than 150cs, then copy the array to the temparray
    if(counter >150)
    {
      for(int i =0; i<=sizeof(morseArray);i++)  // copy the array
    {
      (tempArray[i] = morseArray[i]);

    }
      Serial.println("The morse code is done, the current morse is: ");
      Serial.println(tempArray);

 /*    for(int i =0; i<=sizeof(morseArray);i++)  // copy the array
 //   {
      (morseArray[i] = 'x');

    }


      Serial.println(" ");
      Serial.println("deleting the morseArray: ");
      Serial.println(morseArray);


     // Serial.println( morseArray);
      cycle = -1;
*/

  LM variable = {'A', "......"};
    for(int i =0; i<=sizeof(morseArray);i++)
    {
      if (variable.m[i] == tempArray[i] or tempArray[i] == 'x')
      {
        Serial.println("egyezes");
      }
      else
      {
        Serial.println("nincs egyezes");
      }
    }

      }
   if(counter > 0)
   {


    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0,1);
    lcd.print(counter);
    lcd.setCursor(5,1);
    lcd.print(morseArray);
    Serial.println("The array and cycle: ");
    Serial.println(cycle+1);
    Serial.println(morseArray);

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
