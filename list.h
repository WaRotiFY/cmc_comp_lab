#ifndef LIST_H
#define LIST_H

typedef struct
{
    int size;
    int capacity;
    double *list;
}DoubleList;

DoubleList *init(void);
void append(DoubleList *list, double x);
void reset(DoubleList *list, double x, size_t ind);
double get(DoubleList *list, size_t ind);
void destroy(DoubleList *list);

#endif