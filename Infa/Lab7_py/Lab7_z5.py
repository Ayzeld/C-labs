def search(a):
    l="аиоеёыуяэюАОУЭЫЯЮЕЁИ"
    count=0
    for i in l:
        count+=a.count(i)
    return count
n=input("Введите текст разделённый по строкам с помощью '/': ")
t=n.split('/')
s=0
if len(t) != 3:
    print("Обычный текст")
    exit()
print(t)
if search(t[0])==5:
    s+=1
if search(t[1])==7:
    s+=1
if search(t[2])==5:
    s+=1
if s==3:
    print("Хойку!")
else:
    print("Не хойку")