#4번 문제, C135333, 임원재

class Dog:
    def __init__(self, kind, name):
        self.__kind = kind
        self.__name = name
        self.__tirck_lst = []

    def add_trick(self, trick):
        self.__tirck_lst += [trick]

    def __str__(self):
        all_trick = " ".join(self.__tirck_lst)
        return "%s %s는 %s를 할 수 있습니다" %(self.__kind, self.__name, all_trick)

def main():
    a = Dog('월시코기', '바둑이')
    b = Dog('푸들', '멍멍이')
    a.add_trick('뒹굴기')
    b.add_trick('달리기')
    b.add_trick('점프하기')
    print(a)
    print(b)

main()