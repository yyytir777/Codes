import numpy as np

a = np.random.random((3,4))
print("Generate 3x4 numpy array with random numbers")
print(a)

print("\nselect the 0th and 2nd rows")
print(a[np.array([0,2]), :])

print("\nselect the 2nd row and the 1th through the 2nd elements")
print(a[np.array([0,2]), :2])

print("\n boolean operations to set True to the numbers > 0.5")
print(a[a > 0.5])