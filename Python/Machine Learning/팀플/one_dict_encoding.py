import pandas as pd
import numpy as np
import csv

df = pd.read_csv("C:\\Users\\yyyti\\Documents\\Code\\Python\\Machine Learning\\팀플\\twitter_MBTI.csv", encoding='iso-8859-1')

array = df.to_numpy()

data_list = []

# 출력할 행 (각 사용자마다 단어 추출하여 이중리스트 구성)
n = len(array)
print(n)
for i in range(n):
    # 문장 부분
    string = array[i, 1]
    # |||로 구분된 게시글 split
    splited_string = string.split('|||')

    # 정제된 문장 목록 초기화
    cleaned_sentences = []

    for sentence in splited_string:
        # 괄호 삭제
        sentence = sentence.replace('(', '').replace(')', '')

        # ?가 포함된 문자열 분할
        if '?' in sentence:
            sentence = sentence.split('?')
        else:
            sentence = [sentence]  # ??가 없는 경우에는 원래 문자열을 사용

        # http로 시작하는 문자열 삭제
        sentence = [word for word in sentence if 'http' not in word]

        # @로 시작하는 태그 삭제
        words = ' '.join(sentence).split()
        words = [word for word in words if not word.startswith('@')]

        # \x로 시작하는 이모티콘 삭제
        words = [word for word in words if word.isascii()]

        words = [word.lower() for word in words]

        # 정제된 문장을 정제된 문장 목록에 추가
        words = [word for word in words if len(word) > 2]
        cleaned_sentences.extend(words)

    # 한 사용자의 정제된 단어 배열 저장
    data_list.append(cleaned_sentences)

# data_list = [['asdf', 'asdf', 'asdf', ...], ['qwer', 'qwer', 'qwer', ...], ['zxcv', 'zxcv', 'zxcv', ...] ...]

# -- 정수 인코딩 --
# user_list : 사용자별 단어 사용 빈도를 dictionary화하여 리스트에 저장
user_list = list()
len_list = list()

word_count = {}
for words in data_list:
    for word in words:
        if word not in word_count.keys():
            word_count[word] = 1
        else:
            word_count[word] += 1

sorted_word_list = sorted(word_count, key=lambda x: word_count[x], reverse=True)

keyis1 = sum(1 for v in word_count.values() if v == 1)
keyis2 = sum(1 for v in word_count.values() if v == 2)

pro_dic = dict()
for i in range(len(word_count) - (keyis1 + keyis2)):
    pro_dic[sorted_word_list[i]] = i + 1
pro_dic['OOV'] = len(pro_dic) + 1

for i in range(n):
    encoded_sentences = list()
    
    # Encode sentences
    for word in data_list[i]:
        try:
            encoded_sentences.append(pro_dic[word])
        except KeyError:
            encoded_sentences.append(pro_dic['OOV'])

    len_list.append(len(encoded_sentences))
    user_list.append(encoded_sentences)

# 1000개 단어로 크기 정규화
user_padded_list = list()
for i in range(n):
    if len(user_list[i]) >= 1000:
        tmp = user_list[i][:1000]
    else:
        tmp = user_list[i]
        while len(tmp) < 1000:
            tmp.append(0)
    user_padded_list.append(tmp)

import pickle

with open("C:\\Users\\yyyti\\Documents\\Code\\Python\\Machine Learning\\팀플\\wonjae_input_data.pkl", "wb") as outfile:
    pickle.dump(user_padded_list, outfile)
    print("pkl successful")

import json

with open("C:\\Users\\yyyti\\Documents\\Code\\Python\\Machine Learning\\팀플\\wonjae_input_data.json", "w") as js:
    json.dump(user_padded_list, js)
    print("json successful")