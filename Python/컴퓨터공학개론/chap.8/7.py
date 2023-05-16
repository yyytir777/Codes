#7번 문제, C135333, 임원재

class BankAccount:
    interest_rate = 0.3
    maturity = 0
    def __init__(self, name, number, balance):
        self.__name = name
        self.__number = number
        self.__balance = balance

    def deposit(self, money):
        self.__balance += money

    def withdraw(self, money):
        self.__balance -= money

    def maturityAmount(self):
        BankAccount.maturity = self.__balance * (1 + BankAccount.interest_rate)
        return BankAccount.maturity
    
    def __str__(self):
        return f'Name : {self.__name} Number : {self.__number} Balance : {self.__balance}'

def main():
    a = BankAccount("김철수", "82345", 1000)
    print(a)
    print("Interest Rate =", BankAccount.interest_rate, "Maturity : ", a.maturityAmount())
    a.deposit(3000)
    print(a)
    a.withdraw(1500)
    print(a)

    BankAccount.interest_rate = 0.7
    print("Interest Rate =", BankAccount.interest_rate, "Maturity : ", a.maturityAmount())

main()