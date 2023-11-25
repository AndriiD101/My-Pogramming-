flat = int(input("input flats number from 1 to 15: "))
if 0 < flat < 16:
    floor = (flat - 1) // 3 + 1
    print(f"your flat is {flat}. It is on {floor} floor")
else:
    print("Unappropriet number")