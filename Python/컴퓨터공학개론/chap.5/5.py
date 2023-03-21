#5번 문제, C135333, 임원재

def getSorted(x, y):
    if x >= y:
        return "(%d, %d)" %(y, x)
    else:
        return "(%d, %d)" %(x, y)

def main():
    x = int(input("첫 번째 정수: "))
    y = int(input("두 번째 정수: "))
    print(getSorted(x, y))

main()