이 디렉토리는 affectnet 8class를   
paser로 구동하기 위해서 새롭게 시작하는 디렉토리입니다.   

정상적인 학습 후, confusion matrix까지 표현해야 합니다. 

일단 8 classes 진행 중   
($ python Affectnet_8classes_train.py --epoch=40 --lr=0.001 --batch_size=64 --val_batch_size=16 --gpu=1)
![Screenshot from 2023-05-17 08-21-42.png](..%2F..%2F..%2F..%2F..%2FDesktop%2FScreenshot%20from%202023-05-17%2008-21-42.png)
결과 = Acc 49%로 모델 저장X (40 epoch = 38.5시간 소요)