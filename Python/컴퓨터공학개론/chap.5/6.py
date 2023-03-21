#6번 문제, C135333, 임원재

def getRange(low, high):
    while True:
        num = int(input("숫자를 입력하시오(0에서 23까지 가능) "))
        if num >= 0 and num <= 23:
            break

def main():
    value = getRange(0, 23)
    print("OK")

main()