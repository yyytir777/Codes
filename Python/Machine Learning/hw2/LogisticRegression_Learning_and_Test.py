# Importing necessary libraries
import sys, os
sys.path.append(os.pardir)
import numpy as np
from dataset.mnist import load_mnist

from LogisticRegression import LogisticRegression

#load data
(x_train, y_train), (x_test, y_test) = load_mnist(flatten=True, normalize=False)

# Logistic Regression 실행
clf2 = LogisticRegression(0.00001, 200, x_train.astype('float32'), y_train, x_test.astype('float32'), y_test)
clf2.run()