import numpy as np
import pickle
import tensorflow as tf
from sklearn.preprocessing import LabelEncoder
from tensorflow.keras.layers import LSTM, Embedding, Dense #ignore : 
from tensorflow.keras.models import Sequential
from tensorflow.keras.optimizers import Adam
from tensorflow.keras.callbacks import EarlyStopping


with open("Python\\Machine Learning\\group_project\\input\\input_data.pkl", "rb") as fr:
    input_data = pickle.load(fr)

with open("Python\\Machine Learning\\group_project\\input\\target_class.pkl", "rb") as fr:
    target_class_data = pickle.load(fr)

label_mapping = {
    'istj': 0, 'isfj': 1, 'infj': 2, 'intj': 3,
    'istp': 4, 'isfp': 5, 'infp': 6, 'intp': 7,
    'estp': 8, 'esfp': 9, 'enfp': 10, 'entp': 11,
    'estj': 12, 'esfj': 13, 'enfj': 14, 'entj': 15
}

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
y_train = np.array(y_train, dtype=np.float32)
y_test = np.array(y_test, dtype=np.float32)

x_train = np.reshape(x_train, (x_train.shape[0], 1, x_train.shape[1]))
x_test = np.reshape(x_test, (x_test.shape[0], 1, x_test.shape[1]))

hidden_units = 4

model = Sequential()
model.add(LSTM(hidden_units))
model.add(Dense(4, activation='sigmoid'))

optimizer = Adam(learning_rate = 0.0001)
model.compile(optimizer=optimizer, loss='binary_crossentropy', metrics=['acc'])  # Change loss function
history = model.fit(x_train, y_train, epochs=10, batch_size=50, validation_split = 0.2)

# 모델 평가
model.evaluate(x_test, y_test)

# 모델 예측
predictions = model.predict(x_test)
for i in range(len(predictions)):
    for j in range(len(predictions[i])):
        if predictions[i][j] >= 0.5:
            predictions[i][j] = 1
        else:
            predictions[i][j] = 0

print(predictions)

# 예측 결과 출력
cnt = 0
temp_sum = 0
dimension_cnt = [0, 0, 0, 0]
for i in range(test_data_size):

    print(predictions[i], target_test[i])
    temp = 0
    for j in range(4):
        if predictions[i][j] == target_test[i][j]:
            dimension_cnt[j] += 1
            temp += 1
    temp_sum += temp
    if temp == 4:
        cnt += 1

with open("rnn_predict_data.pkl", "wb") as fr:
    pickle.dump(predictions, fr)



print("cnt : %d" %cnt)
print("size : %d" %test_data_size)
print("accuracy : %0.3f" %(cnt / test_data_size))
print()
print("temp : %d" %temp_sum)
print("size : %d" %(test_data_size * 4))
print("accuracy : %0.3f" %(temp_sum / (test_data_size * 4)))
print()
for i in range(4):
    print("%d 차원 정확도 : %0.3f" %(i, (dimension_cnt[i] / test_data_size)))