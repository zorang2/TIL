import os
from glob import glob
import cv2
from tqdm import tqdm
import sys
import numpy as np
import pandas as pd
from PIL import Image



train_csv = "/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/training.csv"
valid_csv = "/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/validation.csv"

def AffectNet_csv_facial_landmarks(file):
    df_train = pd.read_csv(file)
    # print('df_train 요약 :', df_train.columns)
    cols = list(df_train.columns[5:-3])
    df_train['combined'] = df_train[cols].apply(lambda row: ';'.join(row.values.astype(str)), axis=1)
    df_train.drop(labels = cols, axis=1, inplace=True)
    # print(df_train.columns.to_list())
    df_train = df_train[['subDirectory_filePath', 'face_x', 'face_y', 'face_width', 'face_height', 'combined', 'expression', 'valence', 'arousal']]
    df_train = df_train.rename(columns={'combined' : 'facial_landmarks'})
    return df_train

train = AffectNet_csv_facial_landmarks(train_csv)
valid = AffectNet_csv_facial_landmarks(valid_csv)


all_data = pd.concat([train, valid])

# for i, row in all_data.iterrows():
#     all_data.loc[i, 'subDirectory_filePath'] = row['subDirectory_filePath'].split('/')[-1]

# print(all_data)

# # sys.exit()

name_column = all_data['subDirectory_filePath'].to_numpy()
change_name = lambda name: name.split('/')[-1]

name_column = np.array([change_name(name) for name in name_column])
name_column = pd.DataFrame(name_column)
all_data['subDirectory_filePath'] = name_column
all_data.reset_index()

# print(all_data)

facial_landmarks = []
path = glob('/home/sldev1/Desktop/fer/affectnet_full/*/*/*', recursive=True)

for image_path in tqdm(path):
    # try:
    image = cv2.imread(image_path)
    image_name = image_path.split('/')[-1]
    try:
        # print(all_data.loc[all_data['subDirectory_filePath'] == image_name, ['subDirectory_filePath','facial_landmarks']].values[0])
    # print('image_name : ' + image_name)
    # print(all_data.loc[all_data['subDirectory_filePath'] == image_name, ['subDirectory_filePath','facial_landmarks']].values)
        facial_landmarks.append(all_data.loc[all_data['subDirectory_filePath'] == image_name, ['subDirectory_filePath','facial_landmarks']].values[0])
    except Exception as e:
        print(e)

np.save('/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/facial_infomation.npy', np.array(facial_landmarks))
