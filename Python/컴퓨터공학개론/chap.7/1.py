#1번 문제, C135333, 임원재

day31 = [1, 3, 5, 7, 8, 10 ,12]
day30 = [4, 6, 9, 11]
day28or29 = [2]

while True:
    string = input("생년월일을 입력하시오? ")
    if string == '':
        print("프로그램을 종료합니다")
        break
    #윤년 : 4의 배수이면서 100의 배수가 아닐때 또는 400의 배수일때
    y = int(string[0:4])
    m = int(string[4:6])
    d = int(string[6:8])

    if m in day31:
        if 1 <= d <= 31:
            print("올바른 생년월일입니다.")
        else:
            print("올바르지 않은 생년월일입니다.")

    elif m in day30:
        if 1 <= d <= 30:
            print("올바른 생년월일입니다.")
        else:
            print("올바르지 않은 생년월일입니다.")

    elif m in day28or29:
        if 1 <= d <= 29 and (y % 4 == 0 and y % 100 != 0) or y % 400 == 0:
            print("올바른 생년월일입니다.")
        elif 1 <= d <= 28:
            print("올바른 생년월일입니다.")
        else:
            print("올바르지 않은 생년월일입니다.")
            
    else:
        print("올바르지 않은 생년월일입니다.")