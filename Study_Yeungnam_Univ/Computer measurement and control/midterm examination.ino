/*
준비물)	
아두이노 Uno 보드	1개
브레드보드 830		1개
CdS 조두센서		1개
RED LED 		1개		
GREEN LED		1개
YELLOW LED		1개
저항 220Ω		3개
저항 10KΩ		1개
점퍼 케이블		9개

문제) 
CdS 조도 센서를 설치하고, 실내 조도에 따라 다음과 같이 LED를 제어하라. 
손으로 조도 센서를 가리면, 	RED LED = ON
손을 떼면,			GREEN LED = ON
플래시를 비추면,			YELLOW LED = ON
*/

const byte pinCdS = A0;
const byte pinLEDR = 11;
const byte pinLEDG = 12;
const byte pinLEDY = 13;

void setup() {
  pinMode(pinLEDR, OUTPUT);
  pinMode(pinLEDG, OUTPUT);
  pinMode(pinLEDY, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int value;
  value = analogRead(pinCdS);
  Serial.println(value);
  
  if (value < 500) {
    digitalWrite(pinLEDR, HIGH);
    digitalWrite(pinLEDG, LOW);
    digitalWrite(pinLEDY, LOW);
  } 
  else if (value < 900) {
    digitalWrite(pinLEDR, LOW);
    digitalWrite(pinLEDG, HIGH);
    digitalWrite(pinLEDY, LOW);
  }
  else {
    digitalWrite(pinLEDR, LOW);
    digitalWrite(pinLEDG, LOW);
    digitalWrite(pinLEDY, HIGH);
  }

}
