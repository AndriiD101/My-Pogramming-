import math
b=float(input("smallest basis: "))
a=float(input("bigger basis: "))
c=float(input("height of trapeze: "))
b2=a-b
print(b2)

x=b2/2
print(x)

k=math.sqrt(x**2+c**2)
print(k)

p=k*2+b+a
print(p)
