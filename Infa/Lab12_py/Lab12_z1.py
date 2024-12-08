a=int(input("Введите количество членов экипажа: "))
f=[]
s=[]
t=[]
for i in range(a):
    name, status=(input("Введите имя и статус члена экипажа: ").split( ))
    match status:
        case "women"|"child":
            f.append(name)
        case "man":
            s.append(name)
        case "captain":
            t.append(name)
n=f+s+t
print(" ".join(n))
