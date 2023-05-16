#6번 문제, C135333, 임원재

dictionary = dict()
while True:
    name = input("이름?")
    if name == "":
        break
    elif name in dictionary:
        print("%s의 전화번호는 %s" %(name, dictionary[name]))
        continue


    while True:
        tel = input("전화번호?")
        if tel != "":
            dictionary[name] = tel
            break
        
print("프로그램을 종료합니다")