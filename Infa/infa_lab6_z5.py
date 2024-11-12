n=int(input("Введите возраст собаки: "))
v=float(0)
for i in range(1,n+1):
    if i>2:
        v+=4
    elif 0<i<=2:
        v+=10.5
    else:
        print("ERROR")
print(v)