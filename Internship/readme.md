# This repository is a TIL created during an internship at [SL Corporation](http://www.slworld.com/).

## Sep

* env py3.6 version 정리
    - torch : 1.10.0
    - 파이참 터미널 cuda : 9.1.85
    - 로컬 터미널 cuda : 10.2.89

* env py3.7 version 정리
    - torch : 1.7.0
    - 파이참 터미널 cuda : 9.1.85
    - 로컬 터미널 cuda : 10.2.89
    
    


## Oct

목표 : 15333   
torch vision mnist dataset 불러오기   
classification cifar-100   

10/19(수) 아래 유튜브 정독 완료.   
https://www.youtube.com/watch?v=WjkXTZK3P0A&list=PLHOsBEAyYj3xf4i20sCA5o8MgVW5sIiHD&index=16

10/20(목) 유튜브 실습 + dataload + 전처리 포스팅하기.   

## Nov

### 11/09(수), 11/10(목)   

1. tensorboard를 활용한 실시간 데이터 학습 점검   
2. Model, FLOPs, Params, Accuracy, TestDataset 작성하기.   

|Model|FLOPs|Params|Accuracy(%)|TestDataset|
|--|--|--|--|--|
|EmoNet|16.94G|14 M|75.89|AffectNet-8(상명대, 8-Labels)|
|VggNet|---.---G|-- M|--.--|AffectNet-8(상명대, 8-Labels)|
|ResNet|---.---G|-- M|--.--|AffectNet-8(상명대, 8-Labels)|






### 11/11(금). 11/14(월)

|Model|FLOPs|Params|TestDataset|Total Epoch|val Acc (Epoch)|train Acc|MaxEpoch 걸리는 시간(h)|
|--|--|--|--|--|--|--|--|
|VggNet|15.48 G|138 M|AffectNet-8(상명대, 8-Labels)|17|29.1 % (2)|70.1 %|298|
|ResNet|3.86 G|23 M|AffectNet-8(상명대, 8-Labels)|35|43.9 % (15)|98.3 %|134|
|MobileNet|0.53 G|3.2 M|AffectNet-8(상명대, 8-Labels)|10|42.9 % (9)|- %|47|
|MobileNet|0.53 G|3.2 M|AffectNet-8(상명대, 8-Labels)|200|45.2 % (33)|95.9 %|47|

<details>
<summary>더보기(결과 그래프)</summary>

<!-- summary 아래 한칸 공백 두어야함 -->
### VggNet, ResNet, MobileNet 순서
<img src="./img/vgg_fer.png" width="300" height="300">
<img src="./img/resnet_fer.png" width="300" height="300">
<img src="./img/mobilenet_fer.png" width="300" height="300">
### 11/15(화) 확인된 내용 = 그래프 이상한 이유
    train, valid loss 관련,
    - backward 메소드 잘못 배치 함 + train_loss_visual = loss.item() 부분 잘못 함.
</details>



- VggNet 경로 : 
    - "Internship/VGG_FER/[11.11][tensorboard, 17에폭, valid acc 29%] VGG.ipynb"
- ResNet 경로 : 
    - "Internship/ResNet_FER/[11.11][tensorboard, 35에폭, valid acc 43%] ResNet.ipynb"   
- MobileNet 경로 : 
    - "Internship/MobileNet_FER/[11.11][tensorboard, 200에폭, valid acc 45.2%] MobileNet.ipynb"   

### 11/14(월)

#### 민규 사원님 Feedback   
---
1. loss 먼저 넣고 backward+step vs backward+step후 loss의 차이점을 찾아보라. ==> 진행 중.
2. train_loss_visual = loss.item() 이 아니라, = train_loss다. 고쳐라. ==> Complite.
3. 학습 시키고 valid loss 차이점 체크해봐라(because 원인 미상) ==> ?
4. Dataloader부분, 아래의 1, 2의 시간 비교 해봐라
    1. init에서 통째로 load
    2. getitem에서 차례로
<details>
<summary>더보기(결과 그래프)</summary>

<!-- summary 아래 한칸 공백 두어야함 -->
#### "2. train_loss_visual = loss.item() 이 아니라, = train_loss다. 고쳐라"의 결과
<img src="./img/resnet_fer_after_feedback.png" width="300" height="300">
</details>

---



### 11/15(화)

#### 상준 선임님 과제
---
1. MobileNet Epoch 끝까지 돌려서 보고하기.

<details>
<summary>더보기(결과 그래프)</summary>

<!-- summary 아래 한칸 공백 두어야함 -->
### MobileNet 이미지 고쳐야됨.
<img src="./img/resnet_fer_after_feedback.png" width="300" height="300">
</details>

---

# 11월17일 발견사항 : 현재 실험 코드 차질 생김
[backward후 loss접근, Bad 예상+tensorboard for문안으로] ResNet.ipynb"   
[backward후 loss접근, Bad 예상] ResNet.ipynb"   
이거 둘다 train_loss로 바꿔서 학습시켜야 했는데.,,,,,   
기존에 loss.item()으로 진행함...ㅅㅄㅄㅄㅄㅄㅂ    


### 11/17(목)



#### 11/15 실험을 통해 알게된 부분.
1. step, batch For문이 아니라 Epoch for문에 tensorboard writer가 있어야한다.


#### Conv2d안에 숫자의 의미를 잘 모르며, 실습해보면서 output찍어봐야할 것 같다.
- 참고자료 : https://gaussian37.github.io/dl-pytorch-conv2d/
- VGG code review.ipynb file 참고



<details>
<summary>더보기(결과 그래프)</summary>

<!-- summary 아래 한칸 공백 두어야함 -->
### 왼쪽(Epoch for문 안에 writer), 오른쪽(step, batch for문 안에 writer)
<img src="./img/resnet_11.15_backward+step후 loss접근.png" width="300" height="300">
<img src="./img/resnet_11.15_writer_in_step_batch_for.png" width="300" height="300">
</details>
- Epoch for문 안에 writer 학습 코드 경로 : 
    - "Internship/ResNet_FER/[11.15][backward후 loss접근, Bad 예상] ResNet.ipynb"   
- step, batch for문 안에 writer 학습 코드 경로 : 
    - "Internship/ResNet_FER/[11.15][backward후 loss접근, Bad 예상+tensorboard for문안으로] ResNet.ipynb"   



## 조현근 선정 참고자료
---
[옵티마이저에 대한 좋은 고찰](https://pozalabs.github.io/Optimizer/)   
[Learning Rate Scheduler에 대한 Skill](https://gaussian37.github.io/dl-pytorch-lr_scheduler/)
