import numpy as np

class KNN:
    def __init__(self, k, X, y):
        self.__k = k
        self.__features = X
        self.__Target = y
    
    # 거리 계산 : train_data 하나랑 test_data의 거리 계산하는 메소드
    #test_data_X, train_data_X 필요, return 값 list
    def Calculate_distance(self, X): # <- 매개변수 : test data의 속성값
        result = []

        #test data 하나와, 여러개의 train data의 거리를 계산하여 result 리스트에 거리 추가
        for train_x, train_y, train_z in self.__features:
            tmp = 0

            # numpy에서 sqrt를 반환하는 함수
            tmp = np.sqrt( (train_x - X[0])**2 + (train_y - X[1])**2 + (train_z - X[2])**2)
            result.append(tmp)

        # result와 target끼리 묶어 리스트 생성 [[result, target] .... ... ... ...]
        # 이때 result를 기준으로 정렬 => result값에 target값이 매핑됨 => result값으로 오름차순 정렬
        for i in range(len(result)):
            result[i] = [result[i], self.__Target[i]]

        result.sort()

        return result # result(이차원list) 반환


    # 가장 가까운 k개 선택
    def Obtain_KNN(self, lst): # lst : 2차원 list
        result = []
        for i in range(self.__k):
            result.append(lst[i][1]) #인덱스값 추가
        return result #result(1차원 lst) 반환
    

    # majority vote
    def Obtain_majority_vote(self, lst):
        #lst의 각 원소에 대해 lst.count()함수를 적용하여 각 원소의 등장횟수 계산 -> 큰 값을 반환
        result = max(lst, key=lst.count)
        return result #class의 index