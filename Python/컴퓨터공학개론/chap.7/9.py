#9번 문제, C135333, 임원재

dictionary = dict()
#set 자료형을 사용하므로써 중복되지 않은 사람 or 전화번호 수 구함
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
        dictionary[name] += [tel] #list형태로 추가
    elif name not in dictionary: #name에 dictionary가 없을때
        dictionary[name] = [tel] #value에 list type 형태 사용 -> 여러개의 전화번호 저장 & 중복 허용

print()
print("중복되지 않는 사람 수 : %d" %(len(name_set)))
print("중복되지 않는 전화번호 수 : %d" %(len(tel_set)))
print()

while True:
    modified_name_set = set()
    modified_tel_set = set()

    find = input("지우고 싶은 사람의 이름 또는 전화번호를 입력하세요? ")

    if find == "":
        print("프로그램을 종료합니다")
        break

    #전화번호
    # isdigit() -> 숫자인지 판단하는 함수
    if find.isdigit():
        #dictionary에 전화번호가 있는지 체크
        cnt = 0
        for i in dictionary.values():
            if find in i:
                cnt += 1
        #없으면 continue
        if cnt == 0:
            continue
        
        #전화번호 리스트 안에 전화번호가 있다면 리스트 안에서 삭제, 만약 리스트가 빈다면 해당 항목 상제
        for k, v in dictionary.items():
            for i in v:
                #각 리스트 안에 찾는 전화번호가 있다면 삭제
                if find == i:
                    dictionary[k].remove(i)
                    #만약 삭제 후, 동일 전화번호가 중복되어있어서 하나밖에 삭제하지 못했다면
                    #해당 리스트를 빈 리스트로 선언
                    if dictionary[k] == [i]:
                        dictionary[k] = []
        
        del_lst = [] #빈 리스트를 value값으로 가지는 원소를 추가할 list
        for k, v in dictionary.items():
            #각 key값의 value가 빈리스트일때 key값 del_lst에 추가
            if dictionary[k] == []:
                del_lst += [k]

        #del_lst순회하며 해당 (key : value) 삭제
        for i in del_lst:
            del dictionary[i]
        
        #전화번호 리스트의 원소를 tel_set에 추가 --> 중복되지 않은 전화번호 개수 출력
        for v in dictionary.values():
            for i in v:
                modified_tel_set.add(i)

        #만약 원소가 없다면 continue
        if len(modified_tel_set) == 0:
            continue

        #원소가 존재하면 중복되지 않는 전화번호의 수(modified_tel_set)출력
        print("중복되지 않는 전화번호의 수 %d" %(len(modified_tel_set)))
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

        #원소가 존재하면 중복되지 않는 사람의 수(modified_name_set)출력
        print("중복되지 않는 사람의 수 %d" %(len(modified_name_set)))
        for i in modified_name_set:
            print(i, end = " ")
        print()