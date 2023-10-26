import sys, os
sys.path.append(os.pardir)
from dataset.mnist import load_mnist
from PIL import Image
import numpy as np
import matplotlib.pyplot as plt

(x_train, y_train), (x_test, y_test) = load_mnist(flatten=True, normalize=False)

def img_show(img):
    pil_img = Image.fromarray(np.uint8(img))
    pil_img.show()

# image = x_test[1:2]
# image = image.reshape(28,28)
# img_show(image)

lst = [0,1,2,3,4,5,6,7]

# print(y_test[0:100])

# print(y_train[0:10])

# test : [7 2 1 0 4 1 4 9 5 9]

# train : [5 0 4 1 9 2 1 3 1 4]
x = [3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49]
y = [0.99, 0.99, 0.99, 0.98, 0.98, 0.98, 0.98, 0.97, 0.97, 0.97, 0.98, 0.98, 0.98, 0.98, 0.97, 0.97, 0.97, 0.98, 0.98, 0.97, 0.97, 0.96, 0.96, 0.96]
plt.xlabel("k")
plt.ylabel("accuracy")
plt.scatter(x, y)

plt.show()