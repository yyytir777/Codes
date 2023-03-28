#6번 문제, C135333, 임원재

import random
lotteryNumber = random.randint(10,99)

num = int(input("복권 번호(10-99사이)를 입력하시오: "))

if num // 10 == lotteryNumber // 10 and num % 10 == lotteryNumber % 10:
    print("복권번호는 %d입니다. 상금은 100만원입니다." %lotteryNumber)
elif num // 10 == lotteryNumber // 10 or num % 10 == lotteryNumber % 10:
    print("복권번호는 %d입니다. 상금은 50만원입니다." %lotteryNumber)
else:
    print("복권번호는 %d입니다. 상금은 없습니다." %lotteryNumber)