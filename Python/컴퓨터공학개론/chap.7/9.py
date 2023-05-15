#9번 문제, C135333, 임원재

dictionary = dict()
name_set = set()
tel_set = set()

while True:
    name = input("이름?")
    if name == "":
        break
    elif name not in dictionary: #name이 dictionary에 없으면
        name_set.add(name)
    
    while True:
        tel = input("전화번호?")
        if tel != "":
            cnt = 0
            for k, v in dictionary.items():
                if v == tel or tel in v: #전화번호가 있을때
                    cnt += 1
            if cnt == 0: #tel이 dictionary에 없으면
                tel_set.add(tel)
            break

    if name in dictionary: #name에 dictionary에 있을때
        dictionary[name] += [tel] #여러개의 tel을 가지고 있음을 list로 추가
    elif name not in dictionary: #name에 dictionary가 없을때
        dictionary[name] = [tel] #정상적으로 추가

print(dictionary)
print()
print("중복되지 않은 사람 수 : %d"  %len(name_set))
print("중복되지 않은 전화번호 수 : %d" %len(tel_set))
print()

while True:
    modified_name_set = set()
    modified_tel_set = set()

    find = input("지우고 싶은 사람의 이름 또는 전화번호를 입력하세요? ")

    if find == "":
        print("프로그램을 종료합니다")
        break

    #전화번호
    delete_idx = []
    if find.isdigit():
        #dictionary에 전화번호가 있는지 체크
        cnt = 0
        for i in dictionary.values():
            if find in i:
                cnt += 1
        if cnt == 0:
            continue
        
        #전화번호 리스트 안에 전화번호가 있다면 리스트 안에서 삭제, 만약 리스트가 빈다면 해당 항목 상제
        for k, v in dictionary.items():
            if find in v:
                v.remove(find)
            if v == []:
                delete_idx += [k]
        for i in delete_idx:
            del dictionary[i]

        #전화번호 리스트의 원소를 tel_set에 추가 --> 중복되지 않은 전화번호 개수 출력
        for v in dictionary.values():
            for i in v:
                modified_tel_set.add(i)
        modified_tel_set.discard(find)
        #만약 원소가 없다면 continue
        if len(modified_tel_set) == 0:
            continue
        print("중복되지 않는 전화번호의 수 %d" %len(modified_tel_set))
        for i in modified_tel_set:
            print(i, end = " ")
        print()


    #이름
    else:
        #dictionary에 이름이 있는지 체크
        if find not in dictionary.keys():
            continue
        
        #해당 이름 삭제
        del dictionary[find]

        #남은 이름 name_set에 추가 --> 중복되지 않은 이름 개수 출력
        for k in dictionary.keys():
            modified_name_set.add(k)
        #만약 원소가 없다면 continue
        if len(modified_name_set) == 0:
            continue
        print("중복되지 않는 사람의 수 %d" %len(modified_name_set))
        for i in modified_name_set:
            print(i, end = " ")
        print()