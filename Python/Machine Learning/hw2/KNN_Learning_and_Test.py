# Importing necessary libraries
import sys, os
sys.path.append(os.pardir)
import numpy as np
from dataset.mnist import load_mnist

from KNN import KNN


#load data
(x_train, y_train), (x_test, y_test) = load_mnist(flatten=True, normalize=False)

# KNN 실행
clf1 = KNN(x_train, y_train, x_test, y_test, k = 15)
clf1.run()

# x_train, x_test -> x_train/255, x_test/255와 같이 정규화를
# 하냐 안하느냐에 따라 달라지므로 이를 확인할것.

# for i in range(1, 30, 2):
#     test_model = KNN(x_train, y_train, x_test, y_test, k = i)
#     test_model.run()
