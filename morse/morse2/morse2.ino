//morse code translatot by andras csuri 2019
//we count the amount of time while the button is pressed on the arduino board.
//depending the length of time counted we either create a dot, or a dash or if it is a very long duration we shut down the sequence.
//When the sequence is done we compare the gathered dots and dashes with the morse codes and pass the index of the matched morse code to the
// the abc array. if we use index of the morse code on the index of the abc we should get the corresponding letter.
#include <LiquidCrystal.h>
int button = 6;
int led = 5;
int buzzer = 4;
int counter = 0;
int cursorPos =0 ;
String morseString = "";
String tempString = "";
String dash = "-";
String dot = ".";
//int cycle = 0;          //to mark the cycle of a letter (can be len 4 max)
String abc[] = {"a","b","c","d", "e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
String morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",.-..","--","-.", "---", ".--.", "--.-",".-.","...","-","...-",".--","-..-","-.--","--.."};
//,G  --.,H  ....,I  ..,J  .---,K  -.-,L  .-..,M  --,N  -.,O  ---,P  .--.,Q  --.-,R  .-.,S  ...,T  -,U  ..-,V  ...-,W  .--,X  -..-,Y  -.--,Z  --..";
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

    /* code */

  //if the counter is less then 400 miliseconds (40 centiseconds) the array will add a dot at the actual position of the cycle
   if (counter < 40 && counter >0) //the short signal
    {

      morseString.concat(dot);
      Serial.println(morseString);

    }
  //if the counter is more than 40 centisecond the array will add a dash to the actual cycle position
    if(counter >= 40 and counter < 150)  //the long signal
    {
      morseString.concat(dash);
      Serial.println(morseString);


    }

//this is when we finish with a letter(the cycle) -holding the button longer than 150cs, then copy the array to the temparray
    if(counter >150 )
    {
      tempString = morseString;
      Serial.println("The morse code is done, the current morse is: ");
      Serial.println(morseString);
      morseString = "";
      Serial.println("The tempstring is: ");
      Serial.println(tempString);
      for(int i = 0; i < sizeof(morse); i++)
      {
        if (morse[i].equals(tempString))
        {
        Serial.println(abc[i]);
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
    lcd.print(morseString);
   // Serial.println("The cycle: " );
   // Serial.println(cycle);





  /*  if(cycle<4)
    {
      cycle = cycle+1;

    }
    else
    {
      cycle = 0;

    }
*/
   }
    lcd.setCursor(11,0);
   // lcd.print(cycle);


    counter = 0;



   }
