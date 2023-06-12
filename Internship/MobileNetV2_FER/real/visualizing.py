# 모델 로드 해서 결과 보려고만든 visualizing
import torch
from MoblieNetV2 import MobileNetV2

model = MobileNetV2()
checkpoint = torch.load('./checkpoint/epoch155_acc0.7622.pth')
try:
    checkpoint.eval()
except AttributeError as error:
    print(error)
### 'dict' object has no attribute 'eval'

model.load_state_dict(checkpoint['model_state_dict'])
### now you can evaluate it
model.eval()

'''
from torchinfo import summary
summary(model, (1,3,224,224))
'''
label_tags = {
    0 : 'Neutral',
    1 : 'Happy', #기쁨
    2 : 'Sad', #슬픔
    3 : 'Suprise', #놀람
    4 : 'Fear', #
    5 : 'Disgust', #역겨움
    6 : 'Anger', #분노
    7 : 'Contempt'
}
'''
- 정보 :
    1. batch[0] : 이미지
    2. batch[1] : 라벨
'''

import torch.nn as nn
import torch.optim as optim
import os
import torchvision.models as models
from skimage import io, transform
from torch.utils.tensorboard import SummaryWriter

import torch.backends.cudnn as cudnn
import torch
import re
import PIL
import numpy as np
from PIL import Image
from torch.utils.data import Dataset, DataLoader
import torchvision
import torchvision.transforms as tr
from matplotlib import pyplot as plt
import time

######################################################### random seed fixed
import random

path = "/home/sldev1/Project/hyeongeun_test/data/FER"
torch.manual_seed(0)
torch.cuda.manual_seed(0)
torch.cuda.manual_seed_all(0)
np.random.seed(0)
cudnn.benchmark = False
cudnn.deterministic = True
random.seed(0)

learning_rate = 0.001

########################################################## Simple Learning Rate Scheduler
def lr_scheduler(optimizer, epoch):
    lr = learning_rate
    if epoch == 50:
        lr /= 2
    if epoch == 100:
        lr /= 2
    for param_group in optimizer.param_groups:
        param_group['lr'] = lr


# Xavier
def init_weights(m):
    if isinstance(m, nn.Linear):
        torch.nn.init.xavier_uniform(m.weight)
        m.bias.data.fill_(0.01)


######################################################### 경로 따오고 sort 하는 함수
import glob


def img_load(img_path):
    jpg = glob.glob(img_path + '*.jpg')
    sort_jpg = sorted(jpg, key=lambda s: int(re.findall(r'\d+', s)[1]))
    # print("img_load def is play")
    return sort_jpg


def label_load(label_path):
    # enumerate #파이썬내장함수.. 강민규사원님은 이걸로 쓰셨는데 느리더래
    label = glob.glob(label_path + '*exp.npy')
    sort_label = sorted(label, key=lambda s: int(re.findall(r'\d+', s)[1]))
    # print("label_load def is play")
    return sort_label


from torch.utils.data import Dataset


class MyFERDataset(Dataset):

    def __init__(self, img_path_base, label_path_base, train=None,
                 transform=None):
        super(MyFERDataset, self).__init__()

        if train == True:
            self.img_path = img_path_base + '/train_set/images/'
            self.label_path = label_path_base + '/train_set/annotations/'
        else:
            self.img_path = img_path_base + '/val_set/images/'
            self.label_path = label_path_base + '/val_set/annotations/'

        # img, label path load
        self.img = img_load(self.img_path)
        self.label = label_load(self.label_path)

        # numpy label
        self.label_arr = np.empty([])
        for x in enumerate(self.label):
            label = np.load(x[1])
            self.label_arr = np.append(self.label_arr, label)
        self.label_arr = np.delete(self.label_arr, 0)

        # transform
        self.transform = transform  # image
        # self.target_transform = target_transform # label

    def __getitem__(self, idx):
        img_idx = io.imread(self.img[idx])
        label_idx = self.label_arr[idx]
        label_idx = label_idx.astype(np.int64)
        label_tr = torch.from_numpy(np.asarray(label_idx))

        if self.transform is not None:
            img_tr = self.transform(img_idx)
        # if self.transform is not None:
        #     label_tr = self.transform(label_idx)

        return img_tr, label_tr

    def __len__(self):
        return len(self.label)

    if __name__ == "__main__":
        print('hi, i\'m main')




transform_test = tr.Compose([tr.ToTensor()])
test_dataset = MyFERDataset(img_path_base = path,
                              label_path_base = path,
                              train=False,
                              transform=transform_test)
test_loader = DataLoader(test_dataset, batch_size=32, shuffle=False, num_workers=2)

device = 'cuda:1'

for step, batch in enumerate(test_loader):
    batch[0], batch[1] = batch[0].to(device), batch[1].to(device)

    logits = model(batch[0])
    print("\n******logits*******\n", logits)
    print("\n\n\n******logits_max*******\n", logits.max(1))

    _, predict = torch.max(logits, dim=1)
    # _, predict = logits.max()
    print("\n\n***********_____***********\n", _, "\n\n**********predict************\n", predict)


data_idx = np.random.randint(len(test_dataset))
print(f"data_idx : {data_idx}\n\n")

input_img = test_dataset[0][0].unsqueeze(dim=0).to(device)
output = model(input_img)




x = torch.max(output, 1)


_, argmax = torch.max(output, 1)
print(f"_ : {_}, \nargmax : {argmax}")
# type(argmax.size())

pred = label_tags[argmax.item()]
x = label_load("/home/sldev1/Project/hyeongeun_test/data/FER/val_set/annotations/")[0].split('/')

import cv2

columns = 6
rows = 6
fig = plt.figure(figsize=(25, 25))

# inference
for i in range(1, columns * rows + 1):
    data_idx = np.random.randint(4000)
    input_img = test_dataset[data_idx][0].unsqueeze(dim=0).to(device)

    output = model(input_img)
    _, argmax = torch.max(output, 1)
    pred = label_tags[argmax.item()]
    # test_dataset = test_dataset.numpy()
    label = label_tags[test_dataset[data_idx][1].item()]

    x = label_load("/home/sldev1/Project/hyeongeun_test/data/FER/val_set/annotations/")[data_idx].split('/')
    x = x[-1]

    fig.add_subplot(rows, columns, i)
    if pred == label:
        plt.title(pred + ', right !!\n index : ' + str(x))
        cmap = 'Blues'
    else:
        plt.title('Predict : ' + pred + ' / Answer : ' + label + '\n index :' + str(x))
        cmap = 'Reds'
    plot_img = test_dataset[data_idx][0][0, :, :]
    plt.imshow(plot_img, cmap=cmap)
    # plt.imshow(plot_img)
    plt.axis('off')

plt.show()