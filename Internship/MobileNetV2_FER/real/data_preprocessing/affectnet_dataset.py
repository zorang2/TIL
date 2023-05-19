import torch.utils.data as data
import cv2
import numpy as np
import pandas as pd
import os
import random
from torchvision.datasets import DatasetFolder, ImageFolder

class Affectdataset_8class(data.Dataset):
    def __init__(self, root, dataidxs=None, train=True, transform=None, basic_aug=False, download=False):
        self.root = root
        self.dataidxs = dataidxs
        self.train = train
        self.transform = transform
        # os.chdir(root)

        NAME_COLUMN = 0
        LABEL_COLUMN = 1
        df_train = pd.read_csv(os.path.join(self.root, 'Manually_Annotated_file_lists/train_exp_8classes.csv'))
        # df_valid = pd.read_csv(os.path.join(self.root, 'Manually_Annotated_file_lists/valid_exp_8classes.csv'))
        df_valid = pd.read_csv(os.path.join(self.root, 'Manually_Annotated_file_lists/valid_exp_8classes_cleanset.csv'))
        if self.train:
            dataset = df_train
        else:
            dataset = df_valid

        if self.dataidxs is not None:
            file_names = np.array(dataset.iloc[:, NAME_COLUMN].values)[self.dataidxs]
            self.target = np.array(dataset.iloc[:,LABEL_COLUMN].values)[self.dataidxs]

        else:
            file_names = dataset.iloc[:, NAME_COLUMN].values
            self.target = dataset.iloc[:,LABEL_COLUMN].values
            #

        self.file_paths = []

        for f in file_names:
            # f = f.split(".")[0]
            # f = f + "_aligned.jpg"
            if  self.train:
                path = os.path.join(self.root,'Manually_Annotated_Images/',  f)
            else:
                path = os.path.join(self.root, 'Manually_Annotated_Images/', f)
            self.file_paths.append(path)



        self.basic_aug = basic_aug
        self.aug_func = [flip_image, add_gaussian_noise]
        #######################################################################################

    def __len__(self):
        return len(self.file_paths)

    def get_labels(self):
        return self.target

    def __getitem__(self, idx):


        path = self.file_paths[idx]

        image = cv2.imread(path)
        image = image[:, :, ::-1]  # BGR to RGB
        target = self.target[idx]
        if self.train:
            if self.basic_aug and random.uniform(0, 1) > 0.5:
                index = random.randint(0, 1)
                image = self.aug_func[index](image)

        if self.transform is not None:
            image = self.transform(image)

        return image, target


def add_gaussian_noise(image_array, mean=0.0, var=30):
    std = var**0.5
    noisy_img = image_array + np.random.normal(mean, std, image_array.shape)
    noisy_img_clipped = np.clip(noisy_img, 0, 255).astype(np.uint8)
    return noisy_img_clipped

def flip_image(image_array):
    return cv2.flip(image_array, 1)
