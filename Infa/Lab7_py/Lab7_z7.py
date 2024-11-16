import random
import string

ch = ''
p = ''
l = int(input("Введите желаемую длину пароля: "))
upper = input("нужны ли заглавные буквы (да/нет): ")
lower = input("нужны ли строчные буквы (да/нет): ")
digit = input("нужны ли цифры (да/нет): ")
spec = input("нужны ли специальные символы (да/нет): ")

if upper == 'да':
    ch += string.ascii_uppercase
if lower == 'да':
    ch += string.ascii_lowercase
if digit == 'да':
    ch += string.digits
if spec == 'да':
    ch += string.punctuation
if len(ch) < 2:
    print('Не выбраны символы')
    quit()
for i in range(l):
    p += random.choice(ch)
print(p)