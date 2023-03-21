#4번 문제, C135333, 임원재

i = 1
x = int(input("첫번째 정수: "))
y = int(input("두번째 정수: "))

answer = 0
while (i <= x) or (i <= y):
    if (x % i == 0) and (y % i == 0):
        answer = i
    i += 1
print(answer)