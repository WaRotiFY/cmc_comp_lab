#include <stdio.h>
#include "root.h"
#include "integral.h"
#include "test_funcs.h"

// Тестирование функции корня
void test_root(void)
{
    int funcNum1, funcNum2;
    double a, b, eps; 

    printf("------------------------------\n");
    printf("Testing root...\n");
    printf("Enter function numbers (1-3): ");
    scanf("%d %d", &funcNum1, &funcNum2);
    funcNum1--; // Индексация с 0
    funcNum2--; // Индексация с 0
    printf("Enter interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter epsilon: ");
    scanf("%lf", &eps);

    // Вычисляем корень
    // funcs_pack содержит набор тестируемых функций из файла test_funcs.c
    root(funcs_pack[funcNum1], funcs_pack[funcNum2], dfuncs_pack[funcNum1], dfuncs_pack[funcNum2], a, b, eps, 1, 1); // 1 - вывод корня, 1 - вывод итераций
    printf("------------------------------\n");
}

// Тестирование функции интеграла
void test_integral(void)
{
    int funcNum; 
    double a, b, eps;

    printf("------------------------------\n");
    printf("Testing integral...\n");
    printf("Enter function number (1-3): ");
    scanf("%d", &funcNum);
    funcNum--; // Индексация с 0
    printf("Enter interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter epsilon: ");
    scanf("%lf", &eps);

    // Вычисление определённого интеграла
    printf("Integral: %lf\n", integral(funcs_pack[funcNum], a, b, eps, 10)); // 10 - константа для точности вычислений
    printf("------------------------------\n");
}
