import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from KNN import KNN
from mpl_toolkits.mplot3d import Axes3D

# Iris 데이터셋 불러오기
iris = load_iris()

# [(꽃받침 길이, 꽃받침 너비, 꽃잎 길이, 꽃잎 너비)]
X = iris.data[:, 0:3]

print(X)