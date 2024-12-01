import math

n=int(input("Введите количество сокровищ: "))
s=[]
for i in range(n):
    a = list(map(int, input("Введите координаты сокровища: ").split()))
    s.append(a)
san = list(map(int, input("Введите координаты Санька: ").split()))

o = 0
min = float(999)
b=0
for i in range(n):
    o=math.sqrt((san[0]-s[i][0])**2+abs(san[1]-s[i][1])**2) 
    if min>o:
        min=o
        b=i
if b != -1:
    print("Ближайшее сокровище: ", s[b])
else:
    print("Сокровища не найдены")
