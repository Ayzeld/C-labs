find = "Academy"
with open(r"C:\Users\Alexey\Downloads\file5.txt", 'r', encoding='utf8') as f:
    contents = f.read()
    if find in contents:
        print(f"Слово '{find}' найдено в файле: file5.txt")
with open(r"C:\Users\Alexey\Downloads\file6.txt", 'r', encoding='utf8') as f:
    contents = f.read()
    if find in contents:
        print(f"Слово '{find}' найдено в файле: file6.txt")
