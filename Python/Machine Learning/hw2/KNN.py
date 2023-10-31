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
        self._n = 100

    def run(self):
        # Calculate Distance
        start = time()
        # self._x_test에 대한 원소 순회
        for i in range(self._n):
            # 각 원소에 대한 train_data와의 거리 집합을 리턴하여 self._result에 저장
            self._result += [self.Calculate_Distance(self._x_test[i])]
        
        end = time()
        self._time = end - start
        
        # Obatin_KNN
        self.Obtain_KNN()

        # Obtain_Majority_Vote
        self.Obtain_Majority_Vote()
        # self.Obtain_Weighted_Majority_Vote()
        
        self.print()


    def Calculate_Distance(self, x_test_data):
        # 각 test데이터를 모든 train데이터와 28x28개의 거리 비교
        test_result = list()
        # self._x_train에 대한 원소 순회
        for j in range(len(self._x_train)):
            # 다음과 같은 방식으로 두 점 사이의 거리를 구함
            distance = np.sqrt(np.sum((self._x_train[j] - x_test_data) ** 2))
            # [거리, train_data의 target class값]
            test_result.append([distance, self._y_train[j]])
        
        # k개의 최단거리를 구하기 위해 정렬 진행
        test_result.sort()
        # 정렬된 test_result return
        return test_result


    def Obtain_KNN(self):
        # test_data에 대한 k개의 target class를 담기 위한 리스트
        y_test_list = list()
        # 데이터 크기만큼 반복
        for i in range(self._n):
            tmp = list()
            # k개의 최단거리에 해당하는 target class 선택
            for j in range(self._k):
                # tmp 임시 리스트에 추가
                tmp.append(self._result[i][j][1])
            # test_data 하나에 대한 k개의 target class 저장
            y_test_list.append(tmp)

        self._y_test_list = y_test_list


    def Obtain_Majority_Vote(self):
        test_output = list()
        for i in range(self._n):
            # self._y_test_list의 원소에서 최빈값을 선택하여 output 산출
            output = max(self._y_test_list[i], key=self._y_test_list[i].count)
            test_output.append(output)
        self._test_output = test_output
    

    def Obtain_Weighted_Majority_Vote(self):
        test_output = list()
        for i in range(self._n):
            # Euclidean Distance의 역수를 distance에 저장
            distance = list()
            for j in range(self._k):
                distance.append([1.0 / (self._result[i][j][0])])
            
            # 가중치를 거리 역수의 합으로 나누어 정규화 (0 ~ 1)
            weighted = list()
            for j in distance:
                weighted.append([j / np.sum(distance)])

            # 각 클래스에 대한 가중치를 계산 (이미 존재하는 클래스에 대해서는 덧셈 연산)
            weighted_classes = dict()
            weighted_list = list()
            for j in range(self._k):
                target_class = self._result[i][j][1]
                if target_class in weighted_list:
                    weighted_classes[target_class] += weighted[j]
                else:
                    weighted_list += target_class
                    weighted_classes[target_class] = weighted[j]

            # 가중치가 가장 큰 클래스를 선택
            output = max(weighted_classes)
            test_output.append(output)

        self._test_output = test_output


    def print(self):
        print("output : \t target class : ")
        cnt = 0
        for i in range(self._n):
            print(self._test_output[i], '\t\t', self._y_test[i])
            if self._test_output[i] == self._y_test[i]:
                cnt += 1

        accuracy = round(float(cnt / self._n), 4)
        print("fit time = ", round(float(self._time), 4))
        print("accuracy = ", accuracy)