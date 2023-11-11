import pandas as pd
import numpy as np
import csv

df = pd.read_csv("C:\\Users\\yyyti\\Documents\\Code\\Python\\Machine Learning\\팀플\\twitter_MBTI.csv", encoding='iso-8859-1')

array = df.to_numpy()


data_list = list()
# 출력할 행 (각 사용자마다 단어 추출하여 이중리스트 구성)
for i in range(0,10):
    # 문장 부분
    string = array[i, 1]
    # |||로 구분된 게시글 split
    splited_string = string.split('|||')

    # 괄호 삭제
    # 링크는 유지
    # @로 시작하는 태그 삭제

    # 띄어쓰기를 기준으로 단어 split
    word_list = list()
    for sentence in splited_string:
        sentence = sentence.split()

        # @로 시작하는 단어 삭제
        for words in sentence:
            if words[0] == '@':
                sentence.remove(words)

        word_list.extend(sentence)
    # 한 사용자의 정제된 단어 배열 저장
    data_list.append(word_list)

# data_list = [['asdf', 'asdf', 'asdf', ...], ['qwer', 'qwer', 'qwer', ...], ['zxcv', 'zxcv', 'zxcv', ...] ...]

# for i in word_list:
#     print(i)

print(data_list[0])