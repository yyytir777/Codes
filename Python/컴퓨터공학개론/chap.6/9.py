#9번 문제, C135333, 임원재

def sortList(lst):
    while lst != []:
        small = min(lst)
        lst.remove(small)
        return small + sortList(lst)

def main():
    lst = [20, 60, 40, 10, 50]
    print(lst)
    print(sortList(lst))

main()