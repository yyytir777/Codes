class Circle:
# Circle 객체를 생성한다.
    def __init__(self, radius = 1):
        self.radius = radius

    def methodA(self):
        print("In methodA")

    def method(self):
        Circle.funcA()
        Circle.funcB("called by method")
        self.funcA()
        self.funcB("called by method twice")
        self.methodA()

    def funcA():
        print("In funcA()")
        
    def funcB(a) :
        print("In classfunc",a)

Circle.funcA()
Circle.funcB("called by funcB")

x = Circle(5)

x.funcA()
x.method()