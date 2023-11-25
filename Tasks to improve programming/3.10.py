k = int(input("please write day from 1 to 365: "))
week_days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
#month = ["January", "February", "March", "April", "May", "Juny", "July", "August", "Semptember", "October", "November", "December"]
if 0<k<=365:
    weeks = k//7
    day =k - weeks*7-1
    print("today is", week_days[day],)
else:
    print("out of array")
