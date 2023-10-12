import numpy as np

a = np.random.random((1000,1000))

for i in range(a.shape[0]):
    for j in range(a.shape[1]):
        a[i,j] **= 2

# a **= 2

print(a)

b = np.random.random((1000,1000))

for i in range(100,1000):
    for j in range(b.shape[1]):
        b[i,j] += 5

# b += 5

print(b)