#7번 문제, C135333, 임원재

def convertChar(c):
    #소문자와 대문자의 문자열 인덱스 값을 같게 구성
    letter = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
    upperletter = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    lowerletter = 'abcdefghijklmnopqrstuvwxyz'
    
    #c가 대문자일때, 위의 리스트에서 인덱스를 찾아 소문자로 변환
    if c in upperletter:
        for i in range(0, 26):
            if c == upperletter[i]:
                return letter[i+26]
    else:
    #c가 소문자일때, 위의 리스트에서 인덱스를 찾아 대문자로 변환
        for i in range(0, 26):
            if c == lowerletter[i]:
                return letter[i]


def main():
    char = input("문자를 입력하시오?")
    print(convertChar(char))

main()