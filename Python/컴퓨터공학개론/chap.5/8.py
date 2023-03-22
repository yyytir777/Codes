#8번 문제, C135333, 임원재

def convertChar(c):
    if c.isupper():
        return c.lower()
    else:
        return c.upper()

def convertString(string):
    answer = ""
    for i in string:
        answer += convertChar(i)
    return answer

def main():
    string = input("문자열을 입력하시오?")
    print(convertString(string))

main()