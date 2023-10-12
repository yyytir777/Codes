def getGCD(x, y):
    i = 1
    m = max(x,y)
    while(1):
        if(m % x == 0) and (m % y == 0):
            answer = m
            break
        m += 1
    return answer

print(getGCD(12,14))