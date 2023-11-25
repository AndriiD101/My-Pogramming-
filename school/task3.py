#a*x**2+b*x+c=0
import math
a=int(input("value for a: "))
b=int(input("value for b: "))
c=int(input("value for c: "))
D = b**2-4*a*c
print(D)
if D > 0:
    x1 = (-b+math.sqrt(D))/2*a
    x2 = (-b-math.sqrt(D))/2*a
    print(x1, x2)
elif D == 0:
    x = -b/(2*a)
    print(x)
else:
    print("there is no solution")