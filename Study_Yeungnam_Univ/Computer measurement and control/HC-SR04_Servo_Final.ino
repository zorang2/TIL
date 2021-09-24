#include <Servo.h> 
#include <NewPing.h>
#define MAXDISTANCE 200
const byte pinServo = 9;
const byte pinTrig = 12;
const byte pinEcho = 13;

Servo myServo;
NewPing sonar(pinTrig, pinEcho, MAXDISTANCE);

void setup() {
  myServo.attach(pinServo);
  myServo.write(0);
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  long duration, dist;

  delay(50);
  duration = sonar.ping();
  dist = duration / US_ROUNDTRIP_CM;
  Serial.print("dist(cm) -> ");
  Serial.print(dist);

  int angle;

  if (dist < 10)
    angle = 90;
  else
    angle = 0;
    
  myServo.write(angle);

  Serial.print("\t");
  Serial.print("angle(deg) -> "); 
  Serial.println(angle);
  delay(100); 
}
