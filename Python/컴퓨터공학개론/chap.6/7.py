#7번 문제, C135333, 임원재

def getMax(lst):
    max = 0
    for i in lst:
        if max < i:
            max = i
    lst.remove(max)
    return max, lst

def main():
    lst = [20, 60, 40, 10, 50]
    m, rlst = getMax(lst)
    print(m)
    print(rlst)

main()