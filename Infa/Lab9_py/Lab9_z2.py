from random import choice

def arc():
    # создание матрицы 3 на 3, в которой находятся нули
    a = []
    for i in range(3):
        a.append([0] * 3)
    number = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    for i in range(3):
        for j in range(3):
            a[i][j] = choice(number)
            number.remove(a[i][j])
    return a

# тут надо проверить соответствует ли данная матрица требованием магического квадрата
# если да, то вывести на экран
# если нет, то заново заполнять матрицу
while True:
    x1, x2, x3, y1, y2, y3, d1, d2=0,0,0,0,0,0,0,0
    m=arc()
    x1=sum(m[0])
    x2=sum(m[1])
    x3=sum(m[2])
    for j in range(3):
        d1+=m[j][j]
        y1+=m[j][0]
        y2+=m[j][1]
        y3+=m[j][2]
        d2+=m[j][-(j+1)]
    abc=[x1,x2,x3,d1,y1,y2,y3,d2]
    if abc.count(x1) == 8:
        break

#вывод матрицы на экран
for i in range(3):
    for j in range(3):
        print(m[i][j], end=" ")
    print()
