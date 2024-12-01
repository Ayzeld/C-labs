n, m = map(int, input("Введите размер матрицы: ").split())
b = [list(map(int, input("Введите элементы матрицы: ").split())) for _ in range(n)]
t = [[0] * n for _ in range(m)]
for i in range(n):
    for j in range(m):
        t[j][i] = b[i][j]
for row in t:
    print(' '.join(map(str, row)))