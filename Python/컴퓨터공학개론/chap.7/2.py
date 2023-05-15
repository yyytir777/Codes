#2번 문제, C135333, 임원재

string = input("문자열을 입력하시오: ")
char = input("문자를 입력하시오: ")

cnt = 0
for i in string:
    if char == i:
        cnt += 1
print("\"%s\" 문자의 빈도는 %s 이다" %(char, cnt))