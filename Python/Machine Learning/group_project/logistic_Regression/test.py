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

# train_data: 70배수 번째가 아닌 데이터
# test_data: 70배수 번째인 데이터
for i in range(len(target_class_data)):
    if (i + 1) % 41 == 0:
        x_test.append(input_data[i])
        y_test_not_vector.append(target_class_data[i])
    else:
        x_train.append(input_data[i])
        y_train_not_vector.append(target_class_data[i])

label_mapping = {
    'istj': 0, 'isfj': 1, 'infj': 2, 'intj': 3,
    'istp': 4, 'isfp': 5, 'infp': 6, 'intp': 7,
    'estp': 8, 'esfp': 9, 'enfp': 10, 'entp': 11,
       
    'estj': 12, 'esfj': 13, 'enfj': 14, 'entj': 15
}
y_test = y_test_not_vector
# mbti string으로 되어있는 리스트를 각 0 ~ 15까지의 숫자로 매핑
# for i in y_test_not_vector:
#     y_test.append(label_mapping[i])

for i in y_train_not_vector:
    y_train.append(label_mapping[i])

cnt = dict()
for i in y_test:
    if i not in cnt:
        cnt[i] = 1
    else:
        cnt[i] += 1

print(cnt)