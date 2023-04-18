#6번 문제, C135333, 임원재

def getRange(low, high):
    while True: #if문을 만족할 때까지 반복
        num = int(input("숫자를 입력하시오(%d에서 %d까지 가능) " %(low, high)))
        if num >= low and num <= high:
            return num

def main():
    low = int(input("low 입력하시오 "))
    high = int(input("high 입력하시오 "))
    value = getRange(low, high)
    print("Input value is", value)

main()