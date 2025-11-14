#include <Servo.h>

Servo benderServo1;
Servo benderServo2;
Servo rokuServo; //variable for roku's servo
Servo aangServo; //variable for aang's servo
const int mapLeds = 13;
const int rokuSwitch = 10;
const int fireLED = 5; //fire nation led
int i= 0;
int angle = 0;


void setup() {
  pinMode(mapLeds, OUTPUT);
  pinMode(fireLED, OUTPUT);
  benderServo1.attach(9);
  benderServo2.attach(10);
  Serial.begin(9600);
  rokuServo.attach(8); //pin for roku servo
  aangServo.attach(6); //pin for aang's servo
  pinMode(rokuSwitch, INPUT);
  rokuServo.write(0); //initial state for roku
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
    delay(delayt);    //delayt value controls speed
   }
  servo.write(end);
}

void loop() {
  digitalWrite(mapLeds, HIGH);
  if(angle == 0){
   servoSlow(benderServo1, angle, 180, 20);
   servoSlow(benderServo2, 180, angle, 20);
   angle = 180;
  }
  if (angle == 180){
   servoSlow(benderServo1, 180, 0, 20);
   servoSlow(benderServo2, 0, 180, 20);
   angle = 0;
  }

  else{
  rokuServo.write(0);
  }


}
