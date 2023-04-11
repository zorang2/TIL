import torch.nn as nn

class MobileNet(nn.Module):
    super(MobileNet, self).__init__() # class 선언시 super는 뭐고 왜쓰는가

    def conv_bn(inp, oup, stride):
        return  nn.Sequential(
            nn.Conv2d(inp, oup, 3, stride, 1, bias=False),
            nn.BatchNorm2d(oup),
            nn.ReLU(inplace=True)
        )