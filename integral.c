#include <stdio.h>
#include <math.h>

// Функция для вычисления минимального чётного n,
// необходимого для достижения заданной точности интегрирования (по формуле Симпсона)
int calculate_min_n(double a, double b, double eps, double maxf4)
{
    // n >= ((b - a)^5 * max|f^(4)(x)|) / (180 * ε))^(1/4)
    double term = pow(b - a, 5) * maxf4 / (180.0 * eps);
    double n_f = pow(term, 0.25);

    int n = (int)ceil(n_f);

    if (n % 2 != 0) {
        n++;
    }

    // Минимум 2 разбиения
    return n < 2 ? 2 : n;
}

// Функция вычисления определённого интеграла функции f от a до b с заданной точностью eps по формуле Симпсона
double integral(double (*f)(double), double a, double b, double eps, double maxf4)
{
    int n = calculate_min_n(a, b, eps, maxf4); 
    double step = (b - a) / n;                 
    double ans = 0;                            
    double x1 = a;
    double x2 = a;

    // Вычисление суммы по формуле Симпсона на каждом отрезке
    for (int i = 0; i < n; i++) {
        x2 += step;
        ans += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f((x1 + x2) / 2) + f(x2));
        x1 += step;
    }

    return ans;
}
