def max(num1, num2):
    if num1 > num2:
        return num1
    else:
        return num2
    
def main():
    i = 5
    j = 2
    k = max(i, j)
    print("큰 수 = %d" %max(i, j))

main()