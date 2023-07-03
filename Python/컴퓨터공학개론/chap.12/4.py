#4번 문제, C135333, 임원재

def readBinaryOffset(filename, num):
    infile = open(filename, "rb")

    weight = 0
    while True:
        infile.seek(num * weight)
        binary = infile.read(1)
        if not binary:
            break
        print(binary)
        weight += 1

    
def main():
    byteData = bytes(range(11, 100))
    outfile = open("binaryFile.bin", "wb")
    outfile.write(byteData)
    outfile.close()

    readBinaryOffset("binaryFile.bin", 5)

main()