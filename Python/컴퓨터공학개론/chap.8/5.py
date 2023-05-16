#5번 문제, C135333, 임원재

class Employee:
    SN = 0
    def __init__(self, name, salary):
        Employee.SN += 1
        self.__SN = Employee.SN
        self.__name = name
        self.__salary = salary
    
    def __str__(self):
        return "SN : %d 이름 : %s 월급 : %d" %(self.__SN, self.__name, self.__salary)

def main():
    a = Employee("사장", 1200)
    b = Employee("김수철", 300)
    c = Employee("이영애", 600)

    print(a)
    print(b)
    print(c)

main()