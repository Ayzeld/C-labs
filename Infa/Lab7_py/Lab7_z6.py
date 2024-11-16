sms=input("Введите зашифрованное сообщение: ")
if sms[-1] != '#':
    print("Это не зашифрованное сообщение")
    exit()
ch=[]
n=[]
sms=sms.replace('#','')
print(sms)
s=len(sms)
for i in range(s):
    if i%2==0:
        ch.append(sms[i])
    else:
        n.append(sms[i])
b=n[::-1]
a=ch+b
print(a)
d = ''.join(a)
print("Расшифрованное сообщение:", d)
