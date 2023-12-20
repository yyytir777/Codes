import numpy as np
import matplotlib.pyplot as plt
from collections import OrderedDict
from dataset.mnist import load_mnist


def sigmoid(z):
    return 1 / (1 + np.exp(-z))


def softmax(x):
    if x.ndim == 2:
        x = x.T
        x = x - np.max(x, axis=0)
        y = np.exp(x) / np.sum(np.exp(x), axis=0)
        return y.T
    
    x = x - np.max(x)
    return np.exp(x) / np.sum(np.exp(x))


def cross_entropy_error(y, t):
    if y.ndim == 1:
        t = t.reshape(1, t.size)
        y = y.reshape(1, y.size)

    if t.size == y.size:
        t = t.argmax(axis=1)
    
    batch_size = y.shape[0]
    return -np.sum(np.log(y[np.arange(batch_size), t] + 1e-7)) / batch_size


def numerical_gradient(f, x):
    h = 1e-4
    grad = np.zeros_like(x)

    for idx in range(x.size):
        tmp_val = x[idx]
        x[idx] = tmp_val + h
        fxh1 = f(x)

        x[idx] = tmp_val - h
        fxh2 = f(x)

        grad[idx] = (fxh1 - fxh2) / 2 * h
        x[idx] = tmp_val

    return grad

class Relu:
    def __init__(self):
        self.mask = None

    def forward(self, x):
        self.mask = (x <= 0)
        out = x.copy()
        out[self.mask] = 0
        return out
    
    def backward(self, dout):
        dout[self.mask] = 0
        dx = dout
        return dx
    
class Sigmoid:
    def __init__(self):
        self.y = None

    def forward(self, x):
        y = sigmoid(x)
        self.y = y
        return y

    def backward(self, dout):
        dx = dout * self.y * (1 - self.y)
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
        out = np.dot(x, self.W) + self.b
        return out
    
    def backward(self, dout):
        dx = np.matmul(dout, self.W.T)
        self.dW = np.matmul(self.x.T, dout)
        self.db = np.sum(dout, axis=0)

        return dx

class SoftmaxwithLoss:
    def __init__(self):
        self.loss = None
        self.t = None
        self.y = None

    def forward(self, x, t):
        self.t = t
        self.y = softmax(x)
        self.loss = cross_entropy_error(self.y , self.t)

        return self.loss
    
    def backward(self, dout=1):
        batch_size = self.t.shape[0]
        dx = (self.y - self.t) / batch_size

        return dx
    

class TwoLayerNet:
    def __init__(self, input_size, hidden_size, output_size, weight_init_std=0.01):
        # 2층 신경망 -> 수정 필요
        self.params = {}
        self.params['W1'] = weight_init_std * np.random.randn(input_size, hidden_size)
        self.params['W2'] = weight_init_std * np.random.randn(hidden_size, output_size)
        self.params['b1'] = np.zeros(hidden_size)
        self.params['b2'] = np.zeros(output_size)
    
        self.layers = OrderedDict()
        self.layers['Affine1'] = Affine(self.params['W1'], self.params['b1'])
        self.layers['Relu1'] = Relu()
        self.layers['Affine2'] = Affine(self.params['W2'], self.params['b2'])
        self.lastlayer = SoftmaxwithLoss()

    def predict(self, x):
        for layer in self.layers.values():
            x = layer.forward(x)
        return x
    
    def loss(self, x, t):
        y = self.predict(x)
        loss = self.lastlayer.forward(y, t)
        return loss
    
    def accuracy(self, x, t):
        y = self.predict(x)
        y = np.argmax(y, axis=1)
        if t.ndim != 1:
            t = np.argmax(t, axis=1)

        accuracy = np.sum(y == t) / x.shape[0]
        return accuracy
    
    def gradient(self, x, t):
        self.loss(x, t)

        dout = 1
        dout = self.lastlayer.backward(dout)

        layers = list(self.layers.values())
        layers.reverse()
        for layer in layers:
            dout = layer.backward(dout)

        grads = {}
        grads['W1'] = self.layers['Affine1'].dW
        grads['b1'] = self.layers['Affine1'].db
        grads['W2'] = self.layers['Affine2'].dW
        grads['b2'] = self.layers['Affine2'].db

        return grads
    
    def numerical_gradient(self, x, t):
        loss_W = lambda W: self.loss(x, t)

        grads = {}
        grads['W1'] = numerical_gradient(loss_W, self.params['W1'])
        grads['W2'] = numerical_gradient(loss_W, self.params['W2'])
        grads['b1'] = numerical_gradient(loss_W, self.params['b1'])
        grads['b2'] = numerical_gradient(loss_W, self.params['b2'])

        return grads
    
    def sgd(self, grads, x_batch, t_batch):
        for key in ('W1', 'b1', 'W2', 'b2'):
            self.params[key] -= self.lr * grads[key]

        return self.loss(x_batch, t_batch)

    def learn(self, x_train, t_train, lr, epoch, batch_size):
        self.lr = lr
        self.train_loss = list()
        self.train_accuracy = list()
        self.test_accuracy = list()

        for i in range(epoch):
            batch_mask = np.random.choice(x_train.shape[0], batch_size)
            x_batch = x_train[batch_mask]
            t_batch = t_train[batch_mask]
            
            grads = self.gradient(x_batch, t_batch)

            loss = self.sgd(grads, x_batch, t_batch)

            self.train_loss.append(loss)

            if i % 10 == 0:
                tmp1 = self.accuracy(x_batch, t_batch)
                self.train_accuracy.append(tmp1)

                print("%d번재 학습 => accuracy : %0.3f" %(i, tmp1))
                print()


# 학습 데이터 및 타겟 데이터를 정의
input_size = 784  # MNIST 이미지 크기
hidden_size = 100
output_size = 10  # 클래스 수 (0부터 9까지의 숫자)
(x_train, t_train), _ = load_mnist(flatten=True, normalize=True, one_hot_label=True)

# 네트워크 생성 및 초기화
network = TwoLayerNet(input_size, hidden_size, output_size)

# 학습 진행
network.learn(x_train, t_train, lr=0.1, epoch=500, batch_size=1000)

plt.plot(network.train_loss)
plt.show()