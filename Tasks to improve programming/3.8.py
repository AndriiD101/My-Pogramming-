#AB01643
print("Write your ticket in example AB00000")
ticket = int(input("Please write your serial number of ticket AB"))
if 1<= ticket <= 300:
    row = (ticket - 1644) // 15 + 1
    print(row)
else:
    print("someting went wrong, try again")