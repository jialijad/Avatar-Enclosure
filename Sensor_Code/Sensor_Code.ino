//test changeee
const int sensorPin = A0;
const int ledPin = 13;
int sensorVal;


void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  sensorVal = analogRead(sensorPin);
  Serial.println(sensorVal);
  if(sensorVal >= 250){
    digitalWrite(ledPin, HIGH);
  } else{
    digitalWrite(ledPin, LOW);
  }

  delay(500);
  // put your main code here, to run repeatedly:
}
