n=[]
m=int(input("enter number: "))
k=int(input("enter number: "))
if m<k:
    for i in range(m, k+1):
        n.append(i)
    print(sum(n))
else:
    print("we cant do this")