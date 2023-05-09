#10번 문제, C135333, 임원재

lst = []
cnt = 0
while True:
    name = input("이름? ")
    if name == '':
        print("입력 모드를 종료합니다")
        break

    while True:
        tel = input("전화번호? ")
        if tel != '':
            break

    lst += [[name, tel]]
    cnt += 1

print("전화번호책:",lst)

while True:
    find_name = input("전화번호 찾고싶은 사람의 이름을 입력하세요? ")
    if find_name == '':
        print("프로그램을 종료합니다")
        break
    
    for i in range(cnt):
        if find_name == lst[i][0]: #리스트 순회
            print("%s의 전화번호는 %s입니다" %(lst[i][0], lst[i][1]))