
month=["січень", "лютий", "березень", "квітень", "травень", "червень", "липень", "серпень", "вересень", "жовтень", "листопад", "грудень"]
rate=[7339.5, 9328.25, 8528.8, 6872.0, 8982.85, 9666.80, 9058.05, 11071.65, 10148.15, 10551.35, 19178.00, 28895.25]

np=int(input("Введіть номер початкового місяця: "))
nk=int(input("Введіть номер кінцевого місяця: "))
z=float(input("Введіть курс, більше якого проводити обчислення: "))

k=0
f=0
for i in range(np, nk+1):
    if rate[i]>z:
        k+=1
        f+=rate[i]
        print(month[i], '-', rate[i], 'dollars')
print(k, "month")
print(f/k, "avarage")