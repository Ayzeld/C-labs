import random
s = random.sample(range(1, 50), 6)
print(s)
n=[]
for i in range(len(s)-1):
    if s[i+1]> s[i]:
        n.append(s[i+1])
print(n)
