import math
import matplotlib.pyplot as plt
from sklearn.metrics import r2_score

def rk2_sin_iteration(start_x, start_y, start_y_derivative, step, number_of_iterations):
    x_values = [start_x]
    y_values = [start_y]
    y_derivative_values = [start_y_derivative]
    real_values = [0]
    
    for _ in range(number_of_iterations):
        last_x = x_values[-1]
        y1 = y_values[-1]
        y2 = y_derivative_values[-1]

        # k1
        k1_y1 = y2
        k1_y2 = -y1

        # k2
        k2_y1 = y2 + step * k1_y2
        k2_y2 = -(y1 + step * k1_y1)

        next_y1 = y1 + (step / 2) * (k1_y1 + k2_y1)
        next_y2 = y2 + (step / 2) * (k1_y2 + k2_y2)

        x_values.append(last_x + step)
        y_values.append(next_y1)
        y_derivative_values.append(next_y2)
        real_values.append(math.sin(last_x + step))

    return x_values, y_values, real_values

def rk4_sin_iteration(start_x, start_y, start_y_derivative, step, number_of_iterations):
    x_values = [start_x]
    y_values = [start_y]
    y_derivative_values = [start_y_derivative]
    real_values = [0]
    
    for _ in range(number_of_iterations):
        last_x = x_values[-1]
        y1 = y_values[-1]
        y2 = y_derivative_values[-1]

        # k1
        k1_y1 = y2
        k1_y2 = -y1

        # k2
        k2_y1 = y2 + 0.5 * step * k1_y2
        k2_y2 = -(y1 + 0.5 * step * k1_y1)

        # k3
        k3_y1 = y2 + 0.5 * step * k2_y2
        k3_y2 = -(y1 + 0.5 * step * k2_y1)

        # k4
        k4_y1 = y2 + step * k3_y2
        k4_y2 = -(y1 + step * k3_y1)

        next_y1 = y1 + (step / 6) * (k1_y1 + 2*k2_y1 + 2*k3_y1 + k4_y1)
        next_y2 = y2 + (step / 6) * (k1_y2 + 2*k2_y2 + 2*k3_y2 + k4_y2)

        x_values.append(last_x + step)
        y_values.append(next_y1)
        y_derivative_values.append(next_y2)
        real_values.append(math.sin(last_x + step))

    return x_values, y_values, real_values

r2s = []
r2s_rk2 = []

STEPS = [0.5, 0.25, 0.125, 0.125/2, 0.125/4, 0.125/8, 0.125/16, 0.125/32]

for step in STEPS:
    START_X, START_Y, START_Y_DERIVATIVE = 0, 0, 1

    # RK4
    x_values, y_values, real_values = rk4_sin_iteration(START_X, START_Y, START_Y_DERIVATIVE, step, 50_000)
    r2 = r2_score(real_values, y_values)
    f = math.ceil((3.15 * 4) / step)
    r2s.append(max(r2, 0))
    plt.figure(figsize=(10,5))
    plt.plot(x_values[:f], y_values[:f], label="Aproximação (Runge-Kutta ordem 4)", marker="o", markersize=3)
    plt.plot(x_values[:f], real_values[:f], label="Seno real", linestyle="--")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title(f"Aproximação do seno via Método de Runge-Kutta (ordem 4) com h de {step} com R² de {r2}")
    plt.legend()
    plt.grid(True)
    plt.savefig(f"rk4-out-{step}.png")

    # RK2
    x_values2, y_values2, real_values2 = rk2_sin_iteration(START_X, START_Y, START_Y_DERIVATIVE, step, 50_000)
    r2_rk2 = r2_score(real_values2, y_values2)
    r2s_rk2.append(max(r2_rk2, 0))
    plt.figure(figsize=(10,5))
    plt.plot(x_values2[:f], y_values2[:f], label="Aproximação (Runge-Kutta ordem 2)", marker="o", markersize=3)
    plt.plot(x_values2[:f], real_values2[:f], label="Seno real", linestyle="--")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title(f"Aproximação do seno via Método de Runge-Kutta (ordem 2) com h de {step} com R² de {r2_rk2}")
    plt.legend()
    plt.grid(True)
    plt.savefig(f"rk2-out-{step}.png")

plt.figure(figsize=(10, 5))
plt.plot(STEPS, r2s, marker="o", label="RK4")
plt.plot(STEPS, r2s_rk2, marker="s", label="RK2")
plt.xlabel("Passo (h)")
plt.ylabel("R²")
plt.title("R² da aproximação do seno por Runge-Kutta para diferentes valores de h")
plt.xscale("log")
plt.grid(True)
plt.legend()
plt.savefig("rk_r2_vs_h.png")