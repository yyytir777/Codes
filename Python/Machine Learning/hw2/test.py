import sys, os
sys.path.append(os.pardir)
from dataset.mnist import load_mnist
from PIL import Image
import numpy as np

(x_train, y_train), (x_test, y_test) = load_mnist(flatten=True, normalize=False)

def img_show(img):
    pil_img = Image.fromarray(np.uint8(img))
    pil_img.show()

# image = x_test[1:2]
# image = image.reshape(28,28)
# img_show(image)

lst = [0,1,2,3,4,5,6,7]

# print(y_test[0:100])

print(y_test[0:10])