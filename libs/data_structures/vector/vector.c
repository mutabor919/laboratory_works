#include <stdio.h>
#include <malloc.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\vector\vector.h"

vector createVector(size_t n) {
    int *data = malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    return (vector) {data, 0, n};
}

void reserve(vector *vector, size_t new_capacity) {
    if (new_capacity == 0) {
        free(vector->data);
    } else {
        int *new_data = realloc(vector->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        } else {
            if (new_capacity <= vector->size) {
                vector->size = new_capacity;
            }
            vector->data = new_data;
            vector->capacity = new_capacity;
        }
    }
}

void clear(vector *vector) {
    vector->size = 0;
}

void shrinkToFit(vector *vector) {
    reserve(vector, vector->size);
}

void deleteVector(vector *vector) {
    free(vector->data);
    vector->size = 0;
    vector->capacity =0;
}

bool isEmpty(vector *vector) {
    return vector->size == 0;
}

bool isFull(vector *vector) {
    return vector->size == vector->capacity && vector->size != 0;
}

int getVectorValue(vector *vector, size_t i) {
    return i < vector->size ? vector->data[i] : -1;
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);
    v->data[v->size] = x;
    v->size++;
}


void popBack(vector *vector) {
    if (isEmpty(vector)) {
        fprintf(stderr, "empty");
        exit(1);
    } else {
        vector->size--;
        shrinkToFit(vector);
    }
}

int *atVector(vector *vector, size_t index) {
    if (index >= vector->size) {
        fprintf(stderr, "IndexError: a[%llu] is not exists", index);
        exit(1);
    }
    return &vector->data[index];
}

int *back(vector *vector) {
    return &vector->data[vector->size - 1];
}

int *front(vector *vector) {
    return &vector->data[0];
}


