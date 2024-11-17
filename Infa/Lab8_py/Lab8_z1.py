data = []
while 1:
    a = input("Введите элемент массива данных (Пропустите ввод чтобы закончить): ")
    if a == "":
        break
    data.append(a)

l = []
n = []
for item in data:
    if item.isdigit():
        n.append(item)
    else:
        l.append(item)
del data

print("Буквы:", l)
print("Цифры:", n)
