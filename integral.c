#include <stdio.h>
#include <math.h>

// Функция вычисления интеграла с заданной точностью методом Симпсона
double integral(double (*f)(double), double a, double b, double eps) {
    int num_segments = 1;
    double prev_integral;
    double step = (b - a) / (2 * num_segments);

    // Сумма значений функции в чётных точках
    double sum_even = 0.0;
    double x = a + 2 * step;
    for (int i = 2; i < 2 * num_segments; i += 2) {
        sum_even += f(x);
        x += 2 * step;
    }
    sum_even *= 2;

    // Сумма значений функции в нечётных точках 
    x = a + step;
    double sum_odd = 0.0;
    for (int i = 1; i < 2 * num_segments; i += 2) {
        sum_odd += f(x);
        x += 2 * step;
    }
    sum_odd *= 4;

    // Вычисление текущего значения интеграла по формуле Симпсона
    double current_integral = (f(a) + f(b) + sum_odd + sum_even) * step / 3;

    sum_odd /= 4;
    sum_even /= 2;

    // Цикл идет пока |In - I2n| >= eps (справедливо, так как |I - I2n|~|In - I2n|)
    do {
        num_segments *= 2;
        prev_integral = current_integral;
        step = (b - a) / (2 * num_segments);

        // Новые чётные точки — это все предыдущие нечётные
        double new_sum_even = sum_even + sum_odd;
        new_sum_even *= 2;

        // Новые нечётные точки
        x = a + step;
        double new_sum_odd = 0.0;
        for (int i = 1; i < 2 * num_segments; i += 2) {
            new_sum_odd += f(x);
            x += 2 * step;
        }
        new_sum_odd *= 4;

        current_integral = (f(a) + f(b) + new_sum_odd + new_sum_even) * step / 3;

        sum_even = new_sum_even / 2;
        sum_odd = new_sum_odd / 4;

    } while (fabs(current_integral - prev_integral) > eps);

    return current_integral;
}
