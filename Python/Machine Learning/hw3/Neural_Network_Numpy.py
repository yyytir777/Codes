import numpy as np
import matplotlib.pyplot as plt
from collections import OrderedDict
from dataset.mnist import load_mnist


def sigmoid(z):
    return 1 / (1 + np.exp(-z))


def softmax(x):
    # x = (100, 10)
    if x.ndim == 2:
        # x = (10, 100)
        x = x.T
        # 오버플로우 방지
        x = x - np.max(x, axis=0)
        # y = (10, 100)
        y = np.exp(x) / np.sum(np.exp(x), axis=0)
        return y.T
    
    x = x - np.max(x)
    return np.exp(x) / np.sum(np.exp(x))


def cross_entropy_error(y, t):
    # 1차원일때 2차원으로 변경
    if y.ndim == 1:
        t = t.reshape(1, t.size)
        y = y.reshape(1, y.size)

    # 클래스 인덱스일때
    if t.size == y.size:
        t = t.argmax(axis=1)
    
    batch_size = y.shape[0]
    return -np.sum(np.log(y[np.arange(batch_size), t] + 1e-7)) / batch_size


class Relu:
    def __init__(self):
        self.mask = None

    def forward(self, x):
        # 0보다 작은 element의 index를 mask에 저장 (boolean)
        self.mask = (x <= 0)
        out = x.copy()
        # 0보다 작은 element는 0으로 초기화
        out[self.mask] = 0
        return out
    
    def backward(self, dout):
        # 0보다 작은 index의 기울기를 0으로 초기화
        dout[self.mask] = 0
        dx = dout
        return dx
        
class Affine:
    def __init__(self, W, b):
        self.W = W
        self.b = b
        self.x = None
        self.dW = None
        self.db = None

    def forward(self, x):
        self.x = x
        # unit 계산
        out = np.dot(x, self.W) + self.b
        return out
    
    def backward(self, dout):
        # dout = (100, 100) or (100, 10)
        # self.W = (784, 100) or (100, 100) or (100, 10)
        
        # 각 계층에 대한 dout과 self.W이므로 self.W를 전치하여 행렬곱 진행
        dx = np.dot(dout, self.W.T)
        # 가중치에 대한 gradient
        self.dW = np.dot(self.x.T, dout)
        # bias에 대한 gradient
        self.db = np.sum(dout, axis=0)

        return dx

# softmax + cross_entropy_error
class SoftmaxwithLoss:
    def __init__(self):
        self.loss = None
        self.t = None
        self.y = None

    def forward(self, x, t):
        self.t = t
        # x, self.y = (100, 10)
        self.y = softmax(x)
        # 예측값과 target값 간의 차이
        self.loss = cross_entropy_error(self.y , self.t)

        return self.loss
    
    # 
    def backward(self, dout=1):
        batch_size = self.t.shape[0]
        # 손실에 대한 기울기
        dx = (self.y - self.t) / batch_size

        return dx
    

