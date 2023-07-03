#2번 문제, C135333, 임원재

phoneDict = {
    '길동수':'011-1234-5878',
    '강철한':'017-1234-3679',
    '고영희':'010-1134-6680'
}

def appendPhoneDict(filename, dic):
    infile = open(filename, "a")

    for key, value in dic.items():
        infile.write(f'{key} {value}\n')



def main():
    appendPhoneDict("phonebook.txt", phoneDict)
    infile = open("phonebook.txt", "r")
    for line in infile:
        print(line.rstrip())
    infile.close()
main()