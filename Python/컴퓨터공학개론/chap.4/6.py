#6번 문제, C135333, 임원재

import random

num = int(input("원하는 두 주사위의 합을 입력하시오? "))

while True:
    x = random.randint(1, 6)
    y = random.randint(1, 6)

    print("첫번째 주사위= %d 두번째 주사위= %d 합 = %d" %(x, y, x + y))

    if num == (x + y):
        print("원하는 합이 나왔습니다. 합 = %d" %(x + y))
        break