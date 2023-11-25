V1 = float(input("write any speeed for 1 car: "))
V2 = float(input("write any speeed for 2 car: "))
if V1 > V2:
    s = (V1 - V2) * 0.5
    print(s)
else:
    s = (V2 - V1) * 0.5
    print(s)