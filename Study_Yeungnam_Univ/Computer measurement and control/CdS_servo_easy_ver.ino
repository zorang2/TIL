#include <Servo.h>

Servo myServo;

int cdsPin = A0;
int servoPin = 9;

int value = 0;
int angle = 0;

void setup(){
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop(){
  value = analogRead(cdsPin);
  Serial.print("cds value: ");
  Serial.println(value);

  angle = map(value, 0, 1023, 0, 179);
  Serial.print("angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(100);
}
