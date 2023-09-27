import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris

# Iris 데이터셋 불러오기
iris = load_iris()

X = iris.data[:, :2] # 4 features 중 첫번째, 두번째 feature 사용  # type: ignore
y = iris.target # 각 케이스의 실제 값의 인덱스 # type: ignore 

x1_min, x1_max = X[:,0].min() - 5, X[:,0].max() + 0.5
x2_min, x2_max = X[:,0].min() - 5, X[:,0].max() + 0.5

train_data_X = []
test_data_X = []

train_target_y = []
test_target_y = []

# train data (15배수가 아닌 데이터를 train data로 설정 -> target마다 다른 색깔로 scatter)
# test data (15배수번째의 데이터를 test data로 설정)
for i in range(0, 150):
    if (i + 1) % 15 == 0:
        test_data_X.append(list(X[i]))
        test_target_y.append(y[i])
    else:
        train_data_X.append(list(X[i]))
        train_target_y.append(y[i])

train_data_X = np.array(train_data_X)
test_data_X = np.array(test_data_X)


plt.figure(figsize=(8,6))
# train data를 matplotlib에 scatter (각 target에 대해 색깔을 다르게 설정)
plt.scatter(train_data_X[:,0], train_data_X[:,1], s = 30,c = train_target_y, cmap=plt.cm.Set1, edgecolors='k')

# plt.scatter(test_data_X[:,0], test_data_X[:,1], c = 'blue', cmap=plt.cm.Set1, edgecolors='k')
plt.xlabel('Sepal length')
plt.ylabel('Sepal width')

plt.xlim(x1_min, x1_max)
plt.ylim(x2_min, x2_max)

#plt.show()


model = KNN(k=3, train_data_X, train_target_y) # KNN class 생성

#train_data를 순회하며 Calculate_distance()하고 해당 값을 리스트에 저장 -> 리스트 오름차순 정렬
for _ in range(len(train_data_X)):


#Obtain K-nearest Neighbor : 리스트에서 k개를 선택하여 target요소가 많은 것을 반환

