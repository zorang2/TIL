from re import T
import shutil
import cv2
import os
import random
import numpy as np

def search(dirname, image_list):
    filenames = os.listdir(dirname)
    for filename in filenames:
        full_filename = os.path.join(dirname, filename)
        if os.path.isdir(full_filename):
            search(full_filename, image_list)
        else:
            ext = os.path.splitext(full_filename)[-1]
            if ext == '.mp4':
                image_list.append(full_filename)

video_list = []
search("/home/ubuntu/NAS_CIF/IN_CABIN/YOUTUBE", video_list)

# random.shuffle(image_list)

save_dir = "/home/ubuntu/250GB_SSD/YOUTUBE/"

for video_str in video_list:

    dirname = os.path.dirname(video_str)
    basename = os.path.basename(video_str)   

    if not os.path.exists(save_dir + "/" +basename):
        os.makedirs(save_dir + "/" +basename)


    if os.path.isfile(video_str):	# 해당 파일이 있는지 확인
    # 영상 객체(파일) 가져오기
        cap = cv2.VideoCapture(video_str)

    index = 0
    image_num = 0
    while True:
        # 한 장의 이미지(frame)를 가져오기
        # 영상 : 이미지(프레임)의 연속
        # 정상적으로 읽어왔는지 -> retval
        # 읽어온 프레임 -> frame
        retval, frame = cap.read()
        if not retval:
            break

        index += 1 

        if index % 100 == 0:
            cv2.imwrite(save_dir + "/" +basename+"/" + basename+'_'+'{0:04d}'.format(image_num)+'.jpg',frame)
            index = 0
            image_num += 1
        

            
    if cap.isOpened():	# 영상 파일(카메라)이 정상적으로 열렸는지(초기화되었는지) 여부
        cap.release()	# 영상 파일(카메라) 사용을 종료
    
    # break
