#6번 문제, C135333, 임원재

class Employee:
    employeeList = []
    SN = 0
    def __init__(self, name, salary):
        Employee.SN += 1
        self.__SN = Employee.SN
        self.__name = name
        self.__salary = salary
        Employee.employeeList.append(f'SN : {self.__SN} 이름 : {self.__name} 월급 : {self.__salary}')
    
    def __List__(self):
        return Employee.employeeList

def main():
    Employee("사장", 1200)
    Employee("김수철", 300)
    Employee("이영애", 600)
    a = Employee("장동철", 400)

    print("Employee List")
    for i in a.employeeList:
        print(i)

main()