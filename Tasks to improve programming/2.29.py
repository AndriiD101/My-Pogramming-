import math
A=[]
B=[]
C=[]
for i in range(2):
    f = float(input(">>>: "))
    A.append(f)
    print(A)

for i in range(2):
    f = float(input(">>>: "))
    B.append(f)
    print(B)

for i in range(2):
    f = float(input(">>>: "))
    C.append(f)
    print(C)

distanceAB = math.sqrt((B[0]-A[0])**2+(B[1]-A[1])**2)
distanceBC = math.sqrt((B[0]-C[0])**2+(B[1]-C[1])**2)
distanceAC = math.sqrt((A[0]-C[0])**2+(A[1]-C[1])**2)
P=distanceAB+distanceBC+distanceAC
p=P/2
S=math.sqrt(p*(p-distanceAB)*(p-distanceBC)*(p-distanceAC))
print(P, S)
