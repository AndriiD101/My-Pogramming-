a = int(input("input number: "))
tens = a//10
ones = a%10
if tens > ones:
    print(f"{tens} more then {ones}")
elif tens < ones:
    print(f"{tens} less then {ones}")
else:
    print(f"{ones} equal {tens}")