#include <Servo.h>

Servo bendersServo;
const int mapLeds = 13;
int i= 0;
int angle = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(mapLeds, OUTPUT);
  bendersServo.attach(9);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(mapLeds, HIGH);
if(angle == 0){
  bendersServo.write(angle);
  angle = 90;

}
if (angle == 90){
  bendersServo.write(angle);
  angle = 180;
}
}
