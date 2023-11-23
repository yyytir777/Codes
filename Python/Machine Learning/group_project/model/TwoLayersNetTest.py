from TwoLayerNet import TwoLayerNet, Relu, Affine, SoftmaxWithLoss
import pickle
import numpy as np

with open("Python\\Machine Learning\\group_project\\input\\input_data.pkl", "rb") as fr:
    input_data = pickle.load(fr)

with open("Python\\Machine Learning\\group_project\\input\\target_class.pkl", "rb") as fr:
    target_class_data = pickle.load(fr)

x_train = list()
x_test = list()
y_train_not_vector = list()
y_test_not_vector = list()
y_train = list()
y_test = list()



# train_data : 70배수 번째가 아닌 데이터
# test_data : 70배수 번째인 데이터
for i in range(len(target_class_data)):
    if (i + 1) %  41 == 0:
        x_test.append(input_data[i])
        y_test_not_vector.append(target_class_data[i])
    else:
        x_train.append(input_data[i])
        y_train_not_vector.append(target_class_data[i])


label_mapping = {
    'ISTJ': 0, 'ISFJ': 1, 'INFJ': 2, 'INTJ': 3,
    'ISTP': 4, 'ISFP': 5, 'INFP': 6, 'INTP': 7,
    'ESTP': 8, 'ESFP': 9, 'ENFP': 10, 'ENTP': 11,
    'ESTJ': 12, 'ESFJ': 13, 'ENFJ': 14, 'ENTJ': 15
}
# mbti string으로 되어있는 리스트를 각 0 ~ 15까지의 숫자로 매핑
for i in y_test_not_vector:
    y_test.append(label_mapping[i])

for i in y_train_not_vector:
    y_train.append(label_mapping[i])


cnt = dict()
for mbti in y_test_not_vector:
    if mbti not in cnt:
        cnt[mbti] = 1
    else:
        cnt[mbti] += 1



epoch = 100
learning_rate = 0.01
net = TwoLayerNet(input_size = 1000, hidden_size = 128, output_size = 16)

for i in range(epoch):
    grad = net.gradient(x_train, y_train)

    for i in ('W1', 'b1', 'W2', 'b2'):
        net.params[i] -= learning_rate * grad[i]

predictions = net.predict(x_test)

predicted_labels = np.argmax(predictions, axis=1)
print("예측된 레이블:")
print(len(predicted_labels))

print(len(y_test))
