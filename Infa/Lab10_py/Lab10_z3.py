with open(r"C:\Users\Alexey\Downloads\file6.txt", 'r', encoding='utf8') as f:
    c = f.read()
    words = c.split()
    s = len(words)
    e = sum(1 for word in words if 'e' in word.lower())
    if s > 0:
        p = (e / s) * 100
print(f"Количество слов с буквой 'e' в тексте: '{e}', это '{p}'% от всех слов")