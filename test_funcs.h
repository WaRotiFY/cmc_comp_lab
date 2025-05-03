#ifndef TEST_FUNCS_H
#define TEST_FUNCS_H

double t_f1(double x);
double t_f2(double x);
double t_f3(double x);
double t_df1(double x);
double t_df2(double x);
double t_df3(double x);

double (*funcs_pack[])(double) = {t_f1, t_f2, t_f3};
double (*dfuncs_pack[])(double) = {t_df1, t_df2, t_df3};

#endif