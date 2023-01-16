# FER(Facial Expression Recognition)

<br/><br/><br/>
## 목표하는 결과물 (~.csv)
| Frame | Emotion | Valence |
|-------|---------|---------|
| 1     | 6       | -1      |
| 2     | 6       | -1      |
| 3     | 2       | -1      |
| 4     | 2       | -1      |
| 5     | 2       | -1      |
| ..    | ..      | ..      |
| ..    | ..      | ..      |
| 68766 | 3       | 1       |


## 어이 없는 점(01/16(월))
- 주말동안 돌려두고 간 코드가 아래와 같은 오류를 뱉어냄<br/>
  `error: OpenCV(4.5.5) /io/opencv/modules/imgproc/src/color.cpp:182: error: (-215:Assertion failed) !_src.empty() in function 'cvtColor'`
- 위 오류 보고 해결했던건데 또 떠있어서 겨우 3시간 돌리고(3명 분) 멈춰있었음
- 근데 그냥 다시 실행해보니까 정상작동함...
- 무엇?


<br/><br/><br/>
## 걱정 되는 점(01/13(금))
- 거의 70~80% 이상, Emotion = 2(sadness) or 6(anger)으로 찍히는 중
- 누가봐도 5(disgust)인데, 그것 마저도 6으로 인지하는 중.
- 그래서 좀 쓸모없는 Output으로 보고될 것이라고 예상 됨.
  - 문제 발생 이유(추측)
    - Camera 각도가 위에서 아래로 얼굴을 찍어서?
    - 해당 딥러닝 모델 자체가 위에서 아래로 얼굴을 찍은 데이터를 학습시키지 않아서?



<br/><br/><br/>
## 용어 정리
- Valence (쾌, 중립, 불쾌)
  - 감정의 긍정 or 부정 정도
  - 공포는 아주 부정적인 valence,
  - 지루함이나 흥분감은 중간 정도의 valence,
  - 행복이나 편안함은 긍정적인 valence를 가짐.
- Arousal(각성)
  - 감정의 흥분 정도를 이야기하는 척도.
  - 값이 작을수록 차분한 감정 (지루함, 편안함, 졸림 등)
  - 값이 클수록 흥분감, 분노, 공포 등이 있음.
- Expression(Emotion, 8classes)
  - 0: neutral
  - 1: joy
  - 2: sadness
  - 3: surprise
  - 4: fear
  - 5: disgust
  - 6: anger
  - 7: contemp


<br/><br/><br/>
## 환경설정
- env : dms2
  - python 3.7.15
  - tensorflow 2.3.1