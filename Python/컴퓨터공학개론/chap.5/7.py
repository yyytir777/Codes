#7번 문제, C135333, 임원재

def convertChar(c):
    if c.isupper():
        return c.lower()
    else:
        return c.upper()

def main():
    char = input("문자를 입력하시오?")
    print(convertChar(char))

main()