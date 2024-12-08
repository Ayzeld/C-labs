import PySimpleGUI as sg
import random

def degenerator(min_value, max_value):
    return random.randint(min_value, max_value)

sg.theme('Dark Green')
layout = [
    [sg.Image("maxresdefault.png", key="IMAGE")],
    [sg.Text("Введите минимум:"), sg.InputText(key="MIN")],
    [sg.Text("Введите максимум:"), sg.InputText(key="MAX")],
    [sg.Button("Сгенерировать"), sg.Button("Выход")],
    [sg.Text("", key="OUTPUT", size=(30, 1))],
]
window = sg.Window("Генератор случайных чисел", layout)
while True:
    event, values = window.read()
    if event in (sg.WINDOW_CLOSED, "Выход"):
        break

    if event == "Сгенерировать":
        min = int(values["MIN"])
        max = int(values["MAX"])
        if min >= max:
            window["OUTPUT"].update("Ошибка: Минимум должен быть меньше максимума!")
        else:
            r = degenerator(min, max)
            window["OUTPUT"].update(f"Сгенерированное число: {r}")

window.close()
