#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdbool.h>

typedef struct ordered_array_set {
    int *data;
    size_t size;
    size_t capacity;
} ordered_array_set;

ordered_array_set ordered_array_set_create_from_array(const int a[], size_t size) {
    ordered_array_set set;
    set.data = (int *) malloc(size * sizeof(int));
    memcpy(set.data, a, size * sizeof(int));
    set.size = size;
    set.capacity = size;
    return set;
}

size_t ordered_array_set_in(ordered_array_set *set, int value) {
    for (size_t i = 0; i < set->size; i++) {
        if (set->data[i] == value) {
            return i;
        }
    }
    return set->size;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++) {
        if (ordered_array_set_in(&set, subset.data[i]) == set.size) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 8, 12, 20};
    int size = sizeof(a) / sizeof(a[0]);

    int b[] = {1, 2, 3, 4, 5, 6, 9, 12, 20};
    int size2 = sizeof(b) / sizeof(b[0]);

    ordered_array_set set1 = ordered_array_set_create_from_array(a, size);
    ordered_array_set set2 = ordered_array_set_create_from_array(b, size2);

    printf("%d", ordered_array_set_isSubset(set1, set2));


    return 0;
}
