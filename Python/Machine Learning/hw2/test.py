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
# 수정 전
# majority vote
# x = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49]
# y = [1, 0.99, 0.99, 0.99, 0.98, 0.98, 0.98, 0.98, 0.97, 0.97, 0.97, 0.98, 0.98, 0.98, 0.98, 0.97, 0.97, 0.97, 0.98, 0.98, 0.97, 0.97, 0.96, 0.96, 0.96]

#weighted majority vote
# x = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49]
# y = [1, 0.98, 0.96, 0.93, 0.93, 0.91, 0.89, 0.86, 0.85, 0.84, 0.84, 0.84, 0.82, 0.8, 0.79, 0.79, 0.79, 0.79, 0.77, 0.74, 0.74, 0.72, 0.72, 0.72, 0.72]

# 수정 후
# majority vote
# x = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29]
# y = [0.7, 0.75, 0.78, 0.8, 0.83, 0.84, 0.83, 0.84, 0.85, 0.84, 0.84, 0.83, 0.83, 0.83, 0.83]

# weighted majority vote
x = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29]
# y = [0.7, 0.75, 0.78, 0.79, 0.83, 0.84, 0.83, 0.84, 0.85, 0.84, 0.84, 0.83, 0.83, 0.83, 0.83]

y = [0.72, 0.75, 0.78, 0.78, 0.795, 0.8, 0.8, 0.815, 0.82, 0.815, 0.815, 0.81, 0.81, 0.805, 0.815]
plt.xlim(0,31)
plt.ylim(0.5, 1)
plt.xlabel("k")
plt.ylabel("accuracy")
plt.plot(x, y)

plt.show()