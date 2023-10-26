import numpy as np
from sklearn.metrics import roc_auc_score

# 하나의 class만 수행 (0 ~ 9) 10개의 인스턴스를 비교하여 가장 큰 class를 predict 값으로 선택 예정

class LogisticRegression():
    def __init__(self, lr, epoch, train_data, valid_data):
        self._lr = lr
        self._epoch = epoch
        self._train_file_path = train_data
        self._valid_file_path = valid_data
        self._valid_loss_list = []

    def _init_vectors(self):
        self.w = np.random.randn(self.feature_max_index+1)
        self.train_x_data = np.zeros((len(self._train_data), self.feature_max_index+1))
        self.train_y_data = np.zeros((len(self._train_data)))
        self.valid_x_data = np.zeros((len(self._valid_data), self.feature_max_index+1))
        self.valid_y_data = np.zeros((len(self._valid_data)))

    def train(self):
        for epoch in range(self._epoch):
            
            # train data & valid data (test data)의 sigmod값 
            hypothesis = self.sigmoid(self.train_x_data)
            valid_hypothesis = self.sigmoid(self.valid_x_data)

            # train data & valid data의 cost값
            loss = self.log_likelihood(self.train_y_data, hypothesis)
            valid_loss = self.log_likelihood(self.valid_y_data, valid_hypothesis)

            # self._print_learning_info(epoch=epoch, train_loss=loss, valid_loss=valid_loss, train_auc=roc_auc, valid_auc=valid_roc_auc)

            # descent gradient 수행 (train_x_data : (100, 785), train_y_data : (100, 1), hypothesis : (100,1))
            gradient = self.gradient(self.train_x_data, self.train_y_data, hypothesis)
            # self.w : (1,785) -> gradient : (1,785)여야함
            self.w = self.w - self._lr * gradient

    def sigmoid(self, x):
        return 1 / (1 + np.exp(-np.dot(x, self.w)))

    def log_likelihood(self, y, hypothesis):
        # y : (100, 1), hypothesis : (100,1)
        return -(np.dot(y, np.log(hypothesis)) + np.dot(1-y, np.log(1-hypothesis)))

    def gradient(self, x, y, hypothesis):
        n = len(y)
        # gradient : (875, 1)
        gradient = np.dot(x.transpose(), hypothesis-y) / n
        return gradient

    def _print_learning_info(self, epoch, train_loss, valid_loss, train_auc, valid_auc):
        print("epoch:", epoch, "||", "train_loss:", train_loss, "||", "valid_loss:", valid_loss,
              "||", "Train AUC:", train_auc, "||", "Test AUC:", valid_auc)

    def print_results(self):
        print(self.w)


if __name__ == "__main__":
    lr = LogisticRegression(lr=0.05,
                            epoch=1000,
                            train_data='../../dataset/train.txt',
                            valid_data='../../dataset/test.txt')
    lr.train()
    lr.print_results()