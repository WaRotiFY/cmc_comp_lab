#include <stdio.h>
#include <math.h>
#include "root.h"

// Функция разности f1(x) - f2(x)
static double f(TargetFunc f, double x)
{
    return f.f1(x) - f.f2(x);
}

// Производная разности f1(x) - f2(x)
static double df(TargetFunc f, double x)
{
    return f.df1(x) - f.df2(x);
}

// формула Ньютона
static double newton_func(TargetFunc func, double x)
{
    return x - f(func, x) / df(func, x);
}

// формула хорд
static double chord_func(TargetFunc func, double left, double right)
{
    return left - (f(func, left) * (right - left)) / (f(func, right) - f(func, left));
}

// Функция нахождения корня смешанным методом
double root(double (*f1)(double), double (*f2)(double),
            double (*df1)(double), double (*df2)(double),
            double a, double b, double eps, char print, char iter)
{
    double c;

    // Структура для хранения функций разности
    TargetFunc combFunc;
    combFunc.f1 = f1;
    combFunc.f2 = f2;
    combFunc.df1 = df1;
    combFunc.df2 = df2;

    int cycle = 0;  // счётчик итераций

    // Оценка знака второй производной
    char d2sign = f(combFunc, (b - a) / 2) > (f(combFunc, b) - f(combFunc, a)) / 2 ? -1 : 1;

    // Выбор начальной точки для метода Ньютона: либо a, либо b
    char targetPoint = (d2sign * df(combFunc, a) > 0) ? 0 : 1;

    do {
        // Если цикл нечётный, используем метод хорд, иначе метод Ньютона
        if (cycle % 2) {
            c = chord_func(combFunc, a, b);
            if (f(combFunc, a) * f(combFunc, c) < 0) {
                b = c;
            }
            else {
                a = c;
            }
        }
        else {
            if (targetPoint) {
                c = newton_func(combFunc, b);
                b = c;
            }
            else {
                c = newton_func(combFunc, a);
                a = c;
            }
        }
    } while (cycle += 1, f(combFunc, c) * f(combFunc, c - eps) > 0 && f(combFunc, c) * f(combFunc, c + eps) > 0); 

    // При тесте для вывода корней
    if (print) {
        printf("Solution: %lf\n", c);
    }

    // При тесте для вывода количества итераций
    if (iter) {
        printf("Number of iterations: %d\n", cycle + 1);
    }

    return c;
}
