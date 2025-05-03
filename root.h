#ifndef ROOT_H
#define ROOT_H

typedef struct {
    double (*f1)(double);
    double (*f2)(double);
    double (*df1)(double);
    double (*df2)(double);
} TargetFunc;

double root(double (*f1)(double), double (*f2)(double),
           double (*df1)(double), double (*df2)(double),
           double a, double b, double eps, char print, char iter);

#endif