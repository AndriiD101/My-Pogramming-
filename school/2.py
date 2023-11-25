def sumD (n): 
    sumD = 0
    while n!= 0:
        sumD += n % 10
        n = n // 10
    return sumD 

print (sumD (int(input("n: ")))) 