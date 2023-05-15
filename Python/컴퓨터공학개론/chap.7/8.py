#8번 문제, C135333, 임원재

dictionary = dict()
not_dupl_name = 0
not_dupl_tel = 0

while True:
    name = input("이름?")
    if name == "":
        break
    elif name not in dictionary: #name이 dictionary에 없으면
        not_dupl_name += 1
    
    while True:
        tel = input("전화번호?")
        if tel != "":
            cnt = 0
            for k, v in dictionary.items():
                if v == tel or tel in v: #전화번호가 있을때
                    cnt += 1
            if cnt == 0: #tel이 dictionary에 없으면
                not_dupl_tel += 1
            break

    if name in dictionary: #name에 dictionary에 있을때
        dictionary[name] = [dictionary[name], tel]
    elif name not in dictionary: #name에 dictionary가 없을때
        dictionary[name] = tel #정상적으로 추가

print(dictionary)
print()
print("중복되지 않은 사람 수 : %d"  %not_dupl_name)
print("중복되지 않은 전화번호 수 : %d" %not_dupl_tel)
print()

while True:
    lst = set()
    find = input("찾고싶은 사람의 이름 또는 전화번호를 입력하세요? ")
    if find == "":
        print("프로그램을 종료합니다")
        break
    
    #전화번호일때
    if find.isdigit():
        cnt = 0
        for k, v in dictionary.items():
            if find == v or find in v: #전화번호인지 혹은 리스트 안에 있는지
                cnt += 1
        if cnt == 0:
            print("%s는 등록되지 않았습니다" %find)
            continue

        for k, v in dictionary.items():
            if find == v or find in v:
                lst.add(k)
        
        for i in lst:
            print(i, end = " ")
        print()


    #이름일때
    else:
        if find not in dictionary:
            print("%s는 등록되지 않았습니다" %find)
            continue
        
        for k, v in dictionary.items():
            if k == find:
                if str(type(v)) == "<class 'list'>":
                    for i in v:
                        lst.add(i)
                elif str(type(v)) == "<class 'str'>":
                    lst.add(v)
        
        for i in lst:
            print(i, end = " ")
        print()