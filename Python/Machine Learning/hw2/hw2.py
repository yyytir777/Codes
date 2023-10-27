# Importing necessary libraries
import sys, os
sys.path.append(os.pardir)
import numpy as np
from PIL import Image
from dataset.mnist import load_mnist

from KNN import KNN
from LogisticRegression import LogisticRegression

import matplotlib.pyplot as plt

#load data
(x_train, y_train), (x_test, y_test) = load_mnist(flatten=True, normalize=False)

# KNN 실행
# clf1 = KNN(x_train, y_train, x_test, y_test, k = 1)
# clf1.run()

clf2 = LogisticRegression(0.005, 1000, x_train.astype('float32')/255.0,\
                        y_train, x_test.astype('float32')/255.0, y_test)
clf2.run()

"""
k_list = list()
accuracy_list = list()
for i in range(3, 51, 2):
    knn = KNN(x_train, y_train, x_test, y_test, k = i)
    k_list.append(i)
    accuracy_list.append(knn.run())

print(k_list)
print(accuracy_list)
"""