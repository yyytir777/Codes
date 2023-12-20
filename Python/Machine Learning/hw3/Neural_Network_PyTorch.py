import torch
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt
from dataset.mnist import load_mnist

def create_model(input_size, hidden_sizes, output_size, hidden_layer):
    layers = []
    activations = []

    for i in range(hidden_layer):
        if i == 0:
            # 첫 번째 은닉층
            layers.append(nn.Linear(input_size, hidden_sizes))
            activations.append(nn.ReLU())

        elif 0 < i < hidden_layer - 1:
            # 중간 은닉층들
            layers.append(nn.Linear(hidden_sizes, hidden_sizes))
            activations.append(nn.ReLU())

        else:
            # 출력층
            layers.append(nn.Linear(hidden_sizes, output_size))

    return nn.Sequential(*layers, *activations)

# 모델 생성 및 초기화
input_size = 784
hidden_sizes = 100  # 은닉층의 뉴런 수를 리스트로 표현, 여기서는 10개의 은닉층이 각각 100개의 뉴런을 가짐
output_size = 10
hidden_layer = 10
model = create_model(input_size, hidden_sizes, output_size, hidden_layer)

# 데이터 생성 및 손실 함수, 최적화 기법 정의
(x_train, t_train), _ = load_mnist(flatten=True, normalize=True, one_hot_label=False)

# 데이터를 PyTorch Tensor로 변환
x_train = torch.tensor(x_train[:5000], dtype=torch.float32)
t_train = torch.tensor(t_train[:5000], dtype=torch.long)  # CrossEntropyLoss를 사용하므로 레이블은 long 타입이어야 함

criterion = nn.CrossEntropyLoss()
optimizer = optim.Adagrad(model.parameters(), lr=0.01)

# 모델 학습
epochs = 1000
loss_list = list()
for epoch in range(epochs):
    outputs = model(x_train)
    loss = criterion(outputs, t_train)

    # Backward Pass 및 최적화
    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    loss_list.append(loss.item())

    if (epoch + 1) % 10 == 0:
        y_train = torch.argmax(outputs, dim=1)
        correct = (t_train == y_train).sum().item()
        accuracy = correct / len(t_train)
        print(f'Epoch [{epoch+1}/{epochs}], Accuracy: {accuracy :.4f}')

plt.plot(loss_list)
plt.show()