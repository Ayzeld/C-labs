import random
count = 0
n=[]
i=0
a=0
while count < 3:
    s = random.choice('РО')
    n.append(s)
    i+=1
    if (a == s) or (a == 0):
        count+=1
    else:
        count=1
    a = s
print(i)
print(n)
