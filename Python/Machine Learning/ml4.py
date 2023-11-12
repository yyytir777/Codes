import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer, ENGLISH_STOP_WORDS
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
import xgboost as xgb
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

# 데이터 불러오기
data = pd.read_csv('C:\\Users\\yyyti\\Documents\\Code\\Python\\Machine Learning\\팀플\\twitter_MBTI.csv')

# 데이터를 훈련 세트와 테스트 세트로 나누기
train_data, test_data = train_test_split(data, test_size=0.1, random_state=42)

# 레이블을 LabelEncoder를 사용하여 인코딩하기
le = LabelEncoder()
le.fit(data['label'].unique())
train_data['label'] = le.transform(train_data['label'])
test_data['label'] = le.transform(test_data['label'])

# 불용어(stop_words)에 일반적인 단어 추가하기
custom_stop_words = ['https', 'like', 'just', 'im', 'love', 'don', 'good', 'thank', 'people', 'know', 'think']

# 기본 'english' 불용어와 사용자 정의 불용어를 결합하기
stop_words = list(ENGLISH_STOP_WORDS) + custom_stop_words

# 업데이트된 불용어 리스트로 TfidfVectorizer 만들기
vectorizer = TfidfVectorizer(stop_words=stop_words)

# 텍스트 데이터에 대해 fit 및 transform하기
X_train = vectorizer.fit_transform(train_data['text'])
X_test = vectorizer.transform(test_data['text'])

# XGBoost 모델 초기화
model = xgb.XGBClassifier(learning_rate=0.1, n_estimators=200, max_depth=7)

# 모델 훈련
model.fit(X_train, train_data['label'])

# 예측
y_pred = model.predict(X_test)

# 정확도 평가
accuracy = accuracy_score(test_data['label'], y_pred)
print(f'정확도: {accuracy:.2f}')

# 분류 보고서 출력
class_names = le.classes_
report = classification_report(test_data['label'], y_pred, target_names=class_names)
print("분류 보고서:\n", report)