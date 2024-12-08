import PySimpleGUI as sg
def calculate(num):
    if not (-128 <= num <= 127):
        return "Число должно быть в диапазоне от -128 до 127"
    a = 2 if num >= 0 else 3
    b = (bin(num))[a:].zfill(8)
    if a == 3:
        dir = '1' + b[1:]
    else:
        dir = b
    rev = ''
    for bit in dir:
        if bit == '0':
            rev += '1'
        else:
            rev += '0'
    if a == 3:
        rev = '1' + rev[1:]
    else:
        rev = '0' + rev[1:]
    if rev[-1] == 0:
        dop = rev[:-1] + '1'
    else:
        i = rev.rfind('0')
        if i != -1:
            dop = rev[:i] + '1' + rev[i + 1:]
        else:
            dop = '10000000'

    return f"""Прямой код: {dir} 
Обратный код: {rev} 
Дополнительный код: {dop}"""

layout = [
    [sg.Text("Введите целое число (от -128 до 127):")],
    [sg.Input(key='-INPUT-')],
    [sg.Button("Вычислить"), sg.Button("Выход")],
    [sg.Output(size=(50, 5), key='-OUTPUT-')]
]

window = sg.Window("Перевод", layout)

while True:
    event, values = window.read()
    if event == sg.WIN_CLOSED or event == "Выход":
        break
    if event == "Вычислить":
        res = calculate(int(values['-INPUT-']))
        window["-OUTPUT-"].update(res)

window.close()
