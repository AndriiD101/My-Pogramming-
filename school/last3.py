month=["січень", "лютий", "березень", "квітень", "травень", "червень", "липень", "серпень", "вересень", "жовтень", "листопад", "грудень"]
rate=[7339.5, 9328.25, 8528.8, 6872.0, 8982.85, 9666.80, 9058.05, 11071.65, 10148.15, 10551.35, 19178.00, 28895.25]
k=0
f=0
for i in range(len(rate)):
    if rate[i]>9000:
        k+=1
        f+=rate[i]
        print(month[i], '-', rate[i], 'dollars')
print(k, "month")
print(f/k, "avarage")
