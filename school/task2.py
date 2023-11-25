import math
x = int(input("value for x: "))
if x<-5:
    y=x**2+4*x
    print(y)
elif -5<=x<0:
    y=abs(x)
    print(y)
elif 0<=x<4:
    y=1+math.sqrt(x)
    print(y)
else:
    y=x-1
    print(y)