class NeuralNetwork:
    def __init__(self, input_size, hidden_size, output_size, hidden_layer):
        self.hidden_layer = hidden_layer
        self.params = {}
        self.layers = OrderedDict()

        # momemtum variable
        self.v = None

        # adagrad variable
        self.h = None
        self.ada_lr = 0.01


        for i in range(self.hidden_layer):
            # 입력층
            if i == 0:
                self.params[f'W{i}'] = np.random.randn(input_size, hidden_size) * np.sqrt(2 / input_size)
                self.params[f'b{i}'] = np.zeros(hidden_size)
                self.layers[f'Affine{i}'] = Affine(self.params[f'W{i}'], self.params[f'b{i}'])
                self.layers[f'Relu{i}'] = Relu()

            # 은닉층
            elif 0 < i < self.hidden_layer - 1:
                self.params[f'W{i}'] = np.random.randn(hidden_size, hidden_size) * np.sqrt(2 / input_size)
                self.params[f'b{i}'] = np.zeros(hidden_size)
                self.layers[f'Affine{i}'] = Affine(self.params[f'W{i}'], self.params[f'b{i}'])
                self.layers[f'Relu{i}'] = Relu()

            # 출력층
            else:
                self.params[f'W{i}'] = np.random.randn(hidden_size, output_size) * np.sqrt(2 / input_size)
                self.params[f'b{i}'] = np.zeros(output_size)
                self.layers[f'Affine{i}'] = Affine(self.params[f'W{i}'], self.params[f'b{i}'])

        # 출력층의 마지막
        self.lastlayer = SoftmaxwithLoss()

    def predict(self, x):
        # 예측이므로 layer에 대한 순전파 진행
        for layer in self.layers.values():
            x = layer.forward(x)
        return x
    
    def loss(self, x, t):
        # cross_entropy_error 진행 -> loss 값 구함
        y = self.predict(x)
        loss = self.lastlayer.forward(y, t)
        return loss
    
    def accuracy(self, x, t):
        y = self.predict(x)
        # y값 중 최댓값을 선택(one hot coding)
        y = np.argmax(y, axis=1)
        if t.ndim != 1:
            t = np.argmax(t, axis=1)

        accuracy = np.sum(y == t) / x.shape[0]
        return accuracy
    
    def gradient(self, x, t):
        self.loss(x, t)

        # dout = (100, 10) -> 출력층에서 은닉층으로 역전파 진행
        dout = self.lastlayer.backward(1)
        layers = list(self.layers.values())
        # 역전파이므로 반대로 설정
        layers.reverse()
        for layer in layers:
            # 역전파 진행
            dout = layer.backward(dout)
            # dout = (100, 100) -> 은닉층

        # weight과 bias에 대한 gradient 저장
        gradients= {}
        for i in range(self.hidden_layer):
            gradients[f'W{i}'] = self.layers[f'Affine{i}'].dW
            gradients[f'b{i}'] = self.layers[f'Affine{i}'].db

        return gradients
    
    # optitmizer_sgd
    def sgd(self, gradients, x_batch, t_batch):
        for i in range(self.hidden_layer):
            # learning rate로 학습률 조절
            self.params[f'W{i}'] -= self.lr * gradients[f'W{i}']
            self.params[f'b{i}'] -= self.lr * gradients[f'b{i}']

        # 손실 계산
        return self.loss(x_batch, t_batch)

    # optitmizer_momentum
    def momentum(self, gradients, x_batch, t_batch):
        momentum = 0.9
        if self.v is None:
            self.v = {}
            for key, value in self.params.items():
                self.v[key] = np.zeros_like(value)
        
        for key in self.params.keys():
            # momentum이라는 물리적 저항 생성
            self.v[key] = momentum * self.v[key] - self.lr * gradients[key]
            self.params[key] += self.v[key]
        
        # 손실 계산
        return self.loss(x_batch, t_batch)

    # optitmizer_adagrad
    def adagrad(self, gradients, x_batch, t_batch):
        if self.h is None:
            self.h = {}
            for key, value in self.params.items():
                self.h[key] = np.zeros_like(value)
        
        for key in self.params.keys():
            # 각 매개변수에 대해 학습률 조절
            self.h[key] += gradients[key] ** 2
            # 분모가 0이 되는것을 방지
            self.params[key] -= self.ada_lr * gradients[key] / (np.sqrt(self.h[key]) + 1e-7)

        # 손실 계산
        return self.loss(x_batch, t_batch)

    # 학습 진행
    def learn(self, x_train, t_train, lr, epoch, batch_size):
        self.lr = lr
        self.train_loss = list()
        self.train_accuracy = list()
        self.test_accuracy = list()

        for i in range(epoch):
            # batch 진행
            batch_mask = np.random.choice(x_train.shape[0], batch_size)
            x_batch = x_train[batch_mask]
            t_batch = t_train[batch_mask]
            
            gradients = self.gradient(x_batch, t_batch)

            # 매개변수 업데이트 & 손실 return
            loss = self.adagrad(gradients, x_batch, t_batch)

            self.train_loss.append(loss)

            # 100배수마다 accuracy 출력
            if i % 100 == 0:
                tmp = self.accuracy(x_batch, t_batch)
                self.train_accuracy.append(tmp)

                print("%d번재 학습 => accuracy : %0.3f" %(i, tmp))
                print()


input_size = 784  # MNIST 이미지 크기
hidden_size = 100
output_size = 10  # 클래스 수 (0부터 9까지의 숫자)
hidden_layer = 10 # 입력층 + 은닉층 + 출력층 개수
(x_train, t_train), _ = load_mnist(flatten=True, normalize=True, one_hot_label=True)

# 초기화
network = NeuralNetwork(input_size, hidden_size, output_size, hidden_layer)

# 학습 진행
network.learn(x_train, t_train, lr=0.1, epoch=1000, batch_size=100)

# loss함수 출력
plt.plot(network.train_loss)
plt.show()