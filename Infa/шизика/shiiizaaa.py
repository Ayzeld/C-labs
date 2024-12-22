import numpy as np
import matplotlib.pyplot as plt

# Параметры
b = 1  # коэффициент демпфирования
omega = 5  # угловая частота
A = 1  # амплитуда
phi = 0  # начальная фаза

t = np.linspace(0, 10, 1000)
x = A * np.exp(-b * t / 2) * np.cos(omega * t + phi)

plt.figure(figsize=(10, 6))
plt.plot(t, x, label='Амплитуда колебаний', color='blue')
plt.title('График колебаний пружинного маятника')
plt.xlabel('Время (с)')
plt.ylabel('Смещение (м)')
plt.axhline(0, color='black', lw=0.5, ls='--')
plt.axvline(0, color='black', lw=0.5, ls='--')
plt.grid()
plt.legend()
plt.show()
