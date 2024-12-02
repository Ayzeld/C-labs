import random

def generate(word_list):
    filtered_words = [word for word in word_list if len(word) >= 3]
    
    if len(filtered_words) < 2:
        raise ValueError("Недостаточно подходящих слов для генерации пароля.")
    word1, word2 = random.sample(filtered_words, 2)
    password = f"{word1.capitalize()}{word2.capitalize()}"
    if len(password) < 8 or len(password) < 10:
        raise ValueError("Сгенерированный пароль не соответствует требованиям по длине.")
    return password

file_path = r"C:\Users\Alexey\Downloads\file6.txt"
#невдуплейшн
try:
    with open(file_path, 'r', encoding='utf-8') as file:
        words = [line.strip() for line in file.readlines()]
    password = generate(words)
    print(f"Сгенерированный пароль: {password}")
except FileNotFoundError:
    print(f"Файл '{file_path}' не найден.")
except ValueError as e:
    print(e)
