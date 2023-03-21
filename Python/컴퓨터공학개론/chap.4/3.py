#3번 문제, C135333, 임원재

sum = 0
while True:
    num = int(input("정수를 입력하시오:"))
    if num == 0:
        print("합은 %d 입니다" %sum)
        break
    else:
        sum += num
        
