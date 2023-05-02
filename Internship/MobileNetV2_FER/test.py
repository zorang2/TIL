import torch
from torchvision import datasets, transforms
from torch.utils.data import DataLoader
from torchvision.models import mobilenet_v2


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



bs = 64
crop_size = 224

train_transform = transforms.Compose([
    transforms.RandomRotation(10),
    transforms.RandomResizedCrop(crop_size, scale=(0.8, 1.0)),
    transforms.RandomHorizontalFlip(),
    transforms.ToTensor(),
    transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
    ])

test_transform = transforms.Compose([
    transforms.Resize(230),
    transforms.CenterCrop(crop_size),
    transforms.ToTensor(),
    transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
    ])

train_set = datasets.ImageFolder("/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_compressed/train", transform=train_transform)
trainloader = DataLoader(train_set, batch_size=bs, shuffle=True, num_workers=2)

val_set = datasets.ImageFolder("/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_compressed/valid", transform=test_transform)
valloader = DataLoader(val_set, batch_size=bs, shuffle=True)

test_set = datasets.ImageFolder("/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_compressed/test", transform=test_transform)
testloader = DataLoader(test_set, shuffle=True)

dataiter = iter(trainloader)
images, labels = dataiter.next()
print(images.size())
print(labels)

device = 'cuda:1'
model = mobilenet_v2()

model.apply(init_weights)
model = model.to(device)

learning_rate = 0.001
num_epoch = 200
model_name = '05.02_16:02_test.pth'

loss_fn = nn.CrossEntropyLoss()
# optimizer = optim.SGD(model.parameters(), lr=learning_rate, momentum=0.9, weight_decay=0.0001)
optimizer = optim.Adam(model.parameters(), lr=learning_rate)
train_loss = 0
valid_loss = 0
correct = 0
total_cnt = 0
best_acc = 0

import time
from tqdm.notebook import tqdm

start = time.time()  # 시작 시간 저장
# Train
writer = SummaryWriter("./runs/11.24_init npyfile load modify 2")
for epoch in tqdm(range(num_epoch), desc="tqdm use first time", total=num_epoch, position=0):

    if epoch == 0:
        start = time.time()  # 시작 시간 저장
    if epoch == 1:
        epoch_time_for_1 = time.time() - start
        timer = epoch_time_for_1 * num_epoch
        print("학습에 총 걸리는 시간 :", timer)

    print(f"====== {epoch + 1} epoch of {num_epoch} ======")
    model.train()
    lr_scheduler(optimizer, epoch)
    train_loss = 0
    valid_loss = 0
    correct = 0
    total_cnt = 0

    # Train Phase
    for step, batch in tqdm(enumerate(trainloader), desc="train_loader 1epoch",
                            total=len(trainloader), position=1, leave=True):
        #  input and target
        batch[0], batch[1] = batch[0].to(device), batch[1].to(device)
        optimizer.zero_grad()

        logits = model(batch[0])  # batch[0]=이미지, batch[1]=라벨
        loss = loss_fn(logits, batch[1])
        # loss.backward()
        # optimizer.step()

        train_loss += loss.item()
        # _, predict = logits.max(1)
        _, predict = torch.max(logits, dim=1)

        total_cnt += batch[1].size(0)
        correct += predict.eq(batch[1]).sum().item()

        if step % 1000 == 0 and step != 0:
            print(f"\n====== {step} Step of {len(trainloader)} ======")
            print(f"Train Acc : {correct / total_cnt}")
            print(f"Train Loss : {loss.item() / batch[1].size(0)}")

        loss.backward()
        optimizer.step()

    train_acc_visual = (correct / total_cnt) * 100
    # train_loss_visual = train_loss / batch[1].size(0)
    train_loss_visual = train_loss / total_cnt
    writer.add_scalar('acc/train', train_acc_visual, epoch)
    writer.add_scalar('loss/train', train_loss_visual, epoch)

    correct = 0
    total_cnt = 0

    # Test Phase
    with torch.no_grad():
        model.eval()
        for step, batch in enumerate(testloader):
            # input and target
            batch[0], batch[1] = batch[0].to(device), batch[1].to(device)
            total_cnt += batch[1].size(0)
            logits = model(batch[0])
            valid_loss += loss_fn(logits, batch[1])
            _, predict = logits.max(1)
            correct += predict.eq(batch[1]).sum().item()
        valid_acc = correct / total_cnt
        print(f"\nValid Acc : {valid_acc}")
        print(f"Valid Loss : {valid_loss / total_cnt}")

        valid_acc_visual = valid_acc * 100
        valid_loss_visual = valid_loss / total_cnt
        writer.add_scalar('acc/valid', valid_acc_visual, epoch)
        writer.add_scalar('loss/valid', valid_loss_visual, epoch)

        if (valid_acc > best_acc):
            best_acc = valid_acc
            # torch.save(model, model_name)
            # print("Model Saved!")
            torch.save(model.state_dict(), model_name)
            print('Model Saved!')