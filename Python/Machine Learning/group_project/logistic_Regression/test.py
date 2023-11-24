import pickle
import numpy as np
from logistic_regression import LogisticRegression

with open("Python\\Machine Learning\\group_project\\input\\input_data.pkl", "rb") as fr:
    input_data = pickle.load(fr)

with open("Python\\Machine Learning\\group_project\\input\\target_class.pkl", "rb") as fr:
    target_class_data = pickle.load(fr)

binary_mapping = {
    'i' : 0, 'e' : 1,
    'n' : 0, 's' : 1,
    'f' : 0, 't' : 1,
    'p' : 0, 'j' : 1
}
# mbti string으로 되어있는 리스트에서 하나의 mbti를 4개의 binary signal로 변환(비트마스크)
target_class_data_mapped = list()
for mbti in target_class_data:
    temp = list()
    for j in mbti:
        temp.append(binary_mapping[j])
    target_class_data_mapped.append(temp)

x_train = list()
x_test = list()
target_train = list()
target_test = list()

# train_data: 5배수 번째가 아닌 데이터
# test_data: 5배수 번째인 데이터
for i in range(len(target_class_data_mapped)):
    if (i + 1) % 5 == 0:
        x_test.append(input_data[i])
        target_test.append(target_class_data_mapped[i])
    else:
        x_train.append(input_data[i])
        target_train.append(target_class_data_mapped[i])

y_test = target_test
y_train = target_train

# train data : 6249개
# test data : 1562개

test_data_size = len(x_test)
train_data_size = len(x_train)

# y_train = np.zeros(shape=(train_data_size, 4))
# y_test = np.zeros(shape=(test_data_size, 4))

# for i in range(test_data_size):
#     y_test[i][target_test[i]] = 1

# for i in range(train_data_size):
#     y_train[i][target_train[i]] = 1


x_train = np.array(x_train, dtype=np.float32)
x_test = np.array(x_test, dtype=np.float32)
y_train = np.array(y_train, dtype=np.int32)
y_test = np.array(y_test, dtype=np.int32)

model = LogisticRegression(0.0001, 200, x_train, y_train, x_test, y_test)
model.run()