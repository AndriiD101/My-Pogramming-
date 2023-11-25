a = int(input("a: "))
b = int(input("b: "))
if a<b:
    while (a<=b):
        if a%2!=0:
            print(a)
        a=a+1
else:
    while (b<=a):
        if b%2!=0:
                print(b)
        b=b+1