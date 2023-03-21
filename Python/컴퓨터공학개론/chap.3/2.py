#2번 문제, C135333, 임원재

import random

x = random.randint(0,100)
y = random.randint(0,100)

num = int(input("%d + %d의 값은? " %(x, y)))

if(num == x + y):
    print("맞았습니다.")
else:
    print("틀렸습니다.")