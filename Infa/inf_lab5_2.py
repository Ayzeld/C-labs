a=int(input("Введите значение: "))
b=str(input("Введите единицу измерения: "))
if b == "C":
    print(float(a*1.8+32))
else: print (float((a-32)/1.8))  