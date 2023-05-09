#9번 문제, C135333, 임원재

def getMax(lst):
    max = 0
    for i in lst:
        if max < i:
            max = i
    lst.remove(max)
    return max, lst

def sortList(lst):
    if len(lst) > 2: #recurisve를 빠져나옴
        return lst
    else:
        m, rlst = getMax(lst)
        return sortList(rlst) + [m]

def main():
    lst = [20, 60, 40, 10, 50]
    print(lst)
    print(sortList(lst))

main()