import numpy as np

class KNN:
    def __init__(self, k, X, y):
        self.__k = k
        self.__features = X
        self.__Target = y
    
    # 거리 계산 : train_data 하나랑 test_data의 거리 계산하는 메소드
    #test_data_X, train_data_X 필요, return 값 list
    def Calculate_distance(self, X): # <- 매개변수 (test_data, train_data의 index값)
        result = []

        for train_x, train_y in self.__features:
            tmp = 0
            tmp = np.sqrt( (train_x - X[0])**2 + (train_y - X[1])**2 )
            result.append(tmp)

        # result와 target끼리 묶어 리스트 생성 [[result, target] .... ... ... ...]
        # 이때 result를 기준으로 정렬 => result값에 target값이 매핑됨
        # result 반환
        for i in range(len(result)):
            result[i] = [result[i], self.__Target[i]]

        result.sort()

        return result # 이차원list 반환


    # 가장 가까운 k개 선택
    def Obtain_KNN(self, lst): # lst : 2차원 list
        result = []
        for i in range(self.__k):
            result.append(lst[i][1]) #인덱스값 추가
        return result
    

    # majority vote (return value from 0 to 1)
    def Obtain_majority_vote(self,):
        return 3
