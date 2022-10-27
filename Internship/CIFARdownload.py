import torch
import torchvision
import torchvision.transforms as tr
from torch.utils.data import DataLoader, Dataset
import numpy as np

transf = tr.Compose([tr.Resize(8), tr.ToTensor()])

trainset = torchvision.datasets.CIFAR10(root='/home/sldev1/Project/hyeongeun_test/data', train=True, download=True, transform=transf)
testet = torchvision.datasets.CIFAR10(root='/home/sldev1/Project/hyeongeun_test/data', train=False, download=True, transform=transf)

#print(trainset[0][0].size()) #img
#print(trainset[0][1]) #label

trainloader = DataLoader(trainset, batch_size=50, shuffle=True, num_workers=2)
testloader = DataLoader(testet, batch_size=50, shuffle=True, num_workers=2)

print(len(trainloader))



'''

trainset = torchvision.datasets.CIFAR10(root='./data', train=True,
                                        download=True, transform=transf)
trainloader = torch.utils.data.DataLoader(trainset, batch_size=batch_size,
                                          shuffle=True, num_workers=2)
testset = torchvision.datasets.CIFAR10(root='./data', train=False,
                                          download=True, transform=transf)
testloader = torch.utils.data.DataLoader(testset, batch_size=batch_size,
                                         shuffle=False, num_workers=2)

classes = ('plane', 'car', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck')




import matplotlib.pyplot as plt
import numpy as np

#이미지를 보여주기 위한 함수
def imshow(img):
    img = img / 2 + 0.5 # unnormalize
    npimg = img.numpy()
    plt.imshow(np.transpose(npimg, (1, 2, 0)))
    plt.show()

#학습용 이미지를 무작위로 가져오기
dataiter = iter(trainloader)
images, labels = dataiter.next()

#이미지 보여주기
imshow(torchvision.utils.make_grid(images))
#정답(label) 출력
print(' '.join(f'{classes[labels[j]]:5s}' for j in range(batch_size)))

'''