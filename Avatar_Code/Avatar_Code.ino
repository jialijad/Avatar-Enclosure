#include <Servo.h>

Servo bendersServo;
const int mapLeds = 13;
int i= 0;
int angle = 0;


void setup() {
  pinMode(mapLeds, OUTPUT);
  bendersServo.attach(9);
  Serial.begin(9600);
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
    delay(delayt);
 }
servo.write(end);
}

void loop() {
  digitalWrite(mapLeds, HIGH);
if(angle == 0){
  servoSlow(bendersServo, angle, 180, 20);
  angle = 180;

}
if (angle == 180){
  servoSlow(bendersServo, 180, 0, 20);
  angle = 0;
}
}
