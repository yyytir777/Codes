#4번 문제, C135333, 임원재

cnt = int(input("1000원권 개수: "))
price = int(input("물건값: "))

cnt_500 = (1000 * cnt - price) // 500
cnt_100 = int(((1000 * cnt - price) % 500) / 100)

print("500원 동전의 개수:", cnt_500)
print("100원 동전의 개수:", cnt_100)