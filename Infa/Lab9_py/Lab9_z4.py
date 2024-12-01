menu = [["Пицца Маргарита", ["мука", "томаты", "сыр", "базилик"], 10],
    ["Салат Цезарь", ["салат", "курица", "сыр", "сухарики"], 8],
    ["Суп Томатный", ["томаты", "лук", "морковь", "картофель"], 6]]

def view():
    print("Меню:")
    for dish in menu:
        print(f"- {dish[0]}: {dish[2]}$")

def find(dish_name):
    for dish in menu:
        if dish[0] == dish_name:
            print(f"{dish[0]}: Ингредиенты: {', '.join(dish[1])}, Цена: {dish[2]}$")
            return
    print("Блюдо не найдено!")

def add():
    name = input("Введите название нового блюда: ")
    ingredients = input("Введите ингредиенты через запятую: ").split(", ")
    price = float(input("Введите цену блюда: "))
    menu.append([name, ingredients, price])

def change():
    dish_name = input("Введите название блюда для изменения цены: ")
    new_price = int(input("Введите новую цену: "))
    for dish in menu:
        if dish[0] == dish_name:
            dish[2] = new_price
            print(f"Цена блюда '{dish_name}' изменена на {new_price}$!")
            return
    print("Не найдено!")

while True:
    print("Меню действий:")
    print("1 - Показать меню")
    print("2 - Найти блюдо")
    print("3 - Добавить новое блюдо")
    print("4 - Изменить цену блюда")
    print("5 - Выход")
    choice = input("Выберите действие (1-5): ")
    
    match choice:
        case '1':
            view()
        case '2':
            dish_name = input("Введите название блюда: ")
            find(dish_name)
        case '3':
            add()
        case '4':
            change()
        case '5':
            break
        case _:
            print("Неверный выбор, попробуйте еще раз.")