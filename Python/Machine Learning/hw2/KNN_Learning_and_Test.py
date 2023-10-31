# Importing necessary libraries
import sys, os
sys.path.append(os.pardir)
import numpy as np
from dataset.mnist import load_mnist

from KNN import KNN


#load data
(x_train, y_train), (x_test, y_test) = load_mnist(flatten=True, normalize=False)

# KNN 실행
clf1 = KNN(x_train / 255, y_train, x_test / 255, y_test, k = 3)