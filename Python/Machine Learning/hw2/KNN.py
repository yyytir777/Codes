import numpy as np
from time import time

# KNN class 
class KNN():
    def __init__(self, x_train, y_train, x_test, y_test, k):
        self._x_train = x_train 
        self._y_train = y_train
        self._x_test = x_test  
        self._y_test = y_test
        self._k = k
        self._result = list()
        self._y_test_list = list()
        self._test_predict = list()
        self._n= 100

    def run(self):
        # Calculate Distance
        start = time()
        for i in range(self._n):
            self._result += [self.Calculate_Distance(self._x_test[i])]
        
        mid = time()
        # Obatin_KNN
        self.Obtain_KNN()

        # Obtain_Majority_Vote
        self.Obtain_Majority_Vote()

        end = time()

        print("predict : \t calculate result : ")
        cnt = 0
        for i in range(self._n):
            print(self._test_predict[i], '\t\t', self._y_test[i])
            if self._test_predict[i] == self._y_test[i]:
                cnt += 1
        
        print('calculate distance : %0.3f' %(mid - start))
        print('etc : %0.3f' %(end - mid))
        print("accuracy = ", round(float(cnt / self._n), 4))


    def Calculate_Distance(self, x_test_data):
        # 각 test데이터를 train데이터와 28x28개의 거리 비교
        test_result = list()
        for j in range(len(self._x_train)):
            distance = np.linalg.norm(self._x_train[j] - x_test_data)
            test_result.append([distance, self._y_train[j]])

        test_result.sort()
        return test_result

    def Obtain_KNN(self):
        print("--Obatian KNN--")
        y_test_list = list()
        for i in range(self._n):
            tmp = list()
            for j in range(self._k):
                tmp.append(self._result[i][j][1])
            y_test_list.append(tmp)

        self._y_test_list = y_test_list

    def Obtain_Majority_Vote(self):
        print("--Obtain Majority--")

        test_predict = list()
        for i in range(self._n):
            predict = max(self._y_test_list[i], key=self._y_test_list[i].count)
            test_predict.append(predict)

        self._test_predict = test_predict