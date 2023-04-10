#5번 문제, C135333, 임원재

def getSorted(x, y, z):
    if x >= y:
        if z > x:
            return (y, x, z)
        elif x >= z >= y:
            return (y, z, x)
        else: # y > z
            return (z, y, x)
    else:
        if z > y:
            return (x, y, z)
        elif y >= z >= x:
            return (x, z, y)
        else: # x > z
            return (z, x, y)

def main():
    x = int(input("첫 번째 정수: "))
    y = int(input("두 번째 정수: "))
    z = int(input("세 번째 정수: "))
    print(getSorted(x, y, z))

main()