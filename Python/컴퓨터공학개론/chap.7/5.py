def is_palindrome(s):
    n = len(s)
    for i in range(n // 2):
        if s[i] != s[n - i - 1]:
            return False
    return True

length = int(input("문자열의 길이를 입력하시오: "))
alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

count = 0

for i in range(26**length):
    string = ''
    for j in range(length, 0, -1):
        if j == 1:
            #i를 26으로 나눈 나머지
            string += alphabet[i % 26]
        else:
            #j가 증가할때마다 i를 26의 j-1제곱으로 나눠 자릿수를 설정하고,
            #이를 26으로 나눈 나머지를 사용하여 'a'~'z'를 순회하여 string에 더하도록 함
            string += alphabet[i // (26 ** (j-1)) % 26]
    if is_palindrome(string):
        count += 1

print(f"전체 가능한 소문자 알파벳 문자열 {26**length}개 중 회문의 개수는 {count}개입니다.")