#7번 문제, C135333, 임원재

dictionary = dict()

while True:
    string = input("이름 또는 전화번호?")
    if string == "": #엔터키
        break

    elif string.isdigit(): #string이 전화번호일때
        for k, v in  dictionary.items():
            if string == v: #전화번호부에 있을때
                print(f"전화번호 {v}의 소유주는 {k}")
                continue
            #전화번호부에 없을때
        print("없는 전화번호입니다.")
    
    #string이 이름일때
    elif string not in dictionary: #이름이 dictionary에 없을때 전화번호 묻기
        while True:
            tel = input("전화번호?")
            if tel != "":
                dictionary[string] = tel
                break

    elif string in dictionary: #이름이 dictionary에 있을때 전화번호 출력
        print(f"{string}의 전화번호는 {dictionary[string]}")
        continue

print("프로그램을 종료합니다")