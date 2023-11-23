import pandas as pd
from nltk.tokenize import WordPunctTokenizer
import nltk
from nltk.stem import WordNetLemmatizer
from nltk.corpus import stopwords

tokenizer = WordPunctTokenizer() # 토큰화를 할 때 사용할 라이브러리 함수이다.
df = pd.read_csv('C:\\Users\\yyyti\\Documents\\Code\\Python\\Machine Learning\\팀플\\twitter_MBTI.csv', encoding='iso-8859-1') # df가 우리가 사용할 트위터 엠비티아이 정보 데이터프레임이다.

# 표제어 추출을 위해 필요한 것들이다.

nltk.download('wordnet')


lemmatizer = WordNetLemmatizer()

# 불용어 처리를 위한 라이브러리들이다.

nltk.download('stopwords')

stop_words = set(stopwords.words('english'))

df['text'] = df['text'].fillna('')
# 0단계 : 데이터프레임에서 'text' 행만 따로 떼와서 리스트를 만든다.
input_words_list = df['text']

# 1단계 : 각 데이터를 띄어쓰기 단위로 분리한다.
first_words_list = []
for words in input_words_list:
    # 이 사이에 이번 단계의 핵심을 넣는다.
    first_words = words.split(' ')
    # 이 사이에 이번 단계의 핵심을 넣는다.
    first_words_list.append(first_words)


# 2단계 : 각 데이터의 중간에 있는 |들을 제거한다. (띄어쓰기로는 구분이 안되는 이상한 기호)
second_words_list = []
for words in first_words_list:
    # 이 사이에 이번 단계의 핵심을 넣는다.
    second_words = []
    for word in words:
        subword = word.split('|')
        second_words += subword
    # 이 사이에 이번 단계의 핵심을 넣는다.
    second_words_list.append(second_words)


# 3단계 : 트위터 태그 및 하이퍼 링크 제거 (쓸데없는 것들 다 제거)
third_words_list = []
for words in second_words_list:
    # 이 사이에 이번 단계의 핵심을 넣는다.
    third_words = []
    for word in words:
        # @이 들어있는 문자열 다 제거(트위터 태그 다 지운다. )
        if ('@' in word):
            pass
        # @이 없을 경우 https://가 들어있는 것 다 제거(url 다 지운다.)
        elif ('https://' in word):
            pass
        # 그런 다음 나머지만 남긴다.
        else:
            third_words.append(word)
    # 이 사이에 이번 단계의 핵심을 넣는다.
    third_words_list.append(third_words)


# 4단계 다시 문자열로 합친 후 단어 토큰화를 수행한다.
fourth_words_list = []
for words in third_words_list:
    # 이 사이에 이번 단계의 핵심을 넣는다.
    fourth_words = []
    string = ''
    for word in words:
        if (word != ''):
            string += word + ' '
    fourth_words += tokenizer.tokenize(string)
    # 이 사이에 이번 단계의 핵심을 넣는다.
    fourth_words_list.append(fourth_words)


# 5단계 토큰화된 것들을 정제한다.
# 모든 대문자를 소문자로 바꾼다.

fifth_words_list = []
for words in fourth_words_list:
    # 이 사이에 이번 단계의 핵심을 넣는다.
    fifth_words = []
    for word in words:
        fifth_words.append(word.lower())
    # 이 사이에 이번 단계의 핵심을 넣는다.
    fifth_words_list.append(fifth_words)


# 6단계 토큰화된 것들을 정제한다.
# 길이가 짧은 문자열들을 삭제한다. (길이 < 3 인 단어 삭제)

sixth_words_list = []
for words in fifth_words_list:
    # 이 사이에 이번 단계의 핵심을 넣는다.
    sixth_words = []
    for word in words:
        #길이가 1~2인 단어들을 삭제
        if (len(word) > 2):
            sixth_words.append(word)
    # 이 사이에 이번 단계의 핵심을 넣는다.
    sixth_words_list.append(sixth_words)


# 7단계 토큰화된 것들을 정제한다.
# WordLemmatizer를 이용해서 기본형으로 단어를 다 바꾼다. 이를 통해 단어수를 줄일 수 있다.

seventh_words_list = []
for words in sixth_words_list:
    # 이 사이에 이번 단계의 핵심을 넣는다.
    seventh_words = []
    for word in words:
        seventh_words.append(lemmatizer.lemmatize(word))
    # 이 사이에 이번 단계의 핵심을 넣는다.
    seventh_words_list.append(seventh_words)


# 8단계 단어 중 영어단어가 아닌 것(특수 문자 등)을 제거한다.

eighth_words_list = []
for words in seventh_words_list:
    # 이 사이에 이번 단계의 핵심을 넣는다.
    eighth_words = []
    for word in words:
        if (word.isalnum()):
            eighth_words.append(word)
    # 이 사이에 이번 단계의 핵심을 넣는다.
    eighth_words_list.append(eighth_words)


# 9단계 NLTK 이용해서 불용어를 제거한다.

