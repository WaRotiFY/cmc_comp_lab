#include <stdio.h>
#include <math.h>

double t_f1(double x)
{
    return sin(10 * x);
}

double t_f2(double x)
{
    return exp(- x * x);
}

double t_f3(double x)
{
    return log(x + 0.1);
}

double t_df1(double x)
{
    return 10 * cos(10 * x);
}

double t_df2(double x)
{
    return -2 * x * exp(- x * x);
}

double t_df3(double x)
{
    return 1 / (x + 0.1);
}