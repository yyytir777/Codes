#8번 문제, C135333, 임원재

dictionary = dict()
#set 자료형을 사용하므로써 중복되지 않은 사람 or 전화번호 수 구함
name_set = set()
tel_set = set()

while True:
    name = input("이름? ")
    if name == "":
        break
    elif name not in dictionary: #name이 dictionary에 없으면
        name_set.add(name)
    
    while True:
        tel = input("전화번호? ")
        if tel != "":
            cnt = 0
            for k, v in dictionary.items():
                if v == tel or tel in v: #전화번호가 있을때
                    cnt += 1
            if cnt == 0: #tel이 dictionary에 없으면
                tel_set.add(tel)
            break

    if name in dictionary: #name에 dictionary에 있을때
        dictionary[name] += [tel] #list형태로 추가
    elif name not in dictionary: #name에 dictionary가 없을때
        dictionary[name] = [tel] #value에 list type 형태로 추가 -> 여러개의 전화번호를 저장 & 중복 허용

print()
print("중복되지 않는 사람 수 : %d" %(len(name_set)))
print("중복되지 않는 전화번호 수 : %d" %(len(tel_set)))
print()

while True:
    find_set = set()
    find = input("찾고싶은 사람의 이름 또는 전화번호를 입력하세요? ")
    #find = 빈칸일때
    if find == "":
        print("프로그램을 종료합니다")
        break
    
    #전화번호일때
    # isdigit() -> 숫자인지 판단하는 함수
    if find.isdigit():
        cnt = 0
        for k, v in dictionary.items():
            if find == v or find in v: #전화번호인지 혹은 리스트 안에 있는지
                cnt += 1

        #전화번호가 dictionary에 없을때
        if cnt == 0:
            print("%s는 등록되지 않았습니다" %(find))
            continue

        #dictionary를 순회하며 입력한 전화번호를 가지고 있는 사람 find_set에 추가
        for k, v in dictionary.items():
            if find == v or find in v:
                find_set.add(k)
        
        #find_set 출력(set이므로 중복 허용 x)
        for i in find_set:
            print(i, end = " ")
        print()

    #이름일때
    else:
        if find not in dictionary:
            print("%s는 등록되지 않았습니다" %(find))
            continue
        
        #이름이 dictionary에 있을때
        for k, v in dictionary.items():
            #해당 이름에 대한 값 순회(list type)
            if k == find:
                for i in v:
                    find_set.add(i)
        
        #find_set 출력(set이므로 중복 허용 x)
        for i in find_set:
            print(i, end = " ")
        print()