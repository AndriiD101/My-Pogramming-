a = int(input("side of the square: "))
b = int(input("width rectangle: "))
c = int(input("height rectangle: "))

S_P = c * b
S_SQ = a * a

if S_P<S_SQ:
    print("square's area is begger than rectangle's area")
else:
    print("rectangle's area is begger than square's area")

P_P = 2 * (c + b)
P_SQ = 4 * a

if P_P< P_SQ:
    print("square's perimeter is bigger than rectangle's perimeter")
else:
    print("rectangle's perimeter is bigger than square's perimeter")