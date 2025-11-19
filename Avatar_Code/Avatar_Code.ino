#include <Servo.h>

Servo benderServo1;
Servo rokuServo; //variable for roku's servo
Servo aangServo; //variable for aang's servo
const int mapLeds = 13;
const int fireSwitch = 8;
const int iceSwitch = 7;
const int rokuSwitch = 11;
const int fireLED = 5; //fire nation led
int i= 0;
int angle = 10;

void setup() {
  pinMode(mapLeds, OUTPUT);
  pinMode(fireLED, OUTPUT);

  pinMode(fireSwitch, INPUT); //switch for fire interaction
  pinMode(rokuSwitch, INPUT);
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
  if(angle == 170){
      benderServo1.write(0);   // spin CCW
     angle = 10;
  }

  else if (angle == 10){
      benderServo1.write(180);  // spin CW
     angle = 170;
  }

  if(digitalRead(fireSwitch)== HIGH){
    digitalWrite(fireLED, HIGH);
  }
  else{
    digitalWrite(fireLED, LOW);
  }
 
  if(digitalRead(rokuSwitch)== HIGH){
    rokuServo.write(90);
  }
  else{
    rokuServo.write(0);
  }

    aangServo.write(90);

}
