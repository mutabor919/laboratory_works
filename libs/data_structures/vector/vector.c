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
