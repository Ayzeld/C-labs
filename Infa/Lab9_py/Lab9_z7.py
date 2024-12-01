n = int(input("Введите количество рядов: "))
m = int(input("Введите количество мест в ряду: "))
s = []
print("Введите информацию о занятости мест: ")
for _ in range(n):
    row = list(map(int, input().strip().split()))
    s.append(row)
k = int(input("Введите количество билетов в заказе: "))
result = 0
for i in range(n):
    r = s[i]
    row = ''.join(map(str, r))
    if '0'*k in row:
        result = i + 1
        break
print(result)
