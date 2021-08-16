#include <Servo.h>
#include <LiquidCrystal.h>
Servo servoMain; // Define our Servo
const int rs = 13, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2; /// as per the above connections
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int trigpin = 7;
int echopin = 6;
float distance;
float duration;
float cm;
void setup()
{
servoMain.attach(9); // servo on digital pin 10
pinMode(trigpin, OUTPUT);
pinMode(echopin, INPUT);
Serial.begin(9600);
lcd.begin(16, 2);
lcd.setCursor(0,0);
lcd.print("OBJECT AT");
}
void loop(){
//float cm;
// lcd.setCursor(0, 1);
//lcd.display();
//lcd.print(distance);
//lcd.display();
//delay(500);
//lcd.noDisplay();
//delay(500);
digitalWrite(trigpin, LOW);
delay(5);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
duration = pulseIn(echopin, HIGH);
//cm = (duration/58.82);
distance = (duration/58.82);
lcd.setCursor(0, 1);
lcd.display();
lcd.print(distance);
lcd.setCursor(8,1);
lcd.print("cm");
lcd.display();
delay(500);
lcd.noDisplay();
delay(500);
if(distance<30)
{
servoMain.write(180); // Turn Servo back to center position (90 degrees)
delay(3000);
}
else{
servoMain.write(0);
delay(50);
}
}