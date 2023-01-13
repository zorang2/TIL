import tensorflow as tf
import numpy as np
import cv2
from tensorflow.python.keras import Model, Sequential

class Emotion:
    def __init__(self):
        self.emoModel = self.model_load()

    def model_load(self):
        with tf.device('/cpu:0'):
#         with tf.device('cuda'):
            saved_model = tf.keras.models.load_model("PRlab_student")

            saved_model.load_weights("PRlab_student_weight.h5")

            return saved_model

    def process(self, img):

        try:
            image_arr =cv2.resize(img,(256,256))
            image_arr = image_arr.reshape(1,256,256,3)
            image_arr = image_arr[...,::-1].astype("float")
            image_arr = image_arr/255.
            predicted_saved = self.emoModel.predict(image_arr)
            return np.argmax(predicted_saved[0]), predicted_saved[1][0][0], predicted_saved[2][0][0]


        except Exception as e:
            print(str(e))
            return -1, -2, -2

#         image_arr =cv2.resize(img,(256,256),cv2.INTER_AREA)
#         image_arr = image_arr.reshape(1,256,256,3)
#         image_arr = image_arr[...,::-1].astype("float")
#         image_arr = image_arr/255.
#         predicted_saved = self.emoModel.predict(image_arr)
#         return np.argmax(predicted_saved[0]), predicted_saved[1][0][0], predicted_saved[2][0][0]

