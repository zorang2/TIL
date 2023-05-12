# https://github.com/JBalbuenaG/proyecto_DL/blob/467fbbf5bea10f02ad422a33b8b99de765a241d3/Pruebas%20AffectNet/1_AffecNet_Read_and_Division.ipynb

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


############################ expression 추출(train)
df_name = df_train['subDirectory_filePath']
df_exp = df_train['expression']
df_name = pd.DataFrame(df_name, columns=['subDirectory_filePath'])
df_exp = pd.DataFrame(df_exp, columns=['expression'])
df_name.insert(1,'expression',df_exp) # filePath에 expression 삽입
df_name.drop(df_name[(df_name['expression'] > 7) & (df_name['expression'] < 11)].index, inplace=True)
# df_name.to_csv("/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/train_exp_8classes.csv")
# print(df_name['expression'].value_counts())

############################ expression 추출(valid)
df_name = df_valid['subDirectory_filePath']
df_exp = df_valid['expression']
df_name = pd.DataFrame(df_name, columns=['subDirectory_filePath'])
df_exp = pd.DataFrame(df_exp, columns=['expression'])
df_name.insert(1,'expression',df_exp) # filePath에 expression 삽입
df_name.drop(df_name[(df_name['expression'] > 7) & (df_name['expression'] < 11)].index, inplace=True)
# df_name.to_csv("/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/valid_exp_8classes.csv")
# print(df_name['expression'].value_counts())






# df_train = pd.concat([df_train, df_valid])
# df_train = df_train.reset_index(drop=True)
# print('Training shape: ', df_train.shape)
#
# emotions_dict = {0: 'neutral', 1: 'happy',
#                  2: 'sad', 3: 'surprise',
#                  4: 'fear', 5: 'disgust',
#                  6: 'anger', 7: 'contempt',
#                  8: 'none', 9: 'uncertain',
#                 10: 'non-face'}
#
# # por Ekman이 정의한 표정만 사용한다. (Happy=0,Sad=1, Anger=2, Fear=3, Disgust/Contempt=4, Surprise=5)
# emotions_test = [1,2,3,4,5,6,7]
#
# keepId_train = df_train.loc[df_train['expression'].isin(emotions_test)]
# df_affect_ekman = keepId_train.copy()
# df_affect_ekman['expression'] = np.where(df_affect_ekman['expression']==7, 5, df_affect_ekman['expression'])
# df_affect_ekman['expression'] = df_affect_ekman['expression']-1
# print(df_affect_ekman['expression'].value_counts())
#
# df_affect_ekman = df_affect_ekman.reset_index(drop=True)
#
# #Se seleccionaran de manera aleatoria solo 8600 muestras de cada emocion, siempre  y cuando se tenga menos cantidad
# #각 감정의 표본 8600개만 무작위로 선택하되, 양이 적으면
# emo0 = df_affect_ekman.loc[df_affect_ekman['expression']==0]
# emo1 = df_affect_ekman.loc[df_affect_ekman['expression']==1]
# emo2 = df_affect_ekman.loc[df_affect_ekman['expression']==2]
# emo3 = df_affect_ekman.loc[df_affect_ekman['expression']==3]
# emo4 = df_affect_ekman.loc[df_affect_ekman['expression']==4]
# emo5 = df_affect_ekman.loc[df_affect_ekman['expression']==5]
#
#
# def sampling_emotions(df, n=8600):
#     row, column = df.shape
#
#     if (row >= n):
#         res = df.sample(n=n)
#     else:
#         res = df
#     return res
#
# emo_process0 = sampling_emotions(emo0)
# emo_process1 = sampling_emotions(emo1)
# emo_process2 = sampling_emotions(emo2)
# emo_process3 = sampling_emotions(emo3)
# emo_process4 = sampling_emotions(emo4)
# emo_process5 = sampling_emotions(emo5)
#
# df_train_2 = pd.concat([emo_process0, emo_process1, emo_process2, emo_process3, emo_process4, emo_process5])
# df_train_2 = df_train_2.reset_index(drop=True)
# print('Training shape: ',df_train_2.shape)
#
# # df_train_2.to_csv("/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_file_lists/training_test.csv")



