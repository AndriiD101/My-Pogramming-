V = float(input("speed of spacecraft: "))
if V < 7.8:
    print("will fall down on Earth")
elif 7.8 <= V < 11.2:
    print("will be a satellite")
elif 11.2<=V<16.4:
    print("will be a satellite of Sun")
else:
    print("will leave the solar system")
