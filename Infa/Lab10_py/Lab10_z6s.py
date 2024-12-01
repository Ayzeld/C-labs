def encrypt_file(path):
    with open(path, 'r', encoding='utf-8') as f:
        l = f.readlines()
    lines = []
    for line in lines:
        words = line.strip().split()
        desh = [word[::-1] for word in words] 
        lines.append(' '.join(desh))
    with open(path, 'w', encoding='utf-8') as f:
        f.write('\n'.join(lines))

path = r"C:\Users\Alexey\Downloads\file7.txt"
encrypt_file(path)
print(f"Файл '{path}' зашифрован")