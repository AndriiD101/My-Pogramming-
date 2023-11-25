n = int(input("enter value: "))
m = int(input("enter value: "))
s =0
for i in range(n, m+1):
    if i%2==0:
        s=s+i
print(s)