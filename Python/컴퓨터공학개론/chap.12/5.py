#5번 문제, C135333, 임원재

def isFile(name):
    try:
        file = open(name, "r")
    except FileNotFoundError:
        return False
    return True

def main():
    fname = input("파일 이름? ")
    if isFile(fname):
        print(f'File {fname} exists')
    else:
        print(f'File {fname} does not exists')

main()