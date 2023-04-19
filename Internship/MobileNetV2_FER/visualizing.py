import numpy as np
import pandas as pd
from torch.utils.data import Dataset
from skimage import io, transform
import torch
import glob

IMG_PATH = "/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_Images/"
LABEL_PATH = "/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/"

'''
df = pd.read_csv(LABEL_PATH + "validation.csv")
Path_len = len(df['subDirectory_filePath'])
img_list = []
for i in range(Path_len):
    img = IMG_PATH + df['subDirectory_filePath'][i]
    img_list.append(img)
'''
# Affectnet: 0: Neutral, 1: Happy, 2: Sad, 3: Surprise, 4: Fear, 5: Disgust, 6: Anger,

class Affectnet(Dataset):

    def __init__(self, train=None, transform=None):

        if train == True:
            df = pd.read_csv(LABEL_PATH + "training.csv")
            Path_len = len(df['subDirectory_filePath'])
        else:
            df = pd.read_csv(LABEL_PATH + "validation.csv")
            Path_len = len(df['subDirectory_filePath'])
        for i in range(Path_len):get
            img_, label_ = []
            img = IMG_PATH + df['subDirectory_filePath'][i]
            label = LABEL_PATH + df['FER'][i]
            img_.append(img)
            label_.append(label)

        self.img = img_
        self.label = label_
        self.transform = transform

    def __getitem__(self, idx):
        img_read = io.imread(self.img[idx])
        label_read = label




    def __getitem__(self, idx):
        img_read = io.imread(self.img[idx])
        label_read = np.load(self.label[idx])
        label_read = label_read.astype(np.int64)
        label_tr = torch.from_numpy(label_read)


# Path_len = len(df[0])
# print(Path_len)
# for i in range(Path_len):
#     print(IMG_PATH + df['subDirectory_filePath'][i])



'''
print('Describe:\n', df.describe())
print('FER:\n', df['FER'])

fer = df['FER']
x = fer.value_counts()
print(x)
print(x[0:10].sum())
# x = fer.unique() # 무슨 데이터로 이루어져 있는지 확인
'''

