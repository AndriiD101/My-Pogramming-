a=int(input("write number: "))
c = a // 10
d = a % 10
if d == 5 and c == 7:
    print("5 and 7 is in your number")
elif d == 7 and c == 5:
    print("5 or 7 is in your number")
elif d == 5 or c == 5:
    print("5 is your numder")
elif d == 7 or c == 7:
    print("7 is in your number")
else:
    print("5 or 7 isnt in your number")