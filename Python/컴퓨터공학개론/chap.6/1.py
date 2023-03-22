#1번 문제, C135333, 임원재

list_num = []
sum = 0

while True:
    num = int(input("정수를 입력하시오: "))
    if num < 0:
        break
    list_num.append(num)
    sum += num
    
avg = sum / len(list_num)

print("평균= %d" %avg)