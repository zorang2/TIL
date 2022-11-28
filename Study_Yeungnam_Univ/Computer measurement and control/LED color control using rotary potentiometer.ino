
const byte pinAnalog = A0;
const byte pinR = 11;
const byte pinG = 10;
const byte pinB = 9;

void setup()｛

｝

void loop() {
  float outValue, r, g, b; //출력값 r,g,b를 실수형으로 정의한다.
  int value = analogRead(pinAnalog); //아날로그로 읽어온 값을 정수형 value에 넣는다.
  outValue = value/1023.*255; //아날로그 출력값의 범위를 맞춰주기 위해서 읽어드린 value 의 값을 출력값의 범위의 맞도록 계산하기 위해 위와 같이 1023을 나누고 255를 곱함.
　if (outValue <= 1280 { //아날로그 출력값이 1280이하일 때 
  //RED-GREEN
    b = 0;  //b=0으로 고정한다.
    r = 255 – 255*outValue/128; //red 값은 255에서 아날로그 출력값을 대입해 조정한다.
    if(r<0) r = 0; //r이 0보다 작으면 r=0으로 맞춰준다.
    if(r>255) r = 255;  //r은 255보다 크면 r = 255로 맞춰준다.
    g = 255-r; //r 값이 커지면 g의 값이 작아지고, r 값이 작으면 g의 값이 커진다.
  else if(outValue > 128) { //아날로그 출력값이 128보다 클 때 
   // GREEN – BLUE
    r = 0; //r은 으로 고정한다.
    g = 255 – 255*(outValue-128)/128; //green 의 값을 255에서 아날로그 출력값을 대입해 조정한다.
    if（ｇ＜0）ｇ＝０； //g가 0보다 작으면 0에 맞춘다.
　　if ( g >255) g = 255; //g가 255보다 크면 255에 맞춘다.
    b = 255 – g; //g의 값이 커지면 b가 작아지고, g 의 값이 작아지면 b가 커진다. 
  }
  analogWrite(pinR, r); //아날로그 출력 r,g,b
  analogWrite(pinG, g);
  analogWrite(pinB, b);
  delay(100); //0.1s 간격으로
}
