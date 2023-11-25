import math
A=[]
B=[]
for i in range(2):
    f = float(input(">>>: "))
    A.append(f)
    print(A)

for i in range(2):
    f = float(input(">>>: "))
    B.append(f)
    print(B)
distance = math.sqrt((B[0]-A[0])**2+(B[1]-A[1])**2)
print(distance)
