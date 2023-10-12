punctuations = "!()-[]{};:\\,<>./?@#$%^&*_~"

def remove_puntutions(string1):
    result = ""
    for char in string1:
        if char not in punctuations:
            result += char
    return result


string1 = "aFDF#^&$%SFSDsd^~#+gsd2@#%"
print(remove_puntutions(string1))