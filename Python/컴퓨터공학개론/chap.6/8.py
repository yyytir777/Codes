#8번 문제, C135333, 임원재

def getMax(lst):
    max_num = 0
    for i in lst:
        if max_num < i:
            max_num = i
    lst.remove(max_num)
    return max_num, lst

def mySort(lst):
    sorted_lst = []
    for i in range(len(lst)):
        m, lst = getMax(lst)
        sorted_lst = [m] + sorted_lst
    return sorted_lst

def main():
    lst = [20, 60, 40, 10, 50]
    print(lst)
    print(mySort(lst))

main()