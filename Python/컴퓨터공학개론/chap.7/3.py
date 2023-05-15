#3번 문제, C135333, 임원재

lst = ["ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"]
string = input("문자열을 입력하시오:")
result = ""
for i in string:
    idx = 0
    for j in lst:
        if i in j:
            result += str(idx + 2)
        else:
            idx += 1

print(result)
