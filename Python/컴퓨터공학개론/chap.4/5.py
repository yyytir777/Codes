#5번 문제, C135333, 임원재

num = int(input("3보다 큰 홀수를 입력하시오? "))
sum = 0

for i in range(1, num, 2):
    sum += (i / (i + 2))
print(sum)