import random

secret = random.randint(1, 10)
print("Хорошо, я загадал число. Попробуй его отгадать")
p=1
while 1:
    print(p,'>',end='')
    num = int(input(' '))
    if num == secret:
        print("Поздравляю! Вы угадали! Хотите сыграть снова?")
        o=str(input("Введите yes или no: "))
        if o=='yes':
            secret = random.randint(1, 10)
            p=1
        else:
            break
    else:
        if secret>num:
            print("Нее, ты не угадал, загаданное число больше. Попробуй снова.")
        else:
            print("Нее, ты не угадал, загаданное число меньше. Попробуй снова.")
        p+=1