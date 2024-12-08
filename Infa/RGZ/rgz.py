import PySimpleGUI as sg
import random

sg.theme('Dark Green')
choices = ["Бумага", "Ножницы", "Камень"]
images = {c: f"{c}.png" for c in choices}

def round(player):
    comp = random.choice(choices)
    if player == comp:
        return "Ничья", comp
    if (player == "Камень" and comp == "Ножницы") or \
       (player == "Ножницы" and comp == "Бумага") or \
       (player == "Бумага" and comp == "Камень"): return "Победа", comp
    return "Поражение", comp

layout = [
    [sg.Text("Имя игрока:")], [sg.Input(key='-NAME-')],
    [sg.Text("Раундов:")], [sg.Input(key='-ROUNDS-', default_text="5")],
    [sg.Button("Играть"), sg.Button("Выход")],
    [sg.Image(key='-PLAYER-', size=(70, 70)), sg.Text("Игрок:", justification='r'), sg.Text(key='-PLAYER_SCORE-', size=(10,1), justification='l'),
     sg.Image(key='-COMPUTER-', size=(70, 70)), sg.Text("Компьютер:", justification='r'), sg.Text(key='-COMP_SCORE-', size=(10,1), justification='l')],
    [sg.Column([[sg.Button(image_filename=images[c], key=c, pad=(5, 5), size=(70, 70)) for c in choices]], justification="center")]
]

window = sg.Window("Камень-Ножницы-Бумага", layout)
pl_score, comp_score = 0, 0

while True:
    event, values = window.read()
    if event in (sg.WIN_CLOSED, "Выход"):
        break
    if event == "Играть":
        try:
            rounds = int(values['-ROUNDS-'])
            if rounds <= 0:
                raise ValueError
            for _ in range(rounds):
                pl_choice = None
                while pl_choice is None:
                    event, values = window.read()
                    if event in choices:
                        pl_choice = event
                    res, comp_choice = round(pl_choice)
                    window['-PLAYER-'].update(images[pl_choice])
                    window['-COMPUTER-'].update(images[comp_choice])
                    print(f"Игрок: {pl_choice}, Компьютер: {comp_choice}, Результат: {res}")
                    if res == "Победа":
                        pl_score += 1
                    elif res == "Поражение":
                        comp_score += 1
                    window['-PLAYER_SCORE-'].update(pl_score)
                    window['-COMP_SCORE-'].update(comp_score)
        except ValueError: print("Неверное кол-во раундов")
window.close()
