num = 407

def isPrime(n):
    if(n == 0 or n == 1):
        print(f"{n} is not Prime number")
        return

    for i in range(2, n):
        if(n % i) == 0:
            print(f"{n} is not Prime number")
            return
    print(f"{n} is Prime number")

isPrime(num)