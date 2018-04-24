import matplotlib.pyplot as plt
import numpy as np

datos = np.loadtxt("datos.txt")
plt.figure()
plt.plot(datos[:,0], datos[:,1], label="Difusion")
plt.plot(datos[:,0], datos[:,2], label="Inicial")
plt.title("Evolucion de la ecuacion diferencial")
plt.legend()
plt.xlabel("x")
plt.ylabel("u")
plt.savefig("violeta.pdf")
