km=float(input("past the lenth in kilometr: "))
foot = float(input("past the lenth in foots: ")) * 0.3048
if km<foot:
    print(km, "<", foot)
else:
    print(km, ">", foot)