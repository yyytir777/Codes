import torch
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt
from dataset.mnist import load_mnist

def create_model(input_size, hidden_sizes, output_size, count_layer):
    layers = []
    activations = []

    for i in range(count_layer):
        if i == 0:
            # 입력층
            layers.append(nn.Linear(input_size, hidden_sizes))
            activations.append(nn.ReLU())

        elif 0 < i < count_layer - 1:
            # 은닉층
            layers.append(nn.Linear(hidden_sizes, hidden_sizes))
            activations.append(nn.ReLU())

        else:
            # 출력층
            layers.append(nn.Linear(hidden_sizes, output_size))

    return nn.Sequential(*layers, *activations)

# 모델 생성 및 초기화
input_size = 784
hidden_sizes = 100
output_size = 10
count_layer = 10
epochs = 1000

model = create_model(input_size, hidden_sizes, output_size, count_layer)

# 데이터 생성 및 손실 함수
(x_train, t_train), _ = load_mnist(flatten=True, normalize=True, one_hot_label=False)

# 데이터를 PyTorch Tensor로 변환
x_train = torch.tensor(x_train[:5000], dtype=torch.float32)
t_train = torch.tensor(t_train[:5000], dtype=torch.long)

criterion = nn.CrossEntropyLoss()
optimizer = optim.Adagrad(model.parameters(), lr=0.001)

# 모델 학습
loss_list = list()
for epoch in range(epochs):
    outputs = model(x_train)
    loss = criterion(outputs, t_train)

    # Backpropagation
    optimizer.zero_grad()
    loss.backward()

    # Optitmizer
    optimizer.step()

    loss_list.append(loss.item())

    if (epoch + 1) % 10 == 0:
        y_train = torch.argmax(outputs, dim=1)
        correct = (t_train == y_train).sum().item()
        accuracy = correct / len(t_train)
        print("%d번재 학습 => accuracy : %0.3f" %(epoch + 1, accuracy))

plt.plot(loss_list)
plt.show()