#include <stdio.h>
#include "root.h"
#include "integral.h"
#include "test_funcs.h"

void test_root(void)
{
    int funcNum1, funcNum2;
    double a, b, eps;
    printf("------------------------------\n");
    printf("Testing root...\n");
    printf("Enter function numbers (1-3): ");
    scanf("%d %d", &funcNum1, &funcNum2);
    funcNum1--;
    funcNum2--;
    printf("Enter interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter epsilon: ");
    scanf("%lf", &eps);
    root(funcs_pack[funcNum1], funcs_pack[funcNum2], dfuncs_pack[funcNum1], dfuncs_pack[funcNum2], a, b, eps, 1, 1);
    printf("------------------------------\n");
}

void test_integral(void)
{
    int funcNum;
    double a, b, eps;
    printf("------------------------------\n");
    printf("Testing integral...\n");
    printf("Enter function number (1-3): ");
    scanf("%d", &funcNum);
    funcNum--;
    printf("Enter interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter epsilon: ");
    scanf("%lf", &eps);
    printf("Integral: %lf\n", integral(funcs_pack[funcNum], a, b, eps, 10));
    printf("------------------------------\n");
}