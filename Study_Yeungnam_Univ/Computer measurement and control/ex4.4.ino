/* 예제4.4)
Rotatry Potentiometer에 의한
color LED 색 제어 이라는 예제를 통해서
PWM 아날로그 출력, color LED에 대해 알아보고,
그에 관한 코드를 분석하고자 한다.
*/

/*
입력 : A0핀, 0-1023, Rotary Potentiometer
출력 : 11번 핀, 0-255, Red LED
10번 핀, 0-255, Green LED
9번 핀, 0-255, Blue LED
*/

const byte pinAnalog = A0;
const byte pinR = 11; //PWM
const byte pinG = 10; //PWM
const byte pinB = 9; //PWM

void setup() {

}

void loop() {
	float outValue, r, g, b;
	int value = analogRead(pinAnalog);
	outValue = value/1023.*255.;
	if (outValue <= 128) {
		// RED-GREEN
		b = 0;
		r = 255 - 255*outValue/128;
		if (r<0) r = 0;
		if (r>255) r = 255;
		g = 255-r;
}
	else if(outValue>128) {
		// GREEN-BLUE
		r = 0;
		g = 255 - 255*(outValue-128)/128;
		if (g<0) g = 0;
		if (g>255) g = 255;
		b = 255 - g;
	}
	analogWrite(pinR, r);
	analogWrite(pinG, g);
	analogWrite(pinB, b);
	delay(100);
}
