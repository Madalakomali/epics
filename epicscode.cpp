#include <Servo.h>
#include<LiquidCrystal.h>
Servo myservo1;  // create servo object to control a servo
//                 RS,E,D4,D5,D6,D7
LiquidCrystal lcd(12,11,2,3,4,5);
unsigned char j=0;
int x1,y1,z1,fswstate,wstate=0;
int bzs=0;
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

const int bzr=13;
const int senin=7;
const int senout=8;
unsigned char x=0;

int state = LOW;      // the current state of the output pin
int reading,reading1; // the current reading from the input pin
//int reading1;
int previous = HIGH;    // the previous reading from the input pin
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

void setup() {
 myservo1.attach(9);// a
pinMode(bzr,OUTPUT);
pinMode(senin,INPUT);
pinMode(senout,INPUT);
digitalWrite(senin,1);
digitalWrite(senout,1);
digitalWrite(bzr,0);

lcd.begin(16,2);
delay(100);
lcd.clear();
lcd.setCursor(0,0);  
lcd.print("RAIN CROP       ");   
lcd.setCursor(0,1);  
lcd.print("PROTECTION      ");
delay(2000);

}

void loop() {

   reading = digitalRead(senin);
   if (reading == LOW ) {
    
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("RAIN IS COMMING ");   
      lcd.setCursor(0,1);  
      lcd.print("................");
      delay(100);
      //digitalWrite(bzr,1);
      myservo1.write(100);                  // sets the servo position according to the scaled value
      delay(3000);
      while(digitalRead(senin) == 0){}
     // digitalWrite(bzr,0);
      
      }
   reading1 = digitalRead(senin);
   if (reading1 ==HIGH ) {
    
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("NO RAIN         ");   
      lcd.setCursor(0,1);  
      lcd.print("................");
      delay(100);
      myservo1.write(0);
      
     // digitalWrite(bzr,1);
      delay(3000);
     // digitalWrite(bzr,0);
     while(digitalRead(senin) == 1){}
      }

}