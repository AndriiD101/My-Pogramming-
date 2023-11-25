import math
x = int(input("x: "))
if math.sin(x)>=0:
    k=x**2
else:
    k=abs(x)

if k<x:
    f=abs(x)
    print(f)
else:
    f=k*x
    print(f)