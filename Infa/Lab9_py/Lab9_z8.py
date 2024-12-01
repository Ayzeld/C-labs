n = int(input("Введите количество строк n: "))
m = int(input("Введите количество столбцов m: "))
A = [[0] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if i == 0 or j == 0:
            A[i][j] = 1 
        else:
            A[i][j] = A[i-1][j] + A[i][j-1]

for row in A:
    for elem in row:
        print(f"{elem:6}", end='') 
    print() 
