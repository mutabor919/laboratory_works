#include <stdio.h>
#include <malloc.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\unordered_array_set\unordered_array_set.h"


unordered_array_set unordered_array_set_create(size_t capacity) {
    unordered_array_set set;
    set.data = (int *) malloc(capacity * sizeof(int)); // (int *) - явное приведение указателя к типу.
    set.size = 0;
    set.capacity = capacity;
    return set;
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set;
    set.data = (int *) malloc(size * sizeof(int));
    memcpy(set.data, a, size * sizeof(int));
    set.size = size;
    set.capacity = size;
    return set;
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    for (size_t i = 0; i < set->size; i++) {
        if (set->data[i] == value) {
            return i;
        }
    }
    return set->size;
}

bool unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++) {
        if (unordered_array_set_in(&set, subset.data[i]) == set.size) {
            return false;
        }
    }
    return true;
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size) {
        return false;
    }
    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size) {
            return false;
        }
    }
    return true;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    if (set->size >= set->capacity) {
        printf("Множество заполнено. Невозможно вставить элемент.\n");
        assert(false);
    }
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    unordered_array_set_isAbleAppend(set);
    set->data[set->size] = value;
    set->size++;
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t position = unordered_array_set_in(set, value);
    if (position != set->size) {
        for (size_t i = position; i < set->size - 1; i++) {
            set->data[i] = set->data[i + 1];
        }
        set->size--;
    }
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++) {
        unordered_array_set_insert(&result, set1.data[i]);
    }
    for (size_t i = 0; i < set2.size; i++) {
        unordered_array_set_insert(&result, set2.data[i]);
    }
    return result;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(&set2, set1.data[i]) != set2.size) {
            unordered_array_set_insert(&result, set1.data[i]);
        }
    }
    return result;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(&set2, set1.data[i]) == set2.size) {
            unordered_array_set_insert(&result, set1.data[i]);
        }
    }
    return result;
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    unordered_array_set result = unordered_array_set_create(universumSet.size);
    for (size_t i = 0; i < universumSet.size; i++) {
        if (unordered_array_set_in(&set, universumSet.data[i]) == set.size) {
            unordered_array_set_insert(&result, universumSet.data[i]);
        }
    }
    return result;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_difference(unordered_array_set_union(set1, set2),
                                                                unordered_array_set_intersection(set1, set2));
    return result;
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    for (size_t i = 0; i < set.size; i++) {
        printf("%d", set.data[i]);
        if (i < set.size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void unordered_array_set_delete(unordered_array_set *set) {
    free(set->data);
    set->size = 0;
    set->capacity = 0;
}
