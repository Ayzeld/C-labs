n = int(input("Введите количество комнат, а затем вводите кол-во проживающих и максимальную вместимость для каждой комнаты: "))
count = 0
for i in range(n):
    p, max = map(int, input().split())
    if p + 2 <= max:
        count += 1
print(count)

