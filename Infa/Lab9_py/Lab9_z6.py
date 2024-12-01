n = int(input("Введите размер квадратной матрицы: "))
m = [list(map(int, input().split())) for _ in range(n)]

# Меняем местами элементы:
for i in range(n):
    # Меняем элемент главной диагонали (i, i) и побочной диагонали (i, n - 1 - i)
    m[i][i], m[n - 1 - i][i] = m[n - 1 - i][i], m[i][i]
print()
for row in m:
    print(' '.join(map(str, row)))