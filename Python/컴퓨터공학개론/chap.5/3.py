#3번 문제, C135333, 임원재

def isPrime(n):
    cnt = 0
    for i in range(2,n):
        if (n % i) == 0:
            return False
    return True

num = int(input("정수 입력하시오: "))

for i in range(2, num):
    if isPrime(i):
        print(i, end=" ")
    else:
        continue