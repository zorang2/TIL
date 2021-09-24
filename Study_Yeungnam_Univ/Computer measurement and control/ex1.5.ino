/*
[예제1.5] 5개의 LED에 각각 저항 220Ω을 연결하고,
1초 간격으로 좌에서 우로 순차적으로 켜진 후,
1초 간격으로 역순으로 꺼지도록 회로를 구성하고 프로그램을 작성하라.
*/

#define NUM_LED 5                //  정의
#define TIME_DELAY 1000         // 정의

const byte pinLED[NUM_LED] = {13, 12, 11, 10, 9};  
	//LED를 13, 12, 11, 10, 9 라인을 통해서만 쓸 것입니다.

void setup() {
  int i;
  for (i=0; i<NUM_LED; i++)
		// i가 0에서 시작하는데 NUM_LED보다 작으면 I를 반복해서 1씩 더한다.
    pinMode(pinLED[i] , OUTPUT);
}

void loop() {
  int i;
  for (i=0;i<NUM_LED;i++) {
    digitalWrite(pinLED[i] , HIGH);   // 5V 쏴라
    delay(TIME_DELAY);		    // 1초를 딜레이하면서
  }
  for (i=NUM_LED-1; i>=0; i--) {
    digitalWrite(pinLED[i], LOW);    // 0V 쏴라
    delay(TIME_DELAY);		    // 1초를 딜레이하면서
  }
}

/*
위와같은 코드를 분석하였다.
*/
