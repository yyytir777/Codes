import matplotlib.pyplot as plt
from sklearn.datasets import load_iris

iris = load_iris()

X = iris.data[:,1:3]
y = iris.target
y_name = iris.target_names

print(X)
# x1_min, x1_max = X[:,0].min() - 0.5, X[:,0].max() + 0.5
# x2_min, x2_max = X[:,0].min() - 0.5, X[:,0].max() + 0.5

# plt.figure(figsize=(8,6))
# plt.scatter(X[:,0], X[:,1], c = y, cmap=plt.cm.Set1, edgecolors='k')
# plt.xlabel('Sepal length')
# plt.ylabel('Sepal width')

# plt.xlim(x1_min, x1_max)
# plt.ylim(x2_min, x2_max)

# plt.show()