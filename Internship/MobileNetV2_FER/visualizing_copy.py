import numpy as np
import pandas as pd
from torch.utils.data import Dataset
from skimage import io, transform
import torch
import glob

IMG_PATH = "/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_Images/"
LABEL_PATH = "/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/"


df = pd.read_csv(LABEL_PATH + "validation.csv")
Path_len = len(df['subDirectory_filePath'])
for i in range(Path_len):
    img_ = []
    label_ = []
    img = IMG_PATH + df['subDirectory_filePath'][i]
    label = LABEL_PATH + df['FER'][i]
    img_.append(img)
    label_.append(label)


'''
self.img = img_
self.label = label_
self.transform = transform

def __getitem__(self, idx):
img_read = io.imread(self.img[idx])
label_read = label
'''


