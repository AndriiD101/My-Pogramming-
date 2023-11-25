import math
a = float(input(">>>:"))
b = float(input(">>>:"))
angel = float(input(">>>: "))
ah = (b-a)/2
side = ah/math.cos(angel)
h = math.sqrt(side**2-ah**2)
s = (a+b)/2*h
print(a)
