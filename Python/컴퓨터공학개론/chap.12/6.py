#6번 문제, C135333, 임원재

import random

def randomErrorGenerator():
    exceptionList = [FileNotFoundError("Error I"), TypeError("Error  II"), ZeroDivisionError("Error III"), NameError("Error IV")]
    errorIndex = random.randint(0,3)
    raise exceptionList[errorIndex]

def main():
    try:
        randomErrorGenerator()
    except FileNotFoundError:
        print("FileNotFoundError")
        print("Error I")
    except TypeError:
        print("TypeError")
        print("Error  II")
    except ZeroDivisionError:
        print("ZeroDivisionError")
        print("Error III")
    except NameError:
        print("NameError")
        print("Error IV")

main()