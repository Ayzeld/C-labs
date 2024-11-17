import random
s = random.sample(range(1, 230), 6)
s.sort(reverse=1)
a = int(input("Введите рост Андрея: "))
count=1
print(s)
for i in range(len(s)):
    if s[i] >= a:
        count += 1
print(count)

