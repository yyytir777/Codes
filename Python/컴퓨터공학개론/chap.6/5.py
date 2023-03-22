#5번 문제, C135333, 임원재

def getMean(list1):
    sum1 = 0
    for i in list1:
        sum1 += int(i)
    global avg
    avg = sum1 / len(list1)
    return avg

def getDeviation(list1):
    #표준편차 계산
    sum2 = 0
    for i in range(len(list1)):
        num2 = avg - int(list1[i])
        if num2 < 0:
            num2 = -num2
        sum2 += (num2 ** 2)
    sum2 = sum2 / (len(list1) - 1)
    return sum2 ** (1/2)



def main():
    inputString = input("정수 리스트 입력: ")
    list1 = []
    list1 = inputString.split()

    print("평균=", getMean(list1))
    print("표준 편차", getDeviation(list1))

main()