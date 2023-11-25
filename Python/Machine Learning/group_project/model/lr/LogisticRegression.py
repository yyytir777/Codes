import pandas as pd
import numpy as np
import pickle
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score

# 데이터 로드
twitter_data_path = 'twitter_MBTI.csv'  
encoded_data_path = 'input_data.pkl'  

twitter_data = pd.read_csv(twitter_data_path)

with open(encoded_data_path, 'rb') as file:
    encoded_data = pickle.load(file)

# MBTI 레이블을 네 가지 차원으로 분리하는 함수
def extract_dimension(label, index):
    return 1 if label[index].upper() in ['E', 'S', 'T', 'P'] else 0

# MBTI 레이블을 네 가지 차원으로 분리
twitter_data['E_I'] = twitter_data['label'].apply(lambda x: extract_dimension(x, 0))
twitter_data['S_N'] = twitter_data['label'].apply(lambda x: extract_dimension(x, 1))
twitter_data['T_F'] = twitter_data['label'].apply(lambda x: extract_dimension(x, 2))
twitter_data['P_J'] = twitter_data['label'].apply(lambda x: extract_dimension(x, 3))

# 데이터 준비
X = encoded_data
y = twitter_data[['E_I', 'S_N', 'T_F', 'P_J']]

# 데이터 스케일링
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# 각 차원별로 SVM 모델 훈련 및 평가
results_svm = {}
dimensions = ['E_I', 'S_N', 'T_F', 'P_J']

for dim in dimensions:
    # 데이터 분할
    y_dim = twitter_data[dim]
    indices = np.arange(len(X_scaled))
    test_indices = indices[indices % 5 == 0]  # 5의 배수 인덱스
    train_indices = indices[indices % 5 != 0]  # 나머지 인덱스

    X_train, X_test = X_scaled[train_indices], X_scaled[test_indices]
    y_train, y_test = y_dim.iloc[train_indices], y_dim.iloc[test_indices]

    # SVM 모델 훈련
    svm_model = SVC()
    svm_model.fit(X_train, y_train)

    # 예측
    y_pred = svm_model.predict(X_test)

    # 성능 평가
    accuracy = accuracy_score(y_test, y_pred)
    precision = precision_score(y_test, y_pred)
    recall = recall_score(y_test, y_pred)
    f1 = f1_score(y_test, y_pred)

    # 결과 저장
    results_svm[dim] = {
        'accuracy': accuracy, 
        'precision': precision, 
        'recall': recall, 
        'f1_score': f1
    }

# 결과 출력
for dim, result in results_svm.items():
    print(f"Results for {dim}:")
    print(result)
    print()