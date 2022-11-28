/* [예제3.3]
조도 센서 값이 500 이하이면,
LED 가로등 점등’ 이라는 예제를 통해서
CdS 조도 센서에 대해 알아보고,
그에 관한 코드를 분석하고자 한다.
*/

/*
Cds(Cadmium Sulfide, 황화 카드뮴) :
빛의 세기가 증가하면 저항이 감소하는 광도전 소자의 주성분
Photocell 또는 Photoconductive cell, Photoresistor, LDR(Light-Dependent-Resistor)라 부름
*/


const byte pinLED = 13; // pinLED를 전역 정수형 변수로써 13으로 정의
const byte pinCdS = A0; // pinCdS를 전역 정수형 변수로써 A0(아날로그 입력 핀)으로 정의
value = analogRead(pinCdS); // 아날로그 A0핀으로부터 0~1023사이의 값을 읽음
if (value < 500) // 만약 value가 500보다 작다면
digitalWrite(pinLED, HIGH); // pinLED에 5V출력
else // 아니라면
digitalWrite(pinLED, LOW);  // pinLED에 0V출력
