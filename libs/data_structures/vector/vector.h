#ifndef INC_13_LABA_VECTOR_H
#define INC_13_LABA_VECTOR_H

#include <stdio.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

// возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

//изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(vector *vector, size_t new_capacity);

//удаляет элементы из контейнера, но не освобождает выделенную память.
void clear(vector *vector);

//освобождает память, выделенную под неиспользуемые элементы.
void shrinkToFit(vector *vector);

//освобождает память, выделенную вектору.
void deleteVector(vector *vector);

#endif //INC_13_LABA_VECTOR_H
