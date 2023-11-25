V1 = float(input("write any speeed for 1 car: "))
V2 = float(input("write any speeed for 2 car: "))
S = int(input("write distanse between cars: "))

T = S / (V1 + V2)
print(f"time when cars will meet: {T}")