import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from KNN import KNN

# Iris 데이터셋 불러오기
iris = load_iris()

# [(꽃받침 길이, 꽃받침 너비, 꽃잎 길이, 꽃잎 너비)]
X = iris.data[:, 1:3] # 4 features 중 첫번째, 두번째 feature 사용  # type: ignore
y = iris.target # 각 케이스의 실제 값의 인덱스 # type: ignore 
y_name = iris.target_names #type: ignore ['setosa', 'versicolor', virginica']

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

#scatter위해 list를 np.array로 변경
train_data_X = np.array(train_data_X)
test_data_X = np.array(test_data_X)

x1_min, x1_max = X[:,0].min() - 5, X[:,0].max() + 0.5
x2_min, x2_max = X[:,0].min() - 5, X[:,0].max() + 0.5

plt.figure(figsize=(8,6))
# train data를 matplotlib에 scatter (각 target에 대해 색깔을 다르게 설정)
plt.scatter(train_data_X[:,0], train_data_X[:,1], c = train_target_y, cmap=plt.cm.Set1, edgecolors='k') # type: ignore

# test data를 matplotlib에 scatter
plt.scatter(test_data_X[:,0], test_data_X[:,1], edgecolors='k') # type: ignore

plt.xlabel('Sepal length')
plt.ylabel('Sepal width')

plt.xlim(x1_min, x1_max)
plt.ylim(x2_min, x2_max)

plt.show()

train_data_X = list(train_data_X)
train_target_y = list(train_target_y)

model = KNN(3, train_data_X, train_target_y) # KNN class 생성 <-- train할 데이터 넣어줌

#test 값을 넣어줄 때마다 output 계산해야함 & 계산된 output과 실제 output 비교 using k = 3, 5, 7

i = 0
# 10개의 test data를 순회
for test_data in test_data_X:
    # 각각의 train_data와의 거리 계산을 distance_list에 append
    distnace_list = model.Calculate_distance(test_data)

    # train data와의 거리를 오름차순으로 정렬하여 k개의 최단거리의 target 인덱스 반환
    target_list = model.Obtain_KNN(distnace_list)

    # k개의 최단거리 target 인덱스 중, 가장 빈도수가 많은 인덱스를 반환
    predict_target_idx = model.Obtain_majority_vote(target_list)

    print('Test Data Index : %d,     Computed class : %s,     True class : %s' %(i, y_name[predict_target_idx], y_name[test_target_y[i]]))
    i += 1