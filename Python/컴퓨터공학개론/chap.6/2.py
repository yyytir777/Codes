#2번 문제, C135333, 임원재

def reverseList(lst):
    reversed_lst = []
    for i in lst:
        reversed_lst = [i] + reversed_lst
    return reversed_lst


def main():
    lst = [20, 60, 40, 10, 50]
    print(reverseList(lst))
    print(lst)

main()