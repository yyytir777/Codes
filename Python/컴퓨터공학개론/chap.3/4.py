#4번 문제, C135333, 임원재

num = int(input("정수를 입력하시오: "))

if (num % 2 == 0 and num % 3 != 0) or (num % 2 != 0 and num % 3 == 0):
    print("2 또는 3으로 나누어지지만 2와 3으로 동시에 나누어지지 않는 수")