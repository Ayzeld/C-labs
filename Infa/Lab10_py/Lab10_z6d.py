def decrypt(path):
    with open(path, 'r', encoding='utf-8') as file:
        l = file.readlines()
    lines = []
    for line in l:
        words = line.strip().split()
        words = [word[::-1] for word in words]
        lines.append(' '.join(words))
    return '\n'.join(lines)

path = r"C:\Users\Alexey\Downloads\file7.txt"
message = decrypt(path)
print("Расшифрованное сообщение: ")
print(message)