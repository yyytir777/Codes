# Importing necessary libraries
import sys, os
sys.path.append(os.pardir)
import numpy as np
from PIL import Image
from dataset.mnist import load_mnist

from KNN import KNN
from LogisticRegression import LogisticRegression

#load data
(x_train, y_train), (x_test, y_test) = load_mnist(flatten=True, normalize=True)

# KNN 실행
# clf1 = KNN(x_train, y_train, x_test, y_test, k = 5)                
# clf1.run()

def img_show(img):
    pil_img = Image.fromarray(np.uint8(img))
    pil_img.show()

image = x_test[3]
image = image.reshape(28,28)
# img_show(image)


clf2 = LogisticRegression(0.00002, 10000, x_train.astype('float32')/255.0, y_train, x_test.astype('float32')/255.0, y_test, 3)
clf2.run()

