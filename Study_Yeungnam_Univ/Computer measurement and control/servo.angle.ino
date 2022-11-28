#include<Servo.h>

Servo myServo;
const byte pinServo = 9;
int Angle =90;

void serialEvent(){
    while(Serial.available()){
      Angle = Serial.parseInt();
  }
}

void setup() {
  myServo.attach(pinServo);
  Serial.begin(9600);
}

void loop(){
  Serial.println(Angle);
  myServo.write(Angle);
  delay(100);
  
}
