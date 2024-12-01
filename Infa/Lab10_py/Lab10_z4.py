
def load_names(path):
    names = []
    with open(path, 'r', encoding='utf-8') as file:
        for line in file:
            name, p = line.strip().split()
            names.append((name, float(p)))
    return names

def get_top_names(names, n):
    return sorted(names, key=lambda x: x[1], reverse=True)[:n]

gender = input("Введите 'м' или 'ж' для выбора: ").strip().lower()
n = int(input("Введите количество которые нужно вывести: "))
if gender == 'м':
    names = load_names(r"C:\Users\Alexey\Downloads\file7.txt")
elif gender == 'ж':
    names = load_names(r"C:\Users\Alexey\Downloads\file8.txt")
top = get_top_names(names, n)
print(f"Топ {n} популярных {gender} имен: ")
for name in top:
    print(f"{name}")

