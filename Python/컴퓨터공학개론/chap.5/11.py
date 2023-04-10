#11번 문제, C135333, 임원재

def rcsvSum(num):
    if num == 1:
        return 1
    return num + rcsvSum(num-1)

def main():
    print(rcsvSum(10))
    print(rcsvSum(5))

main()