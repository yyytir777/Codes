import numpy as np

x = np.random.random((3,4))
y = np.random.random((3,1))
z = np.random.random((1,4))
w = np.random.random((3,))

print(x+y)
print(x*z)
print(y+y.T)
# print(x+w) : 오류
print(y+w)