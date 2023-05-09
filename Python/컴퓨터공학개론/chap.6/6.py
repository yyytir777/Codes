#6번 문제, C135333, 임원재

import random

cnt_lst = []
num = int(input("주사위를 던지는 횟수를 입력하시오 : "))
for i in range(0, num):
    dice = random.randint(1,6)
    cnt_lst.append(dice)

for i in range(6):
    print("주사위가 %d(i+1) 인 경우는 %d" %(i + 1, cnt_lst.count(i + 1)))