#8번 문제, C135333, 임원재

class Complex:
    def __init__(self, real_n, imaginary_n):
        self.__rn = real_n
        self.__in = imaginary_n

    def __add__(self, other):
        real_n = self.__rn + other.__rn
        imaginary_n = self.__in + other.__in
        return Complex(real_n, imaginary_n)
    
    def __sub__(self, other):
        real_n = self.__rn - other.__rn
        imaginary_n = self.__in - other.__in
        return Complex(real_n, imaginary_n)
    
    def __eq__(self, other):
        if self.__rn == other.__rn and self.__in == other.__in:
            return True
        else:
            return False

    def __str__(self):
        return f'Complex({self.__rn}, {self.__in})'

def main():
    a = Complex(3.0, -4.5)
    b = Complex(4.0, -5.0)
    c = Complex(-1.0, 0.5)

    print(a+b)
    print(a+b-c)
    print(a-b)
    print(a-b+c)
    print(a-c)
    print(b == (a-c))

main()