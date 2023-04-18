#3번 문제, C135333, 임원재

def isPrime(n):
    cnt = 0
    for i in range(2, n): #2부터 n-1까지 반복
        if (n % i) == 0:
            return False #한번이라도 나눠지면 소수x
    return True #항상 나눠지지 않으면 소수o

num = int(input("정수 입력하시오: "))

for i in range(2, num + 1): #2부터 n까지 반복
    if isPrime(i): #isPrime이 true이면,
        print(i, end=" ")