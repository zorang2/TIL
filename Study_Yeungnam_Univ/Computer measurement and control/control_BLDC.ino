#include <Servo.h>
Servo myESC;
const byte pinESC = 9;
int pulseWidth = 1000; // in microseconds

void setup() {
  myESC.attach(pinESC, 1000, 2000);
  Serial.setTimeout(50);
  myESC.writeMicroseconds(pulseWidth);
  Serial.begin(9600);
}

void loop() {
  myESC.writeMicroseconds(pulseWidth);
  Serial.println(pulseWidth);
  delay(100);
}

void serialEvent() {
  while (Serial.available()) {
    pulseWidth = Serial.parseInt();
  }
}
