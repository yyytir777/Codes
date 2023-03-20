#5번 문제, C135333, 임원재

num = int(input("정수 = "))
sum = 0

sum += num // 100
num = num % 100

sum += num // 10
num = num % 10

sum += num

print(sum)