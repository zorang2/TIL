# 이미지를 랜덤하게 뽑아내어 그 이미지의 FER 결과를 알아보는 code

import pandas as pd
import cv2
import matplotlib.pyplot as plt  # plot

import os
from os.path import join

label_path = ('/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/')
img_path = ('/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_Images/')
file = (label_path + 'training.csv')
df = pd.read_csv(file)
print(df.head())


# display random images

import random

fig, axs = plt.subplots(2, 4)
fig.suptitle("Sample Faces and Labels")
axs = axs.flatten()

for i in range(8):
    idx = random.randint(0, len(df)-1)  # randomly select an index

    path = img_path + df['subDirectory_filePath'][idx]
    img = cv2.imread(path)  # read image
    img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)  # convert to BGR to RGB
    axs[i].imshow(img)
    axs[i].set_title(df['FER'][idx])
plt.show()