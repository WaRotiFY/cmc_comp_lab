#include <stdio.h>
#include <math.h>
#include "root.h"

static double f(TargetFunc f, double x)
{
    return f.f1(x) - f.f2(x);
}

static double df(TargetFunc f, double x)
{
    return f.df1(x) - f.df2(x);
}

static double newton_func(TargetFunc func, double x)
{
    return x - f(func, x) / df(func, x);
}

static double chord_func(TargetFunc func, double left, double right)
{
    return left - (f(func, left) * (right - left)) / (f(func, right) - f(func, left));
}

double root(double (*f1)(double), double (*f2)(double),
                    double (*df1)(double), double (*df2)(double),
                     double a, double b, double eps, char print, char iter)
{
    double c;
    TargetFunc combFunc;
    combFunc.f1 = f1;
    combFunc.f2 = f2;
    combFunc.df1 = df1;
    combFunc.df2 = df2;

    int cycle = 0;
    char d2sign = f(combFunc, (b - a) / 2) > (f(combFunc, b) - f(combFunc, a)) / 2 ? -1: 1;
    char targetPoint = (d2sign * df(combFunc, a) > 0) ? 0 : 1;

    do {
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
    } while (cycle += 1, fabs(f(combFunc, c)) > eps); 

    if (print) {
        printf("Solution: %lf\n", c);
    }

    if (iter) {
        printf("Number of iterations: %d\n", cycle + 1);
    }

    return c;
}