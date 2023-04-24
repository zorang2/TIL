from __future__ import print_function
import io
import os
import sys
import random
import cv2
import pandas as pd
from PIL import Image
import csv


base = "/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_Images/"
done = "/home/sldev1/Desktop/fer/affectnet_full/Manually_train_croped/"
csv_file = "/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/training.csv"
new_val_txt = open('/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/train.txt','w')

fname = []
face_x = []
face_y = []
face_width = []
face_height = []
expression = []
num = 0

with open(csv_file, 'r') as csvfile: # with as 구문은 file을 열고서 닫지 않는 실수를 줄이는 용도
    reader = csv.DictReader(csvfile)
    print(reader)
    '''
    for row in reader:
        num += 1
        fname = row['subDirectory_filePath']
        x = int(row['face_x'][0:])
        y = int(row['face_y'][0:])
        width = int(row['face_width'][0:])
        height = int(row['face_height'][0:])
        expression = int(row['expression'][0:])
        floder_dir = fname.split('/')[0]
        img = fname.split('/')[1]
        image = cv2.imread(os.path.join(base, fname))

        # write name & expression to new txt
        if expression < 7:
            new_val_txt.write(fname)
            new_val_txt.write(' ')
            new_val_txt.write(str(expression))
            new_val_txt.write('\n')

        # process img
        try:
            imgROI = image[x:x + width, y:y + height]
        except:
            pass
        imgROI = cv2.resize(imgROI, (224, 224), interpolation=cv2.INTER_AREA)
        gray = cv2.cvtColor(imgROI, cv2.COLOR_BGR2GRAY)
        if not os.path.isdir('./Manually_train_croped/' + floder_dir):
            os.mkdir('./Manually_train_croped/' + floder_dir)
        cv2.imwrite(done + floder_dir + '/' + img, gray)
        print(fname)
        cv2.waitKey(0)

    print(num)'''





'''
# Read in training csv
train_df = pd.read_csv(IMG_PATH, usecols=['subDirectory_filePath', 'expression']) #int32 if breaks

# Read in validation csv
valid_df = pd.read_csv(LABEL_PATH, usecols=['subDirectory_filePath', 'expression'],
                       dtype={'subDirectory_filePath': 'string', 'expression': 'int16'})



# Remove sub folder at beginning of image name
train_df['subDirectory_filePath'] = train_df['subDirectory_filePath'].map(lambda x: x.split('/', 1)[-1])
valid_df['subDirectory_filePath'] = valid_df['subDirectory_filePath'].map(lambda x: x.split('/', 1)[-1])

# Combine dataframes
combined_df = train_df.append(valid_df)

# Get all filenames and labels as seperate lists
filenames = list(combined_df['subDirectory_filePath'])
labels = list(combined_df['expression'])

'''





'''
# f = open(LABEL_PATH + "training.csv")
# lines = f.readline()
# print(lines)


df = pd.read_csv(LABEL_PATH + "validation.csv")
print(df.drop([0], axis=0))
print(df.iloc[:,[0,6]])

'''




