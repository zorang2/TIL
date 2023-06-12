


# https://skillmemory.tistory.com/entry/%EB%A8%B8%EC%8B%A0%EB%9F%AC%EB%8B%9D-%EB%B6%84%EB%A5%98-%ED%98%BC%EB%8F%99-%ED%96%89%EB%A0%ACConfusion-matrix



import warnings

warnings.filterwarnings(action='ignore')

import numpy as np
import matplotlib.pyplot as plt

from sklearn.svm import SVC
from sklearn.datasets import load_wine
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix
from sklearn.utils.multiclass import unique_labels


# 데이터를 불러와 학습용, 테스트용 데이터로 분리하여 반환하는 함수입니다.
def load_data():
    X, y = load_wine(return_X_y=True)
    class_names = load_wine().target_names

    train_X, test_X, train_y, test_y = train_test_split(X, y, test_size=0.3, random_state=0)

    return train_X, test_X, train_y, test_y, class_names


# Confusion matrix 시각화를 위한 함수입니다.
def plot_confusion_matrix(cm, y_true, y_pred, classes, normalize=False, cmap=plt.cm.OrRd):
    title = ""
    if normalize:
        title = 'Normalized confusion matrix'
    else:
        title = 'Confusion matrix'

    classes = classes[unique_labels(y_true, y_pred)]
    if normalize:
        # 정규화 할 때는 모든 값을 더해서 합이 1이 되도록 각 데이터를 스케일링 합니다.
        cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]

    print(title, ":\n", cm)

    fig, ax = plt.subplots()
    im = ax.imshow(cm, interpolation='nearest', cmap=cmap)
    ax.figure.colorbar(im, ax=ax)
    ax.set(xticks=np.arange(cm.shape[1]),
           yticks=np.arange(cm.shape[0]),
           xticklabels=classes, yticklabels=classes,
           title=title,
           ylabel='True label',
           xlabel='Predicted label')

    # label을 45도 회전해서 보여주도록 변경
    plt.setp(ax.get_xticklabels(), rotation=45, ha="right",
             rotation_mode="anchor")

    # confusion matrix 실제 값 뿌리기
    fmt = '.2f' if normalize else 'd'
    thresh = cm.max() / 2.
    for i in range(cm.shape[0]):
        for j in range(cm.shape[1]):
            ax.text(j, i, format(cm[i, j], fmt),
                    ha="center", va="center",
                    color="white" if cm[i, j] > thresh else "black")
    fig.tight_layout()

    plt.savefig('confusion matrix.png')


"""
1. 혼동 행렬을 계산하고, 
   시각화하기 위한 main() 함수를 완성합니다.

   Step01. 데이터를 불러옵니다.

   Step02. 분류 예측 결과를 평가하기 위한 혼동 행렬을 계산합니다.

   Step03. confusion matrix를 시각화하여 출력합니다.
           plot_confusion_matrix 함수의 인자를 참고하여 
           None을 채워보세요.

           3-1. 혼동 행렬 시각화 결과를 확인합니다.
           3-2. 함수의 인자 normalize값을 True로 설정하여 
                정규화된 혼동 행렬 시각화 결과를 확인합니다.

"""


def main():
    train_X, test_X, train_y, test_y, class_names = load_data()

    # SVM 모델로 분류기를 생성하고 학습합니다.
    classifier = SVC()
    y_pred = classifier.fit(train_X, train_y).predict(test_X)

    cm = confusion_matrix(test_y, y_pred)

    plot_confusion_matrix(cm, test_y, y_pred, classes=class_names)

    # 정규화 된 혼동 행렬을 시각화합니다.
    plot_confusion_matrix(cm, test_y, y_pred, classes=class_names, normalize=True)

    return cm


if __name__ == "__main__":
    main()





'''
import itertools

import numpy as np
from sklearn.metrics import confusion_matrix
import matplotlib.pyplot as plt


def main():
    plot_confusion_matrix()


def plot_confusion_matrix(cm, target_names=None, cmap=None, normalize=True, labels=True, title='Confusion matrix'):
    accuracy = np.trace(cm) / float(np.sum(cm))
    misclass = 1 - accuracy

    if cmap is None:
        cmap = plt.get_cmap('Blues')

    if normalize:
        cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]

    plt.figure(figsize=(8, 6))
    plt.imshow(cm, interpolation='nearest', cmap=cmap)
    plt.title(title)
    plt.colorbar()

    thresh = cm.max() / 1.5 if normalize else cm.max() / 2

    if target_names is not None:
        tick_marks = np.arange(len(target_names))
        plt.xticks(tick_marks, target_names)
        plt.yticks(tick_marks, target_names)

    if labels:
        for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
            if normalize:
                plt.text(j, i, "{:0.4f}".format(cm[i, j]),
                         horizontalalignment="center",
                         color="white" if cm[i, j] > thresh else "black")
            else:
                plt.text(j, i, "{:,}".format(cm[i, j]),
                         horizontalalignment="center",
                         color="white" if cm[i, j] > thresh else "black")

    plt.tight_layout()
    plt.ylabel('True label')
    plt.xlabel('Predicted label\naccuracy={:0.4f}; misclass={:0.4f}'.format(accuracy, misclass))
    plt.show()
'''