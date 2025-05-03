#include <stdio.h>
#include <math.h>
#include "root.h"
#include "integral.h"
#include "funcs.h"

// Четвёртые производные функций f1
double d4f1(double x) {
    return 1152.0 / pow((2 * x + 2), 5);
}

// Четвёртые производные функций f2
double d4f2(double x) {
    return 0;
}

// Четвёртые производные функций f3
double d4f3(double x) {
    return 120.0 / pow(x, 5);
}

// оиск корней, вычисление интегралов
void my_task(char print, char iter)
{
    double eps1 = 0.0001;  // точность для нахождения корней
    double eps2 = 0.0005;  // точность для интегрирования

    // Интервалы, на которых ищутся корни для разных пар функций
    double intervals[][2] = {
        {1, 2},       // для f1 и f3
        {3.5, 4.5},   // для f2 и f3
        {4.5, 5.5}    // для f1 и f2
    };

    printf("------------------------------\n");
    printf("Root calculations f1 and f3...\n");
    double x1 = root(f1, f3, df1, df3, intervals[0][0], intervals[0][1], eps1, print, iter);

    printf("------------------------------\n");
    printf("Root calculations f2 and f3...\n");
    double x2 = root(f2, f3, df2, df3, intervals[1][0], intervals[1][1], eps1, print, iter);

    printf("------------------------------\n");
    printf("Root calculations f1 and f2...\n");
    double x3 = root(f1, f2, df1, df2, intervals[2][0], intervals[2][1], eps1, print, iter);

    printf("------------------------------\n");
    printf("Calculation of the integral...\n");

    double integral1 = integral(f1, x1, x3, eps2, d4f1(x1));
    double integral2 = integral(f2, x2, x3, eps2, d4f2(x2));
    double integral3 = integral(f3, x1, x2, eps2, d4f3(x1));

    // Итоговая формула задачи — разность площадей под кривыми
    double integral = integral1 - integral2 - integral3;

    printf("Integral: %lf\n", integral);
    printf("------------------------------\n");
}
