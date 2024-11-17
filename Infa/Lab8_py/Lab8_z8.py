def short(word):
    if len(word) > 10:
        return f"{word[0]}{len(word) - 2}{word[-1]}"
    return word

n = int(input("Введите количество слов: "))
r = []
for _ in range(n):
    word = input()
    r.append(short(word))
for a in r:
    print(a)
