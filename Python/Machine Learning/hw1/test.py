import matplotlib.pyplot as plt
from sklearn.datasets import load_iris

iris = load_iris()

# 꽃받침 길이, 꽃받침 너비, 꽃잎 길이, 꽃잎 너비
# sepal length', 'sepal width', 'petal length', 'petal width
X = iris.data[:,[2,3]] # 0번째, 2번째 feature 사용
y = iris.target
y_name = iris.target_names

print(X)
x1_min, x1_max = X[:,0].min() - 0.5, X[:,0].max() + 0.5
x2_min, x2_max = X[:,0].min() - 5, X[:,0].max() + 5

plt.figure(figsize=(8,6))
plt.scatter(X[:,0], X[:,1], c = y, cmap=plt.cm.Set1, edgecolors='k')
plt.xlabel('petal length')
plt.ylabel('petal width')

plt.xlim(x1_min, x1_max)
plt.ylim(x2_min, x2_max)

plt.show()