#include <stdio.h>
#include <math.h>

// Функция вычисления определённого интеграла функции f от a до b с заданной точностью eps по формуле Симпсона
double integral(double (*f)(double), double a, double b, double eps)
{
    int n = 2;
    double step;                 
    double In = 0;
    double I2n = 0;
    
    // Цикл на каждом шаге увеличивает число разбиений в два раза,
    // выполнятся до момента |I2n - In| < eps (справедливо, так как |I2n - In| ~ |I - I2n|)
    do {
        double x1 = a;
        double x2 = a;
        step = (b - a) / n;
        In = I2n;
        I2n = 0;

        // Вычисление суммы по формуле Симпсона на каждом отрезке
        for (int i = 0; i < n; i++) {
            x2 += step;
            I2n += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f((x1 + x2) / 2) + f(x2));
            x1 += step;
        }
        n *= 2;
    } while (fabs(I2n - In) >= eps);

    return I2n;
}
