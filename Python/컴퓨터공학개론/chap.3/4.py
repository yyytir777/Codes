#4번 문제, C135333, 임원재

weight = float(input("무게(킬로그램): "))
height = float(input("키(미터)): "))

bmi = weight / (height ** 2)
print("당신의 BMI:", bmi)

match bmi:
    case x if x >= 30:
        print("비만입니다.")
    case x if x >= 25:
        print("과체중입니다.")
    case x if x >= 20:
        print("정상입니다.")
    case _:
        print("저체중입니다.")