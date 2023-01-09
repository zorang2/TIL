import cv2
import os
import numpy as np
import pandas as pd
import math

def search(dirname, image_list):
    filenames = os.listdir(dirname)
    for filename in filenames:
        full_filename = os.path.join(dirname, filename)
        if os.path.isdir(full_filename):
            search(full_filename, image_list)
        else:
            ext = os.path.splitext(full_filename)[-1]
            if ext == '.MP4':
                image_list.append(full_filename)


video_list = []
search("/media/sldev1/T7/AR CMS Dataset/Gopro/Gopro_LH/221118_LH", video_list)
save_dir = "/media/sldev1/T7/AR CMS Dataset/frame_output"
Location = '/media/sldev1/T7/AR CMS Dataset/CV22 결과/'
File = 'AR CMS Frame 추출_230105.xlsx'

video_list = video_list[2] # 파일 하나씩 추출하기 위해


# 추출 코드
data_pd = pd.read_excel('{}/{}'.format(Location, File), header=0, index_col=None, names=None, engine='openpyxl')
data_np = pd.DataFrame.to_numpy(data_pd)
# print(data_np["221118_LH_1_1"])
# max = 28 # 파일 별 프레임 수
frames = []
for i in range(28, 50):
    frames.append(math.ceil(data_np[i][1]))

print('추출 할 파일 :', video_list, '\n추출 할 프레임 :', frames)




dirname = os.path.dirname(video_list)
basename = os.path.basename(video_list)

if not os.path.exists(save_dir + "/" +basename):
    os.makedirs(save_dir + "/" +basename)


if os.path.isfile(video_list):
    cap = cv2.VideoCapture(video_list)


while True:
    retval, frame = cap.read()
    if not retval:
        break

    x = int(cap.get(1))
    print("여기서 x:", x)

    for i in frames:
        if x == i:
            cv2.imwrite(save_dir + "/" +basename+"/" + basename+'_'+str(i)+'.jpg', frame)
            print("발견 후 저장", i)
            for j in range(1, 60):
                retval, frame = cap.read()
                if not retval:
                    break
                x1 = cap.get(1)

                cv2.imwrite(save_dir + "/" +basename+"/" + basename+'_'+str(i+j)+'.jpg', frame)
                print("60장 중 i+j", i+j)

if cap.isOpened():	# 영상 파일(카메라)이 정상적으로 열렸는지(초기화되었는지) 여부
    cap.release()	# 영상 파일(카메라) 사용을 종료

