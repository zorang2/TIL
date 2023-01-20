import torch
import numpy as np
import cv2
from mobilenetv2 import mobilenet_v2
from torchvision.transforms import transforms

class Emotion:
    def __init__(self):
        self.emo_model = self.model_load()

    def model_load(self):
        model_path = './mobilenet_v2_affectnet_2023_01_12_07.37'
        emo_model = mobilenet_v2(in_channels=3, num_classes=8)

        state = torch.load(model_path, map_location='cpu')
        emo_model.load_state_dict(state['net'])
        emo_model.eval()
        return emo_model

    def process(self, img):
#         image_arr =cv2.resize(img,(256,256))
#         image_arr = image_arr.reshape(1,3,256,256)
#         image_arr = image_arr[...,::-1].astype("float")
#         image_arr = image_arr/255.
#         image_arr = torch.Tensor(image_arr)
        transform = transforms.Compose([
                                transforms.ToTensor(),])
        
#         img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        img = transform(img)
        out = self.emo_model(img.unsqueeze(dim=0))
        expr = out['expression']
        expr = np.argmax(expr.cpu().detach().numpy(), axis=1)
        return expr.item()
        
        
        
        
        
        
        
#         try:
#             image_arr =cv2.resize(img,(256,256))
#             image_arr = image_arr.reshape(1,256,256,3)
#             image_arr = image_arr[...,::-1].astype("float")
#             image_arr = image_arr/255.
# #             predicted_saved = self.emoModel.predict(image_arr)
#             out = self.emo_model(image_arr)
#             expr = out['expression']
#             expr = np.argmax(expr.cpu().numpy(), axis=1)
    
# #             return np.argmax(predicted_saved[0]), predicted_saved[1][0][0], predicted_saved[2][0][0]
#             return expr


#         except Exception as e:
#             print(str(e))





#         image_arr =cv2.resize(img,(256,256),cv2.INTER_AREA)
#         image_arr = image_arr.reshape(1,256,256,3)
#         image_arr = image_arr[...,::-1].astype("float")
#         image_arr = image_arr/255.
#         predicted_saved = self.emoModel.predict(image_arr)
#         return np.argmax(predicted_saved[0]), predicted_saved[1][0][0], predicted_saved[2][0][0]

