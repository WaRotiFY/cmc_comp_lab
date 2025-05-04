#include <stdio.h>
#include <math.h>
#include <float.h>
#include "list.h"

// Функция вычисления определённого интеграла функции f от a до b с заданной точностью eps по формуле Симпсона
double integral(double (*f)(double), double a, double b, double eps)
{
    // last_data — значения функции в точках до удвоения числа отрезков
    // cur_data — значения функции в точках после удвоения числа отрезков
    DoubleList *last_data = init();
    DoubleList *cur_data = init();
    reset(last_data, f(a), 0);
    reset(last_data, f((a + b) / 2), 1);
    reset(last_data, f(b), 2);

    int n = 2;
    double step;                 
    double In = 0;
    double I2n = DBL_MAX;
    
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

            double f_left = get(last_data, i);
            reset(cur_data, f_left, 2 * i );
            double f_right = get(last_data, i + 1);
            reset(cur_data, f_right, 2 * (i + 1));
            double f_mid = f((x1 + x2) / 2.0);
            reset(cur_data, f_mid, 2 * i + 1);

            I2n += (x2 - x1) / 6.0 * (f_left + 4.0 * f_mid + f_right);

            x1 += step;
        }
        n *= 2;
        
        DoubleList *temp = cur_data;
        cur_data = last_data;
        last_data = temp;
    } while (fabs(I2n - In) >= eps);

    destroy(cur_data);
    destroy(last_data);
    return I2n;
}
