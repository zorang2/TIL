import numpy as np
import pandas as pd
from torch.utils.data import Dataset
from skimage import io, transform
import torch
import glob

IMG_PATH = "/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_Images/"
LABEL_PATH = "/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/"

f = open(LABEL_PATH + "training.csv")
lines = f.readline()
print(lines)


# df = pd.read_csv(LABEL_PATH + "validation.csv")
# print(df.drop([0], axis=0))
# print(df.iloc[:,[0,6]])



'''
self.img = img_
self.label = label_
self.transform = transform

def __getitem__(self, idx):
img_read = io.imread(self.img[idx])
label_read = label
'''


