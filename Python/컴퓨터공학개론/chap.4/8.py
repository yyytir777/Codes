#8번 문제, C135333, 임원재

string = input("문자열을 입력하시오? ")

answer = ""
for i in string:
    answer = i + answer
print(answer)