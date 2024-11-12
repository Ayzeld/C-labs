array=[]
while True:
    rost=int(input("Введите рост: "))
    if rost>0:
        array.append(rost)
    elif rost<0:
        print("Рост не может быть отрицательным")
    elif rost==0 and len(array)<2:
        print("Недостаточно данных, введите ещё")
    elif rost==0 and len(array)>1:
        break
print("Самый высокий: ", max(array))
print("Самый низкий: ", min(array))

