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

clf2 = LogisticRegression(0.0001, 100, x_train.astype('float32'),\
                        y_train, x_test.astype('float32'), y_test)
clf2.run()

epoch, cost_list = clf2.getCostList()
x = [i for i in range(epoch)]

for i in range(10):
    plt.plot(x, cost_list[:,i], label=f'Epoch {i + 1}')

plt.xlabel('Epoch')
plt.ylabel('Cost')
plt.show()