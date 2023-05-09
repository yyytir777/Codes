#5번 문제, C135333, 임원재


def getMean(list1):
    global avg
    sum1 = 0
    for i in list1:
        sum1 += int(i)
    avg = sum1 / len(list1)
    return avg

def getDeviation(list1):
    #표준편차 계산
    sum2 = 0
    for i in list1:
        num2 = avg - int(i)
        if num2 < 0: #음수일때 
            num2 = -num2 #양수로 변환
        sum2 += (num2 ** 2)
    sum2 = sum2 / len(list1)
    return sum2 ** (1/2)



def main():
    inputString = input("정수 리스트 입력: ")
    list1 = []
    list1 = inputString.split()

    print("평균=", getMean(list1))
    print("표준 편차", getDeviation(list1))

main()