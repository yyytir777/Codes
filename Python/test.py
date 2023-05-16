lst = ['1', '1', '1']

find = '1'
for i in lst:
    if find == i:
        lst.remove(i)

print(lst)