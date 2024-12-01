import math

def f(x):
  # Ну типа функция наша
  return math.cos(x)

def zvezdec(a, b, n):
  h = (b - a) / n
  integral = 0.5 * (f(a) + f(b))
  for i in range(1, n):
    integral += f(a + i * h)
  return integral * h

a = 0
b = math.pi
n = [10, 100, 1000]
for i in n:
  integral = zvezdec(a, b, i)
  print(f"Приблизительное значение интеграла для N = {i}: {integral}")

