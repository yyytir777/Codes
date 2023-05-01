#4번 문제, C135333, 임원재

def reverseList3(lst):
    lst.remove(max(lst))
    length = len(lst)
    for i in range(length // 2):
        lst[i], lst[length - i - 1] = lst[length - i - 1], lst[i]
    return lst
    # lst변화 x

def main():
    lst = [20, 60, 40, 10, 50]
    print(reverseList3(lst))
    print(lst)

main()