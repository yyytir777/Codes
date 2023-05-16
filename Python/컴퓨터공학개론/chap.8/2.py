#2번 문제, C135333, 임원재

class Point:
    def __init__(self, x = 0, y = 0):
        self.__x = x
        self.__y = y

    def move(self, x, y):
        self.__x += x
        self.__y += y
        return self

    def __str__(self):
        return "(%d, %d)" %(self.__x, self.__y)
    
def main():
    a = Point()
    b = Point(1,5)
    print("a =", a)
    a.move(2,3)
    b.move(4,3).move(-1,-2)
    print("a =", a, "b =", b)

main()