#1번 문제, C135333, 임원재

class Shape:
    def __init__(self, color = "yellow", filled = True):
        self.__color = color
        self.__filled = filled

    def __str__(self):
        return f'({self.__color},{self.__filled})'

class Circle(Shape):
    def __init__(self, color, filled, radius):
        super().__init__(color, filled)
        self.__radius = radius
    
    def area(self):
        return 3.14 * (self.__radius ** 2)

    def __str__(self):
        return f'{super().__str__()}(radius = {self.__radius})'
    
def main():
    a = Shape()
    b = Shape("red")
    print(a, b)
    c = Circle("blue", False, 10)
    print(c)
    print(c.area())

main()