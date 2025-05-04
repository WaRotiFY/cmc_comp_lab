#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Инициализация списка
DoubleList *init(void)
{
    DoubleList *list = malloc(sizeof(DoubleList));
    list->size = 0;
    list->capacity = 1;
    list->list = calloc(1, sizeof(*(list->list)));
    return list;
}

// Добавляет элемент в конец списка
void append(DoubleList *list, double x)
{
    if (list->capacity <= list->size) {
        list->capacity *= 2;
        list->list = realloc(list->list, list->capacity * sizeof(*(list->list)));
    }
    list->list[list->size++] = x;
}

// Изменяет элемент по индексу, если индекс больше размера списка, то увеличивает размер списка
void reset(DoubleList *list, double x, size_t ind)
{
    if (ind >= list->size) {
        list->size = ind + 1;
        while (list->capacity <= list->size) { list->capacity *= 2; }
        list->list = realloc(list->list, list->capacity * sizeof(*(list->list)));
    }
    list->list[ind] = x;
    return;
}

// Получает элемент по индексу
double get(DoubleList *list, size_t ind)
{
    if (ind >= list->size) {
        printf("Out of range\n");
        return -1;
    }
    return list->list[ind];
}

// Очищает память
void destroy(DoubleList *list)
{
    free(list->list);
    free(list);
}