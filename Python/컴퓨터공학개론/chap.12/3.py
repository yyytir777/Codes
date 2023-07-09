#3번 문제, C135333, 임원재

def convertEncoding(filename, encode):
    infile = open(filename, "r")
    text = infile.read()

    outfile = open(filename, "w", encoding= encode)
    outfile.write(text)

def main():
    convertEncoding("phonebook.txt", 'utf8')
    infile = open("phonebook.txt", "r", encoding='utf8')
    for line in infile:
        print(line.rstrip())
    infile.close()

main()