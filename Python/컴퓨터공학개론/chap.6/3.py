#3번 문제, C135333, 임원재

def reverseList2(lst):
    re_lst = [] + lst
    re_lst.remove(max(re_lst))
    return re_lst[::-1]

def main():
    lst = [20, 60, 40, 10, 50]
    print(reverseList2(lst))
    print(lst)

main()