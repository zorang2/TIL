import pandas as pd
import numpy as np


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

df_train = AffectNet_csv_facial_landmarks(train_csv)
df_valid = AffectNet_csv_facial_landmarks(valid_csv)

print('Training shape: ',df_train.shape)
print('Validation shape:',df_valid.shape)

df_train = pd.concat([df_train, df_valid])
df_train = df_train.reset_index(drop=True)
print('Training shape: ', df_train.shape)

emotions_dict = {0: 'neutral', 1: 'happy',
                 2: 'sad', 3: 'surprise',
                 4: 'fear', 5: 'disgust',
                 6: 'anger', 7: 'contempt',
                 8: 'none', 9: 'uncertain',
                10: 'non-face'}

# por Ekman이 정의한 표정만 사용한다. (Happy=0,Sad=1, Anger=2, Fear=3, Disgust/Contempt=4, Surprise=5)
emotions_test = [1,2,3,4,5,6,7]

keepId_train = df_train.loc[df_train['expression'].isin(emotions_test)]
df_affect_ekman = keepId_train.copy()
df_affect_ekman['expression'] = np.where(df_affect_ekman['expression']==7, 5, df_affect_ekman['expression'])
df_affect_ekman['expression'] = df_affect_ekman['expression']-1
print(df_affect_ekman['expression'].value_counts())

df_affect_ekman = df_affect_ekman.reset_index(drop=True)

#Se seleccionaran de manera aleatoria solo 8600 muestras de cada emocion, siempre  y cuando se tenga menos cantidad
#각 감정의 표본 8600개만 무작위로 선택하되, 양이 적으면
emo0 = df_affect_ekman.loc[df_affect_ekman['expression']==0]
emo1 = df_affect_ekman.loc[df_affect_ekman['expression']==1]
emo2 = df_affect_ekman.loc[df_affect_ekman['expression']==2]
emo3 = df_affect_ekman.loc[df_affect_ekman['expression']==3]
emo4 = df_affect_ekman.loc[df_affect_ekman['expression']==4]
emo5 = df_affect_ekman.loc[df_affect_ekman['expression']==5]


def sampling_emotions(df, n=8600):
    row, column = df.shape

    if (row >= n):
        res = df.sample(n=n)
    else:
        res = df
    return res

emo_process0 = sampling_emotions(emo0)
emo_process1 = sampling_emotions(emo1)
emo_process2 = sampling_emotions(emo2)
emo_process3 = sampling_emotions(emo3)
emo_process4 = sampling_emotions(emo4)
emo_process5 = sampling_emotions(emo5)

df_train_2 = pd.concat([emo_process0, emo_process1, emo_process2, emo_process3, emo_process4, emo_process5])
df_train_2 = df_train_2.reset_index(drop=True)
print('Training shape: ',df_train_2.shape)

# df_train_2.to_csv("/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/training.csv")

################ Data Division ###################

new_emotions_dict = {0: 'happy', 1: 'sad',
                     2: 'surprise', 3: 'fear',
                     4: 'disgust-contempt', 5: 'anger'}

from sklearn.model_selection import train_test_split

rnd_seed = 0
df_train, df_test_val = train_test_split(df_train_2,test_size=0.2, random_state=rnd_seed)
df_test, df_val = train_test_split(df_test_val,test_size=0.5, random_state=rnd_seed)

print('Training shape: ',df_train.shape)
print('Validation shape:',df_val.shape)
print('Test shape:',df_test.shape)

df_train = df_train.reset_index(drop=True)
df_val = df_val.reset_index(drop=True)
df_test = df_test.reset_index(drop=True)

# df_train.to_csv("/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/df_training.csv")
# df_val.to_csv("/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/df_validation.csv")
# df_test.to_csv("/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/df_test.csv")



################################## Cropping image and saving cropped faces
a = list(new_emotions_dict.keys())
print(len(a))
values = list(np.zeros(len(a), dtype=np.int32))
d = dict(zip(a,values))
print(d)

import matplotlib.pyplot as plt
import cv2


# This function only works with the AffectNet data and
# could be adapted for similar data.
# Make sure that the index of the dataframe are continous,
# you can use reset_index(drop=true) of pandas
def crop_image_save(df, img_path, emotions_dict, name='train'):
    # Creation of a dictonary to keep a counter for each emotion of
    # the input dictionary
    keys = list(emotions_dict.keys())
    values = list(np.zeros(len(keys), dtype=np.int32))
    emotions_counter = dict(zip(keys, values))

    # Total number of file
    total_files = len(df['expression'])
    for idx in range(total_files):
        # if idx==20:
        #    break;
        img_dir = df['subDirectory_filePath'][idx]  # reading the path of the image
        x = df['face_x'][idx]  # reading the coordinate x for the crop
        y = df['face_y'][idx]  # reading the coordinate y for the crop
        h = df['face_width'][idx]  # reading the width for the crop
        w = df['face_height'][idx]  # reading the height for the crop
        emo = df['expression'][idx]  # reading the emotion

        # Reading each face
        img = cv2.imread(imgs_path + img_dir)
        # cropping the face
        crop_img = img[y:y + h, x:x + w]
        save_path = './data/' + name + '/' + str(emo) + '/' + name + '-' + emotions_dict[emo] + '-' + str(
            emotions_counter[emo]) + '.jpg'
        emotions_counter[emo] += 1
        cv2.imwrite(save_path, crop_img)

        # if emo==4:
        #    print(save_path)
        #    plt.imshow(crop_img)

    return emotions_counter


# Test of the function
imgs_path = '/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_compressed/'
# crop_image_save(df_train, imgs_path, new_emotions_dict, name='train')

crop_image_save(df_train, imgs_path, new_emotions_dict, name='train')
