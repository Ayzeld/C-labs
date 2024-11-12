s1=0
s2=0
x=int(input("Введите номер билета: "))
if len(str(x))!=6:
    print("Неправильный номер билета")
else:
    for i in range(6):
        if i<3:
            s1+=x%10
        else:
            s2+=x%10
        x=x//10
    if s1==s2:
        print("Счастливый билет")
    else:
        print("Обычный билет")