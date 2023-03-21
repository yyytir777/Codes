#2번 문제, C135333, 임원재

def getGCD(x, y):
    i = 1
    answer = 0
    while(i <= x) or (i <= y):
        if(x % i == 0) and (y % i == 0):
            answer = i
        i += 1
    return answer

def main():
    x = int(input("첫 번째 정수: "))
    y = int(input("두 번째 정수: "))
    print(getGCD(x, y))

main()