#8번 문제, C135333, 임원재

def convertChar(c):
    letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    upperletter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    lowerletter = "abcdefghijklmnopqrstuvwxyz"
    
    if c in upperletter:
        for i in range(0, 26):
            if c == upperletter[i]:
                return letter[i+26]
            
    elif c in lowerletter:
        for i in range(0, 26):
            if c == lowerletter[i]:
                return letter[i]

def convertString(string):
    answer = ''
    for i in string:
        answer += convertChar(i)
    return answer

def main():
    string = input("문자열을 입력하시오?")
    print(convertString(string))

main()