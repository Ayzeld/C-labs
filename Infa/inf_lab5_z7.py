s=input("Введите номер: ")
if s[0:3].isalpha() and s[3:6].isdigit:
    print("Старый формат")
elif s[0:4].isdigit() and s[4:7].isalpha:
    print("Новый формат")
else:
    print("Нет такого номера")