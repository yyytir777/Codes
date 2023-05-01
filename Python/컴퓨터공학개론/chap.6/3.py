#3번 문제, C135333, 임원재

def reverseList2(lst):
    lst1 = [] + lst
    reversed_lst = []
    lst1.remove(max(lst1))
    for i in lst1:
        reversed_lst = [i] + reversed_lst
    return reversed_lst

def main():
    lst = [20, 60, 40, 10, 50]
    print(reverseList2(lst))
    print(lst)

main()