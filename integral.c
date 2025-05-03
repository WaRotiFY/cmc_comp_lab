#include <stdio.h>
#include <math.h>

int calculate_min_n(double a, double b, double eps, double maxf4)
{
    double term = pow(b - a, 5) * maxf4 / (180.0 * eps);
    double n_f = pow(term, 0.25);
    
    int n = (int)ceil(n_f);
    if (n % 2 != 0) {
        n++;
    }
    
    return n < 2? 2: n;
}

double integral(double (*f)(double), double a, double b, double eps, double maxf4)
{
    int n = calculate_min_n(a, b, eps, maxf4);
    double step = (b - a) / n;
    double ans = 0;
    double x1 = a;
    double x2 = a;
    for (int i = 0; i < n; i++) {
        x2 += step;
        ans += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f((x1 + x2) / 2) + f(x2));
        x1 += step;
    }

    return ans;
}