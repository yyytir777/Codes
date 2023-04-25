print("hello world")

x = int(input("첫 번째 정수: ")) #사용자가 3을 입력했다고 가정
y = int(input("두 번째 정수: ")) #사용자가 4을 입력했다고 가정

sum = x + y
print("합은 ", sum)

s1 = sum // 3
s2 = sum%3
s3 = sum / 3
print(s1)
print(s2)
print(s3)


sum += 1 
print(sum)


sum = sum**2 + sum *2
print(sum)

age1 = 10
age2 = 20

sumage = age1 + age2
print(sumage)


age3 = '10'
age4 = '20'

sumage = age3+age4
print(sumage)

a = "Student"+26 #무슨 오류를 발생시키는가?#
b = 'hongik university'
print(b[3])

list1 = ['messi','xabi','andres']
print(list1[1])

v = 1
v = t
v = 2
print(t)

a = 12
b = 13

if a > b :
    a += 1
else:
    b += 1
print (a)

if 0 : 
    a = 'hello'
else: 
    a = 'bye'
print(a)

if [] : 
    a = 'hello'
else: 
    a = 'bye'
print(a)

if not'asc' : 
    a = 'hello'
else: 
    a = 'bye'
print(a)

match a :
    case 'hello':
        a = 'hawai'
    case 'bye':
        a = 'paris'
a = 0
for x in range(5) : 
    a += 1
print(a)
a = ['h','e','l','l']
for x in a:
    print(x) # 반복문이 모두 반복되었을 때의 결과를 적으시오

#여기부터는 손코딩 말고 주관식 문제들
# 다음 바이트 10111101을 10진수로 바꾸었을 때의 수를 적으시오.
# 프로그래밍 언어에 해당하는 3가지 언어를 말하시오
# 프로그래밍 언어를 기계어로 바꾸어주는 역할을 무엇이 하는가?
# 파이썬에서 가장 크게 범하는 오류 3가지를 말하시오 / 작년 기출


# ox 문제
# 기계어는 0과 1로 구성된다
# n =3 이라는 명령문은 실제론 변수 n 에 int 객체 3의 참조값을 저장하는 것이다.
# 모든 데이터가 객체이진 않다.
# 각 객체는 id와 type을 갖는다

# 주관식 문제 예시중 하나
# 다음 반복문은 'hello'를 10번 print하는 반복문이다.
# 아래 반복문에서 잘못된 지점을 지적하고 고쳐보아라

for i in range(0,10,1):
    print('hello')

# 다음 반복문은 팩토리얼을 값을 구하는 소스코드이다.
# 아래 소스코드에서 빈 부분을 채워넣어라(조건문을 활용할 것)

x = int(input("구하고자 하는 팩토리얼 값을 입력하시오:"))
while True:

# 다음 반복문은 팩토리얼을 값을 구하는 소스코드이다.
# 아래 소스코드에서 빈 부분을 채워넣어라(조건문을 활용할 것)
