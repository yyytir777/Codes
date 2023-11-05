import numpy as np

def find_mode(arr):
    # 값과 그 빈도수를 저장할 딕셔너리
    frequency_dict = {}
    
    # 배열을 순회하며 빈도수 계산
    for num in arr:
        if num in frequency_dict:
            frequency_dict[num] += 1
        else:
            frequency_dict[num] = 1
    
    # 최빈값 찾기
    mode = max(frequency_dict, key=frequency_dict.get)
    return mode

class KNN():
    def __init__(self, x_train, y_train, x_test, y_test,k):
        self._x_train = x_train 
        self._y_train = y_train
        self._x_test = x_test  
        self._y_test = y_test 
        self.k=k
    def calculate_distance(self):
        distance_matrix = []
        for i in range(100):  # 테스트 데이터의 개수
            distances = [np.linalg.norm(self._x_test[i] - x_train_instance) for x_train_instance in self._x_train]
            sorted_indices = np.argsort(distances)
            distance_matrix.append(sorted_indices)
        return distance_matrix

    def obtain_knn(self, distance_matrix):
        knn_list = []
        for sorted_indices in distance_matrix:
            knn = [self._y_train[index] for index in sorted_indices[:self.k]]
            knn_list.append(knn)
        return knn_list

    def majority_vote(self, knn_list):
        result = []
        for knn in knn_list:
            result.append(find_mode(knn))
        return result

    def test(self, result):
        count = 0
        for i in range(100):  # 테스트 데이터의 개수
            if result[i] == self._y_test[i]:
                count += 1
        accuracy = count / 100  # 테스트 데이터의 개수로 나눔
        print("Accuracy with k =", self.k, "is:", accuracy)


    def run(self):
        result=self.majority_vote(self.obtain_knn(self.calculate_distance()))
        self.test(result)