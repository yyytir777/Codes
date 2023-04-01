#7번 문제, C135333, 임원재

a = int(input("숫자 1: "))
b = int(input("숫자 2: "))
c = int(input("숫자 3: "))

if b > a > c or c > a > b:
    print(a)
elif a > b > c or c > b > a:
    print(b)
elif a > c > b or b > c > a:
    print(c)