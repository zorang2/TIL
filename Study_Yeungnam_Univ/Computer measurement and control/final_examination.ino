/*문제1)
초음파센서와 서보 모터를 이용하여,
거리가 10cm 이상이면 서보 모터를 0도로 유지하고,
거리가 10cm 미만으로 접근하면 서보 모터를 90로 회전시켜 Arm을 세워라.
함수 loop() 끝에서 delay는 100ms 이다. 

초음파센서에서 거리가 0으로 읽히면, MAXDISTANCE로 대체한다. 

Serial Monitor에는 다음과 같이 거리와 각도를 출력한다. 


각도 0과 90이 다음과 같이 위치하도록 Arm을 조립하라. 

*/
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


