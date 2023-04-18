#11번 문제, C135333, 임원재

def rcsvSum(num): #\sum(num)
    if num == 1:
        return 1
    return num + rcsvSum(num-1) #\sum(num) = num + \sum(num-1)

def main():
    print(rcsvSum(100))
    print(rcsvSum(5))

main()