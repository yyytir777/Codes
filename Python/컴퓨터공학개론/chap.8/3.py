#3번 문제, C135333, 임원재

class Point:
    def __init__(self, x = 0, y = 0):
        self.__x = x
        self.__y = y

    def move(self, x, y):
        x1 = self.__x + x
        y1 = self.__y + y
        return Point(x1, y1)

    def __str__(self):
        return f"({self.__x}, {self.__y})"
    
def main():
    a = Point()
    b = Point(1,5)
    print("a =", a)
    a.move(2,3)
    b.move(4,3).move(-1,-2)
    print(f'a.move(2,3) = {a.move(2,3)}, a = {a}, b = {b} ')

main()