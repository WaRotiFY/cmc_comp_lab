#include <stdio.h>
#include <math.h>

double t_f1(double x)
{
    return x + 1;
}

double t_f2(double x)
{
    return pow(x, 2) + 1;
}

double t_f3(double x)
{
    return -pow(x, 3);
}

double t_df1(double x)
{
    return 1;
}

double t_df2(double x)
{
    return 2 * x;
}

double t_df3(double x)
{
    return -3 * pow(x, 2);
}