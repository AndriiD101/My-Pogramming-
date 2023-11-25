continent=['Австралія', 'Азія', 'Антарктида', 'Африка', 'Європа', 'Південна Америка', 'Північна Америка']
area=[7687, 43820, 13970, 30300, 10180, 18280, 24250]

for i in range(len(continent)):
      print(continent[i],'—',area[i],'тис. кв. км')
print(min(area)) 
print(max(area))
print(sum(area))
print(sum(area)/len(area))