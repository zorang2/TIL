#include <Servo.h> 
int motor = 5;          // 서보 모터의 핀 번호
int LED = 6;            // LED의 핀 번호
Servo servo; 
 
void setup(){
  Serial.begin(9600);    // 시리얼 통신, 속도는 9600
  servo.attach(motor);    // 모터 시작
  pinMode(motor,OUTPUT);  // 모터 출력
}
void loop(){
    int sensor = analogRead(A0);          // 조도센서의 데이터 받아오기
    if (sensor > 1000){                   // 주위가 어둡다면
      digitalWrite(LED, HIGH);            // led 켜주기            
      for(int i = 0; i < 180; i++){       // 서보 모터의 각도를 180도로
      servo.write(i);                     
      delay(10); 
      }
      while(sensor >=1000 && sensor <= 1023){    // 조도센서의 빛 밝기에 변함이 없을 때
      delay(100); 
      sensor = analogRead(A0);                   // 조도센서의 값 재입력
      }
      
    }else {                                      // 주위가 밝다면
      digitalWrite(LED, LOW);                    // led꺼주기      
      for(int k = 180; k>  0; k--){              // 서보모터의 각도를 0도로      
       servo.write(k); 
       delay(10); 
      }  
      while(sensor >= 0 && sensor < 1000){       // 조도센서의 빛 밝기에 변함이 없을 때     
      delay(100);
      sensor = analogRead(A0);                   // 조도센서의 값 재입력
     }
    }
} 
