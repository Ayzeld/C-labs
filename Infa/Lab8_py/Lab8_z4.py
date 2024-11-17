import random
s = random.sample(range(1, 100), 6)
print(s)
m=[]
r=[]
p=[]
a=0
for i in range(len(s)):
    a += s[i]
a = a/len(s)
print("Среднее арифметическое: ", a)
for i in range(len(s)):
    if s[i] < a:
        m.append(s[i])
    elif s[i] == a:
        r.append(s[i])
    elif s[i] > a:
        p.append(s[i])
print("Элементы меньше среднего арифметического: ", m)
print("Элементы равные среднему арифметическому: ", r)
print("Элементы больше среднего арифметического: ", p)