ninth_words_list = []
for words in eighth_words_list:
    # 이 사이에 이번 단계의 핵심을 넣는다.
    ninth_words = []
    for word in words:
        if (word not in stop_words):
            ninth_words.append(word)
    # 이 사이에 이번 단계의 핵심을 넣는다.
    ninth_words_list.append(ninth_words)


# 10 단계 dictionary 자료형 이용해서 정수인코딩을 한다.

# 10 - 1 : 각 단어별로 등장 횟수를 알아본다.
word_count = {}

for words in ninth_words_list:
    for word in words:
        # 각워드가 한 번도 카운트되지 않은 것이면 카운트를 0으로 세팅
        if word not in word_count.keys() :
            word_count[word] = 0
        # 각 워드가 나타날때마다 카운트를 1씩 증가한다.
        word_count[word] += 1


    # 10 - 1 단계 결과

# 워드별로 개수를 출력한다.
print(word_count['love'])
print(word_count['happy'])
print(word_count['computer'])
print(word_count['engineering'])

# 10 - 2 : 가장 숫자가 많은 워드부터 정렬해서 나열해봅니다.
sorted_word_list = sorted(word_count, key = lambda x: word_count[x], reverse = True)

# 10 - 2 단계 결과
# 가장 많이 나온 상위 10개 단어와 그 나온 횟수 출력

for i in range(0, 10):
    print(i + 1,":", sorted_word_list[i], ":", word_count[sorted_word_list[i]])

# 10 - 3단계 : input data 차원을 줄이기 위해 1, 2번만 나타나는 단어는 제외하고 나머지 단어에 대해 정수 인코딩을 부여한다.
# 가장 많이 등장하는 단어부터 낮은 인덱스를 부여한다.
encoding = {}

# 여기서 134969, 32225는 각각 1,2 번만 나타나는 단어의 개수
for i in range(len(sorted_word_list) - (134959 + 32225)):
    encoding[sorted_word_list[i]] = i + 1

# 10 - 3 단계 결과

print(encoding.keys())
print(encoding.values())

print(encoding['like']) # 1 st
print(encoding['love']) # 3 rd
print(encoding['see'])  # 20 th
print(encoding['year']) # 40 th
print(encoding['fuck']) # 70 th most often word

# 11단계 각 사용자 별로 가지는 워드를 정수로 인코딩해서 집어넣는다.

encoded_words_list = []
for words in ninth_words_list:
    # 이 사이에 이번 단계의 핵심을 넣는다.
    encoded_words = []
    for word in words:
        if word in encoding.keys() :
            # 워드가 인코딩 키 집합에 있으면 그 키에 해당하는 정수로 인코딩한다.
            encoded_words.append(encoding[word])
        else :
            # 워드가 인코딩 키 집합에 없으면 OutOfVocabulary에 해당하는 정수로 인코딩한다.
            # 해당 정수 = 전체 인코딩 키 집합 개수 + 1
            encoded_words.append(len(encoding) + 1)
    # 이 사이에 이번 단계의 핵심을 넣는다.
    encoded_words_list.append(encoded_words)


# 11단계 결과
# 정수 인코딩 결과와 실제값 비교해본다.

print(ninth_words_list[4])
print(encoded_words_list[4])

print(encoding['give'])
print(encoding['ha'])
print(encoding['pica'])
print(encoding['since'])
print(encoding['childhood'])
print(encoding['say'])
print('qubool' in encoding.keys())

# 12단계 사전작업 : 각 사람에 해당하는 데이터에 몇 개 단어가 들어있는지 테스트해본다.

length = []

for i in range(len(encoded_words_list)):
    length.append(len(encoded_words_list[i]))

length = sorted(length, reverse = True)

print(length[0:20])

# 8개 제외하고 모두 2000단어 미만이다. -> 2000단어로 단어 크기 정규화

# 12단계 길이를 맞춰주기 위해 0으로 패딩한다.
# 2000단어보다 크면 잘라내고, 2000단어보다 작으면 그만큼 채워 넣는다.

padded_words_list = []
for words in encoded_words_list:
    # 이 사이에 이번 단계의 핵심을 넣는다.
    # 단어들의 길이가 2000보다 크다면 앞에서부터 2000만큼만 사용한다.
    if len(words) > 2000 :
        padded_words = words[:2000]
    # 단어들의 길이가 2000보다 작다면 길이가 2000이 될 때 까지 0을 append한다.
    else :
        padded_words = words
        while len(padded_words) < 2000 :
            padded_words.append(0)
    # 이 사이에 이번 단계의 핵심을 넣는다.
    padded_words_list.append(padded_words)


# 12 단계 결과 : 각 사람 데이터에 대해 길이가 전부 다 2000이 되었다.

length = []

for i in range(len(padded_words_list)):
    length.append(len(padded_words_list[i]))

length = sorted(length, reverse = True)

# 길이가 전부 다 2000이 된 것을 확인 할 수 있다.
print(length[0:10])
print(length[-10:-1])

# 최종 인코딩 결과 : 길이 2000의 숫자 배열로 만들어졌다.

print(padded_words_list[4])