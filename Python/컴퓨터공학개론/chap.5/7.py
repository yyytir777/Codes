#7번 문제, C135333, 임원재

def convertChar(c):
    letter = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
    upperletter = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    lowerletter = 'abcdefghijklmnopqrstuvwxyz'
    if c in upperletter:
        for i in range(0, 26):
            if c == upperletter[i]:
                return letter[i+26]
    else:
        for i in range(0, 26):
            if c == lowerletter[i]:
                return letter[i]


def main():
    char = input("문자를 입력하시오?")
    print(convertChar(char))

main()