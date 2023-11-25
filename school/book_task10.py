a=int(input("write number a: "))
b=int(input("write number b: "))
c=int(input("write number c: "))

if a > b > c:
    print(a*b)
elif c > a > b:
    print(c*a)
elif c > b > a:
    print(c*b)