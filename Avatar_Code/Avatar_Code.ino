#include <Servo.h>

Servo bendersServo;
Servo rokuServo;
const int mapLeds = 13;
const int rokuSwitch = 10;
int i= 0;
int angle = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(mapLeds, OUTPUT);
  bendersServo.attach(9);
  Serial.begin(9600);
  rokuServo.attach(8);
  pinMode(rokuSwitch, INPUT);

}

void servoSlow(Servo &servo, int start, int end, int delayt){
int step;

  if (end > start) {
    step = 1;
  } else {
    step = -1;
  }
  for (int a = start; a != end; a += step) {
    servo.write(a);
    delay(delayt);    // increase this to make it slower
   }
  servo.write(end);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(mapLeds, HIGH);
  if(angle == 0){
   servoSlow(bendersServo, angle, 180, 20);
   angle = 180;
  }
  if (angle == 180){
   servoSlow(bendersServo, 180, 0, 20);
   angle = 0;
  }

  if (digitalRead(rokuSwitch) == HIGH){
    servoSlow(rokuServo, 0, 180, 20);
  }
  else{
  servoSlow(rokuServo, 180, 0, 20);
  }
}
