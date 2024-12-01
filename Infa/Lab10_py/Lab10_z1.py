max = 0
winner = ""
p = 0
with open(r"C:\Users\Alexey\Downloads\file4.txt", 'r', encoding='utf8') as f:
    for l in f:
        a = l.split()
        if int(a[-1]) > max:
            p = max
            winner = a[0] + " " + a[1]
            max = int(a[-1])
        if p < int(a[-1]) < max:
            p = int(a[-1])
            pwinner = a[0] + " " + a[1]
print(f"Победитель: {pwinner} (Набранное количество баллов: {p})")
