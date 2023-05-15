#10번 문제, C135333, 임원재

def mydeepcopy(lst):
    #lst가 hashable한 자료형일때
    if type(lst) in (str, float, int):
        return lst

    #lst가 unhashable한 자료형일때
    else:
        copy_lst = []
        for i in lst:
            copy_lst.append(mydeepcopy(i))
    return copy_lst

def main():
    s = ["aaa",["bbb", ["ccc", ["ddd", "eee", 45]]]]
    d = mydeepcopy(s)

    d[1][1][1][1] = 'xxxxx'

    print(d)
    print(s)

main()