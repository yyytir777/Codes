#4번 문제, C135333, 임원재

def deci2bin(x):
    num = ""
    while x:
        if (x % 2) == 0: #2로 나눠지면 맨 앞에 0 추가
            num = "0" + num
        else: #2로 나눠지지 않으면 맨 앞에 1 추가
            num = "1" + num
            x -= 1
        x /= 2
    return "0b" + num


def main():
    x = int(input("10진수: "))
    print(deci2bin(x))

main()