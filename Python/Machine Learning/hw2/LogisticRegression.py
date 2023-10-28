import numpy as np


# LogisticRegression Class
class LogisticRegression():
    def __init__(self, lr, epoch, x_train, y_train, x_test, y_test):
        self._lr = lr
        self._epoch = epoch
        self._x_train = x_train.reshape(60000, 28 * 28)
        self._x_test = x_test.reshape(10000, 28 * 28)
        self._n = 1000
        self._y_train = np.zeros(shape=(self._n, 10))
        self._y_test = np.zeros(shape=(self._n, 10))
        self._w = np.zeros((len(self._x_train[0]) + 1)).reshape(785,1)
        self._result = np.ones(shape=(self._n, 10))
        self._x = list()
        self._y = list()
        self._y_test_for_compare = y_test

        # 사용할 데이터 크기로 자르기
        self._x_train = self._x_train[0:self._n,:] # -> shape : (100, 784)
        self._x_test = self._x_test[0:self._n,:] # -> shape : (100, 784)
        y_train = y_train[0:self._n] # -> shape : (100,)
        y_test = y_test[0:self._n] # -> shape : (100,)

        # y_test, y_train에서 target class만 1로 바꾸고 나머지를 0으로 치환
        # ex) target_class가 7일때, y_train, y_test의 원소가 7이면 1로, 아니면 0으로 설정
        for i in range(self._n):
            self._y_train[i][y_train[i]] = 1
            self._y_test[i][y_test[i]] = 1

        new_column = np.ones((self._n,1))
        self._x_train = np.hstack((new_column, self._x_train)) # -> shape : (100, 785)
        self._x_test = np.hstack((new_column, self._x_test)) # -> shape : (100, 785)
        self._y_train = self._y_train.reshape(self._n, 10) # -> shape : (100,10)
        self._y_test = self._y_test.reshape(self._n, 10) # -> shape : (100,10)

    def getCostList(self):
        return self._epoch, self._cost_list
    
    def sigmoid_f(self, z):
        return 1 / (1 + np.exp(-z))
        
    def cost_f(self, y, h):
        cost = -np.sum(y * np.log(h) + (1 - y) * np.log(1 - h), axis=0) / self._n
        return cost

    def gradient_descent(self, x, y, h):
        # size : (785, 10)
        return np.dot(x.T, h-y) / self._n
    

    # epoch번 반복하여 self._w update
    def learn(self):
        self._cost_list = np.empty((0,10))
        for i in range(self._epoch):

            x = np.dot(self._x_train, self._w) # -> (100,785) x (785,1) = (100,1)
            print("w : ", self._w.shape)
            y = self._y_train # (100,10)


            # sigmoid(x) h : (100,1)
            h = self.sigmoid_f(x)

            # cost(h) cost : (10,)
            cost = self.cost_f(y, h)
            cost = np.array(cost).reshape(1,10)
            print("cost : ", cost.shape)
            self._cost_list = np.concatenate([self._cost_list, cost])

            print("epoch : %d" %(i))
            print("cost : ", cost)

            # gradient : (785,1)
            gradient = self.gradient_descent(self._x_train, y, h)
            self._w = self._w - self._lr * gradient

    # predict : 새로운 속성을 input했을때, 그 레이블에 속하는지 아닌지 판단
    def predict(self):

        x = np.dot(self._x_test, self._w) # (100, 785) x (785, 10) = (100, 10)
        h = self.sigmoid_f(x)

        row_max_list = list()
        for i in range(self._n):
            # h를 각 데이터별로 나눔
            row = h[i,:]
            # 해당 데이터에서 0-9까지 target class에 대한 sigmoid값의 최대값의 인덱스 반환
            target_class = np.argmax(row)
            # 반환한 인덱스 값은 predict한 target class로 사용
            row_max_list.append([target_class, np.argmax(row)])
        
        cnt = 0
        for i in range(self._n):
            print("test[%d] is %d" %(i, row_max_list[i][1]),\
                    "and real value is %d" %(self._y_test_for_compare[i]))
            if row_max_list[i][1] == self._y_test_for_compare[i]:
                cnt += 1
        print("accuracy : %0.3f" %(cnt / self._n))

    def run(self):
        self.learn()
        self.predict()