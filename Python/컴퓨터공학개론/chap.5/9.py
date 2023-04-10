#9번 문제, C135333, 임원재

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

def convertString(string, reverse = 0):
    answer = ""
    for i in string:
        answer += convertChar(i)
    
    if reverse == 0:
        return answer
    else:
        reverse_answer = ""
        for i in answer:
            reverse_answer = i + reverse_answer
        return reverse_answer

def main():
    string = input("문자열을 입력하시오?")
    print(convertString(string))

    string = input("문자열을 입력하시오?")
    print(convertString(string, 1))

main()