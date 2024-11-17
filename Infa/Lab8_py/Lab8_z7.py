b=input("Введите номер вашей карты (и 3 цифры с задней стороны): ")
if len(b) != 16:
    print("Неправильный номер")
    quit()
a=[]
for i in b:
    a.append(int(i))
s=0
for i in range(0, len(a)):
    if i%2 == 1:
        s+=a[i]
    else:
        n = a[i]*2
        if n > 9:
            n-=9
        s += n
if s%10 == 0:
    print("Правильный номер")
else:
    print("Неправильный номер")