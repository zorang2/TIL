'''
https://tutorials.pytorch.kr/beginner/nn_tutorial.html
이해를 돕기 위해서, 먼저 아무 feature도 사용하지 않고
MNIST Dataset에 대해 기초적인 신경망을 학습시킬 것임.
우리는 처음에 가장 기초적인 Pytorch tensor기능만 사용할 것임.
나아가, torch.nn, torch.optim, Dataset, DataLoader 등
한번에 하나씩 feature를 추가하면서, 정확히 각 부분이 어떤 드일을 하는지
그리고 이것이 어떻게 코드를 더 간결하고 유연하게 만드는지 보여줄 것임.
'''

########################################3################# MNIST 데이터 준비
from pathlib import Path # Python3 표준 라이브러리의 일부, 경로 설정 담당
                         # pathlib 모듈의 기본 아이디어는 파일시스템 경로를 단순한 문자열이 아니라 객체로 다루자는 것.
import requests #데이터셋 다운로드

DATA_PATH = Path("data")
PATH = DATA_PATH / "mnist"
PATH.mkdir(parents=True, exist_ok=True) # parents=False(기본값) : 부모 디렉토리 없으면 FileNotFoundError
                                         # parents=True : 부모 디렉토리 없으면 만들어라.
                                         # exists_ok=False(기본값) : 해당 디렉토리 있으면 FileExistsError
                                         # exists_ok=True : FileExistsError 무시

URL = "https://github.com/pytorch/tutorials/raw/master/_static/"
FILENAME = "mnist.pkl.gz"

if not (PATH / FILENAME).exists(): # Path.exists() : 경로가 기존 파일 또는 디렉터리를 가르키는지 여부(T/F)
    content = requests.get(URL + FILENAME).content
    (PATH / FILENAME).open("wb").write(content)
    # wb = 바이너리 파일 쓰기 위한 모드
    # rb = 바이너리 파일 읽기 위한 모드


########################################3################# 데이터 직렬화
#https://hub1234.tistory.com/m/26 (데이터 직렬화가 왜 필요한지)
import pickle # 데이터 직렬화를 위한 python전용 포멧
import gzip # 파일 압축 및 압축 해제 모듈

with gzip.open((PATH / FILENAME).as_posix(), "rb") as f:
    # gzip.open(filename, mode='rb', compresslevel=9, encoding=None, errors=None, newline=None)
    #  - gzip 압축 파일을 바이너리 or 텍스트 모드로 열고 파일 개체를 반환
    # as_posix()
    #  - 경로의 문자열 포현을 슬래시(/)로 반환. 즉, 백슬래쉬(\\)를 슬래쉬(/)로 반환.
    ((x_train, y_train), (x_valid, y_valid), _) = pickle.load(f, encoding="latin-1")


########################################3################# 이미지 2D 재구성(?)
import matplotlib.pyplot as plt
import numpy as np


plt.imshow(x_train[0].reshape((28, 28)), cmap="gray")
#plt.show()
print(x_train.shape)



########################################################## numpy배열에서 torch.tensor로 데이터 변환
import torch

x_train, y_train, x_valid, y_valid = map(
    torch.tensor, (x_train, y_train, x_valid, y_valid)
)
n, c = x_train.shape
print(x_train, y_train)
print(x_train.shape)
print(y_train.min(), y_train.max())