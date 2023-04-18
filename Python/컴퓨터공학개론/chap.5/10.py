#10번 문제, C135333, 임원재

def mySum(*args): #*args로 튜플의 형태로 받아옴
    sum = 0
    for i in args:
        if i % args[0] == 0:
            sum += i
    return sum


def main():
    print(mySum(2,3,4,6,8,19))
    print(mySum(5,20,10,4))

main()