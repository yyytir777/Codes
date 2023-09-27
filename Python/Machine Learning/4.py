dec = 15

def DecToBi(n):
    num = n
    result = ""
    while num:
        if(num % 2) == 0:
            result = "0" + result
        else:
            result = "1" + result
            num -= 1
        num /= 2
    return print("%d -> %s" %(n, result))

def DecToOc(n):
    num = n
    result = ""
    while num:
        tmp = int(num  % 8)
        if tmp == 0:
            result = "0" + result
        else:
            result = str(tmp) + result
            num -= tmp
        num /= 8

    return print("%d -> %s" %(n, result))

def DecToHex(n):
    num = n
    result = ""
    while num:
        tmp = int(num % 16)
        if tmp == 0:
            result = "0" + result
        else:
            if tmp == 10:
                result = "A" + result
            elif tmp == 11:
                result = "B" + result
            elif tmp == 12:
                result = "C" + result
            elif tmp == 13:
                result = "D" + result
            elif tmp == 14:
                result = "E" + result
            elif tmp == 15:
                result = "F" + result
            else:
                result = str(tmp) + result
            num -= tmp
        num /= 16

    return print("%d -> %s" %(n, result))

DecToBi(dec)
DecToOc(dec)
DecToHex(dec)