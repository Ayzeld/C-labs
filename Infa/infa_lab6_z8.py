n=str(input("Введите двоичное число: "))
s=0
print(len(n))
for i in range(len(n)-1,-1,-1):
    print(i)
    s=s+int(n[i])*(2**(len(n)-1-i))
print(s)
