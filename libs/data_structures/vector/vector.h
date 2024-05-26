#ifndef INC_13_LABA_VECTOR_H
#define INC_13_LABA_VECTOR_H

#include <stdio.h>
#include <stdbool.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

vector createVectorFromArray(int *arr, int size);

//изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(vector *vector, size_t new_capacity);

//удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *vector);

//освобождает память, выделенную под неиспользуемые элементы.
void shrinkToFit(vector *vector);

//освобождает память, выделенную вектору.
void deleteVector(vector *vector);

// проверка на то, является ли вектор пустым.
bool isEmpty(vector *vector);

// проверка на то, что вектор полный.
bool isFull(vector *vector);

// возвращает i-ый элемент вектора v.
int getVectorValue(vector *vector, size_t i);

//добавляет элемент x в конец вектора v.
void pushBack(vector *vector, int x);

//удаляет последний элемент из вектора.
void popBack(vector *vector);

//возвращает указатель на index-ый элемент вектора.
int *atVector(vector *vector, size_t index);

//возвращает указатель на последний элемент вектора.
int *back(vector *vector);

// возвращает указатель на нулевой элемент вектора.
int *front(vector *vector);

#endif //INC_13_LABA_VECTOR_H
