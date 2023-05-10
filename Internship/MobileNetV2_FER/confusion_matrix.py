import random
import torch
from torchvision import datasets, transforms
from torch.utils.data import Dataset, DataLoader
from torchvision.models import mobilenet_v2
from tqdm import tqdm
import numpy as np
import torch.backends.cudnn as cudnn

torch.manual_seed(0)
torch.cuda.manual_seed(0)
torch.cuda.manual_seed_all(0)
np.random.seed(0)
cudnn.benchmark = False
cudnn.deterministic = True
random.seed(0)
learning_rate = 0.001


model = mobilenet_v2()
model.load_state_dict(torch.load("./05.02_16:02_test.pth"))
model.eval()

class_to_idx = {'Happy': 0, 'Sad': 1, 'Surprise': 2, 'Fear': 3, 'Disgust-Contempt': 4, 'Anger': 5}
idx_to_class = {0: 'Happy', 1: 'Sad', 2: 'Surprise', 3: 'Fear', 4: 'Disgust-Contempt', 5: 'Anger'}



bs = 64
crop_size = 224


test_transform = transforms.Compose([
    transforms.Resize(230),
    # transforms.CenterCrop(crop_size),
    transforms.ToTensor(),
    transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
    ])


val_set = datasets.ImageFolder("/home/sldev1/Desktop/fer/affectnet_full/Manually_Annotated_compressed/valid", transform=test_transform)
valloader = torch.utils.data.DataLoader(val_set, batch_size=bs, shuffle=False)



# dataiter = iter(valloader)
# images, labels = dataiter.next()
# print(images.size())
# print(images.unsqueeze_(0).size())
# print(labels)


pre_labels = []
gt_labels = []
with torch.no_grad():
    bingo_cnt = 0
    model.eval()
    for batch_i, (imgs, targets) in enumerate(valloader):
        outputs, features = model(imgs.cuda())
        targets = targets.cuda()
        _, predicts = torch.max(outputs, 1)
        _, predicts = torch.max(outputs, 1)
        correct_or_not = torch.eq(predicts, targets)
        bingo_cnt += correct_or_not.sum().cpu()
        pre_labels += predicts.cpu().tolist()
        gt_labels += targets.cpu().tolist()

    acc = bingo_cnt.float() / float(test_size)
    acc = np.around(acc.numpy(), 4)
    print(f"Test accuracy: {acc:.4f}.")
    cm = confusion_matrix(gt_labels, pre_labels)
    # print(cm)

y_val, y_scores_val = [], []

for image, label in tqdm(val_set, desc="valid image scoring"):
    image.unsqueeze_(0)
    # image = image.cuda()
    scores = model(image)
    scores = scores[0].data.cpu().numpy()
    y_scores_val.append(scores)
    y_val.append(label)

y_scores_val = np.array(y_scores_val)
y_val = np.array(y_val)
print(y_scores_val.shape, y_val.shape)