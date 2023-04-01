#6번 문제, C135333, 임원재

import random
lotto = random.randint(10,99)

num = int(input("복권 번호(10-99사이)를 입력하시오: "))

if (num // 10 == lotto // 10) and (num % 10 == lotto % 10): #2자리가 전부 일치할때
    print("복권번호는 %d입니다. 상금은 100만원입니다." %lotto)
elif (num // 10 == lotto // 10) or (num % 10 == lotto % 10): #1자리만 일치할때
    print("복권번호는 %d입니다. 상금은 50만원입니다." %lotto)
else: #전부 일치하지 않을때
    print("복권번호는 %d입니다. 상금은 없습니다." %lotto)