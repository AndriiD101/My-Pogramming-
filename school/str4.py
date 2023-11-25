slovo=input("Введіть слово")
new = slovo[::-1]
k=0
for nomer in range(len(slovo)):
    if slovo[nomer]==new[nomer]:
        k=k+1
print(k)
