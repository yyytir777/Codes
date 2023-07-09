#5번 문제, C135333, 임원재

class CPoint:
    def __init__(self, x = 0, y = 0):
        self.__x = x
        self.__y = y
    
    def move(self, x, y):
        self.__x += x
        self.__y += y
        return self

    def __str__(self):
        return f'pos({self.__x},{self.__y})'


class Shape():
    def __init__(self, color = "yellow", filled = True, cpoint = None):
        self.__color = color
        self.__filled = filled
        if cpoint != None:
            self.__CPoint = cpoint
        else:
            self.__CPoint = CPoint()

    def move(self, x, y):
        self.__CPoint.move(x, y)
        return self
    
    def __str__(self):
        return f'{self.__CPoint}({self.__color},{self.__filled})'


class Rectangle(Shape):
    def __init__(self, color, filled, width, height):
        super().__init__(color, filled)
        self.__width = width
        self.__height = height

    def area(self):
        return self.__height * self.__width
    
    def __str__(self):
        return f'{super().__str__()}({self.__width},{self.__height})'


class Circle(Shape):
    def __init__(self, color, filled, radius):
        super().__init__(color, filled)
        self.__radius = radius
    
    def area(self):
        return 3.14 * (self.__radius ** 2)

    def __str__(self):
        return f'{super().__str__()}(radius = {self.__radius})'

def main() :
    a = Shape()
    b = Shape("red")
    cpoint = CPoint(4,7)
    c = Shape("black",False,cpoint)
    print(a)
    print(b)
    print(c)
    a.move(2,3)
    print(a)
    print(b.move(4,5))
    d = Circle("blue",False,10).move(3,4)
    print(d)
    e = Rectangle("blue",False,10,20)
    print(e.move(7,8))
main()