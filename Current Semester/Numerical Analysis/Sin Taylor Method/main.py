import math
import matplotlib.pyplot as plt

from sklearn.metrics import r2_score


def taylor_sin(y, h, dy, ddy):
    return y + (h * dy) + ((h ** 2) / 2) * ddy

def taylor_sin_iteration(start_x, start_y, start_y_derivative, step, number_of_iterations):
    x_values = [start_x]
    y_values = [start_y]
    y_derivative_values = [start_y_derivative]
    real_values = [0]
    
    for _ in range(number_of_iterations):
        last_x = x_values[-1]
        last_y = y_values[-1]
        last_y_derivative = y_derivative_values[-1]

        first_derivative_value = last_y_derivative
        second_derivative_value = -last_y

        next_y = taylor_sin(y=last_y, h=step, dy=first_derivative_value, ddy=second_derivative_value)
        
        next_y_derivative = last_y_derivative + step * second_derivative_value + ((step ** 2) / 2) * (-last_y_derivative)

        x_values.append(last_x + step)
        y_values.append(next_y)
        y_derivative_values.append(next_y_derivative)
        real_values.append(math.sin(last_x))

    return x_values, y_values, real_values

def taylor_sin_4th(y, h, dy, ddy, d3y, d4y):
    # Taylor expansion up to 4th order
    return (
        y
        + h * dy
        + (h ** 2) / 2 * ddy
        + (h ** 3) / 6 * d3y
        + (h ** 4) / 24 * d4y
    )

def taylor_sin_iteration_4th(start_x, start_y, start_y_derivative, step, number_of_iterations):
    x_values = [start_x]
    y_values = [start_y]
    y_derivative_values = [start_y_derivative]
    real_values = [0]

    for _ in range(number_of_iterations):
        last_x = x_values[-1]
        last_y = y_values[-1]
        last_y_derivative = y_derivative_values[-1]

        # Derivatives for y'' = -y, y''' = -y', y'''' = y
        first_derivative_value = last_y_derivative
        second_derivative_value = -last_y
        third_derivative_value = -last_y_derivative
        fourth_derivative_value = last_y

        next_y = taylor_sin_4th(
            y=last_y,
            h=step,
            dy=first_derivative_value,
            ddy=second_derivative_value,
            d3y=third_derivative_value,
            d4y=fourth_derivative_value,
        )

        # Update y' using Taylor up to 4th order for y'
        # y'(x+h) = y'(x) + h*y''(x) + h^2/2*y'''(x) + h^3/6*y''''(x)
        next_y_derivative = (
            last_y_derivative
            + step * second_derivative_value
            + (step ** 2) / 2 * third_derivative_value
            + (step ** 3) / 6 * fourth_derivative_value
        )

        x_values.append(last_x + step)
        y_values.append(next_y)
        y_derivative_values.append(next_y_derivative)
        real_values.append(math.sin(last_x))

    return x_values, y_values, real_values

r2s = []
r2s_4 = []

STEPS = [0.5, 0.25, 0.125, 0.125/2, 0.125/4, 0.125/8, 0.125/16, 0.125/32]

for step in STEPS:
    START_X, START_Y, START_Y_DERIVATIVE = 0, 0, 1

    x_values, y_values, real_values = taylor_sin_iteration(START_X, START_Y, START_Y_DERIVATIVE, step, 50_000)
    x_values_4, y_values_4, real_values_4 = taylor_sin_iteration_4th(START_X, START_Y, START_Y_DERIVATIVE, step, 50_000)

    r2 = r2_score(real_values, y_values)
    r2_4 = r2_score(real_values_4, y_values_4)

    f = math.ceil((3.15 * 4) / step)

    r2s_4.append(max(r2_4, 0))
    r2s.append(max(r2, 0))
    # Plot
    plt.figure(figsize=(10,5))
    plt.plot(x_values_4[:f], y_values_4[:f], label="Aproximação (Taylor ordem 4)", marker="o", markersize=3)
    plt.plot(x_values_4[:f], real_values_4[:f], label="Seno real", linestyle="--")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title(f"Aproximação do seno via Método de Taylor (ordem 4) com h de {step} com R² de {r2_4}")
    plt.legend()
    plt.grid(True)
    plt.savefig(f"out-{step}-4.png")

    plt.figure(figsize=(10,5))
    plt.plot(x_values[:f], y_values[:f], label="Aproximação (Taylor ordem 2)", marker="o", markersize=3)
    plt.plot(x_values[:f], real_values[:f], label="Seno real", linestyle="--")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title(f"Aproximação do seno via Método de Taylor (ordem 2) com h de {step} com R² de {r2}")
    plt.legend()
    plt.grid(True)
    plt.savefig(f"out-{step}.png")

plt.figure(figsize=(10, 5))
plt.plot(STEPS, r2s_4, marker="o", label="Taylor Ordem 4")
plt.plot(STEPS, r2s, marker="s", label="Taylor Ordem 2")
plt.xlabel("Passo (h)")
plt.ylabel("R²")
plt.title("R² da aproximação do seno por Taylor (ordem 4) para diferentes valores de h")
plt.xscale("log")
plt.grid(True)
plt.savefig("r2_vs_h.png")