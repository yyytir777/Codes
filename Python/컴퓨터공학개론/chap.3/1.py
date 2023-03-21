#1번 문제, C135333, 임원재

country = str(input("국가를 입력하시오: "))
state = str(input("도를 입력하시오: "))

if country == "한국":
    if state == "제주도":
        print("배송료는 10000원입니다.")
    else:
        print("배송료는 5000원입니다.")
else:
    print("배송료는 20000원입니다.")