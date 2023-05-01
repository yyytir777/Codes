#8번 문제, C135333, 임원재

def getMax(lst):
    max = 0
    for i in lst:
        if max < i:
            max = i
    lst.remove(max)
    return max, lst

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