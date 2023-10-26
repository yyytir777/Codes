import numpy as np


# LogisticRegression Class
class LogisticRegression():
    def __init__(self, lr, epoch, x_train, y_train, x_test, y_test, target_class):
        self._lr = lr
        self._epoch = epoch
        self._x_train = x_train.reshape(60000, 28 * 28)
        self._x_test = x_test.reshape(10000, 28 * 28)
        self._n = 100
        self._y_train = np.zeros(shape=self._n)
        self._y_test = np.zeros(shape=self._n)
        self._target_class = target_class
        self._w = np.random.randn(len(self._x_train[0]) + 1).reshape(785,1)
        self._result = np.zeros(shape=self._n)

        # 사용할 데이터 크기로 자르기
        self._x_train = self._x_train[0:self._n,:] # -> shape : (100, 784)
        y_train = y_train[0:self._n] # -> shape : (100, )
        self._x_test = self._x_test[0:self._n,:] # -> shape : (100, 784)
        y_test = y_test[0:self._n] # -> shape : (100,)

        # y_test, y_train에서 target class만 1로 바꾸고 나머지를 0으로 치환
        # ex) target_class가 7일때, y_train, y_test의 원소가 7이면 1로, 아니면 0으로 설정
        for i in range(self._n):
            if y_train[i] == self._target_class:
                self._y_train[i] = 1
                self._y_test[i] = 1

        new_column = np.ones((self._n,1))
        self._x_train = np.hstack((new_column, self._x_train)) # -> shape : (100, 785)
        self._y_train = self._y_train.reshape(self._n, 1) # -> shape : (1,100)
        self._y_test = self._y_test.reshape(self._n, 1) # -> shape : (1,100)
        self._x_test = np.hstack((new_column, self._x_test)) # -> shape : (100, 785)

    def run(self):
        self.learn()
        self.predict()

    def sigmoid_f(self, z):
        return (1 / (1 + np.exp(z)))
        
    def cost_f(self, y, h):
        y = y.transpose()
        return -(np.dot(y, np.log(h)) + np.dot(1-y, np.log(1-h)))
    

    def gradient_descent(self, x, y, h):
        # gradient : (875, 1)이어야함
        gradient = np.dot(x.transpose(), h-y) / len(y)
        self._w = self._w - self._lr * gradient 
    
    # 반복하여 self._theta값 update
    def learn(self):
        for i in range(self._epoch):
            # self._w x self._x_train끼리 행렬곱하여 (100,1)
            x = np.dot(self._x_train, self._w) # -> (100,785) x (785,1)
            y = self._y_train # (100,1)
            
            # sigmoid(x) h : (100,1)
            h = self.sigmoid_f(x)

            # cost(h) j : (100,1)
            cost = self.cost_f(y, h)

            self.gradient_descent(self._x_train, y, h)

        # self._w (가중치)의 값이 epoch만큼 수정되어 업데이트
        # learn()에서 self._w x 


    
    # predict : 새로운 속성을 input했을때, 그 레이블에 속하는지 아닌지 판단
    def predict(self):
        # x = np.dot(self._x_test, self._w).reshape(self._n,1)
        # print(self.sigmoid_f(x))

        x = np.dot(self._x_test[0], self._w)
        h = self.sigmoid_f(x)

        print(h)
        if h >= 0.5:
            print("test[0] is 0")
        else:
            print("test[0] is not 0")
