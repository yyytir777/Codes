#2번 문제, C135333, 임원재

class Shape:
    def __init__(self, color, filled):
        self.__color = color
        self.__filled = filled

    def __str__(self):
        return f'({self.__color},{self.__filled})'

class Rectangle(Shape):
    def __init__(self, color, filled, width, height):
        super().__init__(color, filled)
        self.__width = width
        self.__height = height

    def area(self):
        return self.__height * self.__width
    
    def __str__(self):
        return f'{super().__str__()}({self.__width},{self.__height})'

def main():
    c = Rectangle("blue", False, 10, 20)
    print(c)
    print(c.area())

main()