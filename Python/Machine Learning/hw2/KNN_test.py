import numpy as np

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

    def run(self):
        self.Calculate_Distance()
        self.Obtain_KNN()
        self.Obtain_Majority_Vote()

    def Calculate_Distance(self):
        print("--Calculate_Distance--")
        total_test_result = list()
        # 각 test데이터를 train데이터와 28x28개의 거리 비교


        for i in range(0,30):
            test_result = list()

            for j in range(len(self._x_train)):
                distance = np.linalg.norm(self._x_train[j] - self._x_test[i])
                test_result.append([distance, self._y_train[j]])

            test_result.sort()
            total_test_result.append(test_result)

        self._result = total_test_result
        print('result : ', total_test_result)
        print()

    def Obtain_KNN(self):
        print("--Obatian KNN--")
        y_test_list = list()
        for i in range(0,30):
            tmp = list()
            for j in range(self._k):
                tmp.append(self._result[i][j][1])
            y_test_list.append(tmp)

        self._y_test_list = y_test_list
        # print(y_test_list)
        # print()
    
    def Obtain_Majority_Vote(self):
        print("--Obtain Majority--")

        test_predict = list()
        for i in range(0,30):
            predict = max(self._y_test_list[i], key=self._y_test_list[i].count)
            test_predict.append(predict)
        
        print("predict : \t\t real : ")
        cnt = 0
        for i in range(0,30):
            print(test_predict[i], '\t\t', self._y_test[i])
            if test_predict[i] == self._y_test[i]:
                cnt += 1
        # print(test_predict)
        print(float(cnt / 30))