t = "Довольно распространённая ошибка ошибка это лишний повтор повтор слова слова Смешно не не правда ли Не нужно портить хор хоровод"
t = t.split()
words = []
for word in t:
    if word not in words:
        words.append(word)
res = ' '.join(words)  
print(res)
