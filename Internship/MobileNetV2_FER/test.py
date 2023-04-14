import torch
from torchvision import datasets, transforms
from torch.utils.data import DataLoader
# from torchvision.models import mobilenet_v2

bs = 128
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

train_set = datasets.ImageFolder("/home/sldev1/Desktop/172.20.33.22/mingyu.kang/5.FER/affectnet_full/Manually_Annotated_Images", transform=train_transform)
trainloader = DataLoader(train_set, batch_size=bs, shuffle=True, num_workers=2)

# val_set = datasets.ImageFolder("/home/sldev1/Desktop/172.20.33.22/mingyu.kang/5.FER/affectnet_full/Manually_Annotated_Images", transform=test_transform)
# valloader = DataLoader(val_set, batch_size=bs, shuffle=True)
#
# test_set = datasets.ImageFolder("/home/sldev1/Desktop/172.20.33.22/mingyu.kang/5.FER/affectnet_full/Manually_Annotated_Images", transform=test_transform)
# testloader = DataLoader(test_set, shuffle=True)