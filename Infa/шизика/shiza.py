import numpy as np
import matplotlib.pyplot as plt

omega = 5000  # угловая частота
T = 2 * np.pi / omega  # период
q_max = 1.0e-6  # максимальный заряд
t = np.linspace(0, 2 * T, 1000)
E = -q_max * omega**2 * np.cos(omega * t)  # ЭДС

plt.figure(figsize=(8, 5))
plt.plot(t, E, label="ЭДС $\mathcal{E}(t)$", color="red")
plt.axhline(0, color="black", linewidth=0.8, linestyle="--")  # Линия y=0
plt.title("График ЭДС в колебательном контуре")
plt.xlabel("Время $t$, с")
plt.ylabel("ЭДС $\mathcal{E}(t)$, В")
plt.xlim(0, 2 * T)
plt.legend()
plt.grid()
plt.show()
