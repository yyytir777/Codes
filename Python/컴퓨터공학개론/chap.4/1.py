#1번 문제, C135333, 임원재

interest = float(input("이자율 입력하시오? ")) / 100
mag = float(input("목표 배율을 입력하시오? "))
interest += 1

n = 1
while True:
    if (interest ** n) < mag:
        n += 1
        continue
    elif interest ** n >= mag:
        print("이자율이 %0.3f 일때 원금의 %0.1f 배가 되기 위해 %d 년이 걸립니다" %((interest - 1), mag, n)) 
        break