이 디렉토리는 affectnet 8class를   
paser로 구동하기 위해서 새롭게 시작하는 디렉토리입니다.   

정상적인 학습 후, confusion matrix까지 표현해야 합니다. 

일단 8 classes 진행 중   
($ python Affectnet_8classes_train.py --epoch=40 --lr=0.001 --batch_size=64 --val_batch_size=16 --gpu=1)
![Screenshot from 2023-05-17 08-21-42.png](..%2F..%2F..%2F..%2F..%2FDesktop%2FScreenshot%20from%202023-05-17%2008-21-42.png)
결과 = Acc 49%로 모델 저장X (40 epoch = 38.5시간 소요)

### 05/18
- CleanSet(emonet pickle(val_fullpath.pkl)) + Custom MobileNetV2 기반 재 학습 목표
- 현재 Valid용 CleanSet을 위해서 csv작업중........ㅠ 실패했음

### 05/19
- CleanSet csv 작업, MobileNetV2 Class로 구현 및 학습 작업 완료
- ($ python Affectnet_8classes_train.py --epoch=40 --lr=0.001 --batch_size=64 --val_batch_size=16 --gpu=1)
  - FileNotFoundError: [Errno 2] No such file or directory: './checkpoint/epoch25_acc0.5578.pth'
    - checkpoint라는 디렉토리 다시 만들고 똑같이 학습돌림(05/23)
      - [Epoch 39] Train time:60.31, Training accuracy:0.8390. Loss: 5.058 LR:0.000464
      - [Epoch 39] Validation accuracy:0.6491, Loss:1.757, f1 0.622471, score 0.631259
      - best_acc:0.6491 (05/23)

### 05/26 ~ 31
($ python Affectnet_8classes_train.py --epoch=100 --lr=0.001 --batch_size=64 --val_batch_size=16 --gpu=1)
![Screenshot from 2023-05-31 09-15-35.png](..%2F..%2F..%2F..%2F..%2FDesktop%2FScreenshot%20from%202023-05-31%2009-15-35.png)
결과 = Acc 69.6%로 모델 저장O (98 epoch, 총 100epoch로 102시간 39분 소요됨)

### 06/12 ~ 14
[Epoch 199] Train time:61.84, Training accuracy:0.8816. Loss: 4.780 LR:0.000018   
[Epoch 199] Validation accuracy:0.7827, Loss:1.482, f1 0.746082, score 0.758166   
Model saved.   
best_acc:0.7827   
100%|██████ | 199/200 [204:27:06<1:02:02, 3723.00s/it]   

[Epoch 200] Train time:61.05, Training accuracy:0.8819. Loss: 4.778 LR:0.000018   
[Epoch 200] Validation accuracy:0.7791, Loss:1.483, f1 0.743108, score 0.754986   
100%|██████| 200/200 [205:28:38<00:00, 3698.59s/it]   
결과 = Acc 78.27%로 모델 저장 (199 Epoch, 총 200epoch로 205.5시간 소요됨.)   

1. 민규 선임님께 학습 제대로 되었는지 코드 봐달라 하기
2. Confusion matrix 코드 공유 가능한지 여쭤보기   



