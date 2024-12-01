def insert_line_into_file(file_path, new_line):
    with open(file_path, 'r', encoding='utf-8') as f:
        l = f.readlines()
    i = len(l) // 2
    l.insert(i, new + '\n')
    with open(file_path, 'w', encoding='utf-8') as f:
        f.writelines(l)

path = r"C:\Users\Alexey\Downloads\file7.txt"
new = input("Введите строку для добавления: ")
insert_line_into_file(path, new)
print("Строка добавлена")

