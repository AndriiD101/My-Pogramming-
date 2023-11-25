n = int(input("enter amount of seconds within day: "))
if 0<n<86400:
    full_hours_in_day = n // 3600
    print(f"from begining of day passed {full_hours_in_day} hours")
    m_b = full_hours_in_day * 60
    minuts = n//60 - m_b
    print(f"{minuts} minuts")
    sec =(n - (full_hours_in_day * 3600)) - minuts * 60
    print(sec, "seconds")
    print(f"time now is {full_hours_in_day} hours {minuts} minuts {sec} seconds")
else:
    print("i dont work with this value")    