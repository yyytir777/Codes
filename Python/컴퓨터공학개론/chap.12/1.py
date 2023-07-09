#1번 문제, C135333, 임원재

phoneDict = {
    '홍길동':'010-1234-5678',
    '김철수':'010-1234-5679',
    '김영희':'010-1234-5680',
    '최무선':'010-1111-2222'
}

def makePhoneDict(filename, dic):
    infile = open(filename, "w")

    for key, value in dic.items():
        infile.write(f'{key} {value}\n')

def main():
    makePhoneDict("phonebook.txt", phoneDict)
    infile = open("phonebook.txt", "r")
    for line in infile:
        print(line.rstrip())
    infile.close()

main()