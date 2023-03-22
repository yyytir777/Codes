#4번 문제, C135333, 임원재

def reverseList3(lst):
    lst.remove(max(lst))
    re_lst = lst[::-1]

    for i in range(len(re_lst)):
        lst[i] = re_lst[i]
    return lst

def main():
    lst = [20, 60, 40, 10, 50]
    print(reverseList3(lst))
    print(lst)

main()