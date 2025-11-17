#include <Servo.h>

Servo benderServo1;
Servo benderServo2;
Servo rokuServo; //variable for roku's servo
Servo aangServo; //variable for aang's servo
const int mapLeds = 13;
const int rokuSwitch = 10;
const int iceSwitch = 7;
const int fireLED = 5; //fire nation led
int i= 0;
int angle = 0;


void setup() {
  pinMode(mapLeds, OUTPUT);
  pinMode(fireLED, OUTPUT);

  pinMode(rokuSwitch, INPUT); //initializes the switch to make roku dissappear
  pinMode(iceSwitch, INPUT); //initializes the switch to make aang appear

  benderServo1.attach(9);
  benderServo2.attach(10);

  Serial.begin(9600);

  rokuServo.attach(8); //pin for roku servo
  aangServo.attach(6); //pin for aang's servo
  rokuServo.write(0); //initial state for roku
  aangServo.write(0); //initial state for aang
}

void loop() {
  digitalWrite(mapLeds, HIGH);
  if(angle == 0){
   //servoSlow(benderServo1, angle, 180, 20);
  // servoSlow(benderServo2, 180, angle, 20);
   angle = 180;
  }
  if (angle == 180){
   //servoSlow(benderServo1, 180, 0, 20);
  // servoSlow(benderServo2, 0, 180, 20);
   angle = 0;
  }

  if(digitalRead(rokuSwitch)== HIGH){
 // servoSlow(rokuServo, 0, 180, 20);
  }
  else{
  rokuServo.write(0);
  }


}
