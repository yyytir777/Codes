#9번 문제, C135333, 임원재

string = input("문자열을 입력하시오? ")
char = input("문자를 입력하시오? ")

cnt = 0
for i in string:
    if i == '$':
        break
    if i == char:
        cnt += 1
print(cnt)