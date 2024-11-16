i = input("Введите фразу содержащую чётное количество слов: ")
t=i.split()
n=[]
if len(t)%2 == 0:
    for i in t[::-1]:
        print(t)
        n.append(i)
else:
    print("Ошибка")
print(' '.join(n))