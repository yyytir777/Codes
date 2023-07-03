#6번 문제, C135333, 임원재

# Defining parent class 1
class Parent1:
    def __init__(self, a):
        super().__init__()
        self.__p1 = a
    
    #Parent's show method
    def show(self):
        print("Inside Parent1", self.__p1)
    
    def display(self):
        print("Inside Parent1", self.__p1)

#Defining parent class 2
class Parent2:
    def __init__(self, a, b):
        super().__init__(a)
        self.__p2 = b
    
    #Parent's show method
    def display(self):
        print("Inside Parent2", self.__p2)

#Defining child class
class Child(Parent2, Parent1):
    def __init__(self, a, b, c):
        super().__init__(a, b)
        self.__c = c

    #Child's show method
    def show(self):
        print("Inside Child", self.__c)

#Driver's code
obj = Child(1,2,3)

obj.show()
obj.display()