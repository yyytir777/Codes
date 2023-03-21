#4번 문제, C135333, 임원재

def deci2bin(x):
    num = ""
    while x :
        if (x % 2) == 0:
            num = "0" + num
        else:
            num = "1" + num
            x -= 1
        x /= 2
    return num


def main():
    x = int(input("10진수: "))
    print(deci2bin(x))

main()