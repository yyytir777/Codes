import pandas as pd

df = pd.read_csv("C:\\Users\\yyyti\\Documents\\Code\\Python\\Machine Learning\\팀플\\twitter_MBTI.csv", encoding='iso-8859-1')

array = df.to_numpy()

data_list = []

# 출력할 행 (각 사용자마다 단어 추출하여 이중리스트 구성)
for i in range(0, 1):
    # 문장 부분
    string = array[i, 1]
    # |||로 구분된 게시글 split
    splited_string = string.split('|||')

    # 정제된 문장 목록 초기화
    cleaned_sentences = []

    for sentence in splited_string:
        # 괄호 삭제
        sentence = sentence.replace('(', '').replace(')', '')

        # ??가 포함된 문자열 분할
        if '??' in sentence:
            sentence = sentence.split('??')
        else:
            sentence = [sentence]  # ??가 없는 경우에는 원래 문자열을 사용

        # http로 시작하는 문자열 삭제
        sentence = [word for word in sentence if 'http' not in word]
        
        # @로 시작하는 태그 삭제
        words = ' '.join(sentence).split()
        words = [word for word in words if not word.startswith('@')]

        # # \x로 시작하는 이모티콘 삭제
        print(words)
        tmp = list()        
        for word in words:
            if '\\x' not in word:
                tmp.append(word)

        print(tmp)

        # 정제된 문장을 정제된 문장 목록에 추가
        cleaned_sentences.extend(words)

    # 한 사용자의 정제된 단어 배열 저장
    data_list.append(cleaned_sentences)

# data_list = [['asdf', 'asdf', 'asdf', ...], ['qwer', 'qwer', 'qwer', ...], ['zxcv', 'zxcv', 'zxcv', ...] ...]

# 예시로 첫 번째 사용자의 데이터 출력
print(data_list[0])