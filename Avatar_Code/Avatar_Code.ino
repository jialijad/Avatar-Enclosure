#include <Servo.h>

Servo benderServo1;
int bendersAngle = 41;
int benderSpeed = 0.5;
Servo rokuServo; //variable for roku's servo
Servo aangServo; //variable for aang's servo
const int mapLeds = 13;
const int rokuSwitch = 8;
const int iceSwitch = 7;
const int fireLED = 5; //fire nation led
int i= 0;
int turn = 0;

void setup() {
  pinMode(mapLeds, OUTPUT);
  pinMode(fireLED, OUTPUT);

  pinMode(rokuSwitch, INPUT); //switch to make roku dissappear
  pinMode(iceSwitch, INPUT); //switch to make aang appear

  benderServo1.attach(9);
  benderServo1.write(0);

  Serial.begin(9600);

  rokuServo.attach(10); //pin for roku servo
  aangServo.attach(6); //pin for aang's servo
  rokuServo.write(0); //initial state for roku
  aangServo.write(0); //initial state for aang
  Serial.begin(9600);
}

void loop() {
  digitalWrite(mapLeds, HIGH);
  if(angle == 1){
      benderServo1.write(0);   // spin CCW
     angle = 0;
  }

  else if (angle == 0){
      benderServo1.write(180);  // spin CW
     angle = 1;
  }

  if(digitalRead(rokuSwitch)== HIGH){
    Serial.println("byeroku");
  }
  else{
    rokuServo.write(0);
    Serial.println("hiroku");
  }

  if(digitalRead(iceSwitch)== HIGH){
  }
  else{
    aangServo.write(0);
  }


}
