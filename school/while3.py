a = int(input("a: "))
b = int(input("b: "))
if a<b:
    while (a<=b):
        if a%2==0:
            print(a)
        a=a+1
elif a==b:
    print(0)