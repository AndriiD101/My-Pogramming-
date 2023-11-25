n = int(input("write three-digit number: "))
first_digit = n // 100
second_digit = (n//10)%10
third_digit = n%10
if first_digit == third_digit:
    print(f"your number {n} is polindrom")
else:
    print("it isnt polindrom")