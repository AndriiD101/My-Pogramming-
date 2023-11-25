import math
a=float(input("any value for a: "))
b=float(input("any value for b: "))

x = (2/(a**2+25)+b)/(math.sqrt(b)+(a+b)/2)
print(x)
y = (abs(a)+2*math.sin(b))/5.5*a
print(y)
