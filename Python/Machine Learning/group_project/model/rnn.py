import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
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

# mbti string으로 되어있는 리스트를 각 0 ~ 15까지의 숫자로 매핑
for i in y_test_not_vector:
    y_test.append(label_mapping[i])

for i in y_train_not_vector:
    y_train.append(label_mapping[i])

# 데이터 크기 조정
x_train = x_train[:500]
x_test = x_test[:500]
y_train = y_train[:500]
y_test = y_test[:500]

# 텐서로 변환
x_train = torch.tensor(x_train, dtype=torch.float32)
x_test = torch.tensor(x_test, dtype=torch.float32)
y_train = torch.tensor(y_train, dtype=torch.long)  # 정수로 된 클래스이므로 dtype을 long으로 설정
y_test = torch.tensor(y_test, dtype=torch.long)

# RNN 모델 정의
class SimpleRNN(nn.Module):
    def __init__(self, input_size, hidden_size, output_size):
        super(SimpleRNN, self).__init__()
        self.rnn = nn.RNN(input_size, hidden_size, batch_first=True)
        self.fc = nn.Linear(hidden_size, output_size)

    def forward(self, x):
        out, _ = self.rnn(x)
        out = self.fc(out[-1, :])  # RNN의 마지막 시간 단계의 출력을 사용
        return self.fc(out)

# 모델 초기화
input_size = 500  # 입력 특성의 개수
hidden_size = 10  # 은닉 상태의 크기
output_size = 16  # 출력 클래스의 개수

model = SimpleRNN(input_size, hidden_size, output_size)

# 손실 함수와 옵티마이저 정의
criterion = nn.CrossEntropyLoss()
optimizer = optim.SGD(model.parameters(), lr=0.1)

# 학습
num_epochs = 100
for epoch in range(num_epochs):
    # Forward pass
    outputs = model(x_train)

    # 손실 계산
    loss = criterion(outputs, y_train)

    # Backward pass 및 최적화
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    if (epoch + 1) % 10 == 0:
        print(f'Epoch [{epoch+1}/{num_epochs}], Loss: {loss.item():.4f}')

# 모델 평가
model.eval()
with torch.no_grad():
    output = model(x_test)
    probabilities = F.softmax(output, dim=1)
    _, predicted_classes = torch.max(probabilities, 1)
    
    # 정확도 계산
    accuracy = torch.sum(predicted_classes == y_test).item() / len(y_test)
    print(f'Predicted Classes: {predicted_classes.tolist()}')
    print(f'Actual Classes: {y_test.tolist()}')
    print(f'Accuracy: {accuracy * 100:.2f}%')
