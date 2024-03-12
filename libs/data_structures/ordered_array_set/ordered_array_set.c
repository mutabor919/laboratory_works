#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <memory.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\algorithms\array\array.h"
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\ordered_array_set\ordered_array_set.h"


ordered_array_set ordered_array_set_create(size_t capacity) {
    ordered_array_set set;
    set.data = (int*)malloc(capacity * sizeof(int));
    set.size = 0;
    set.capacity = capacity;
    return set;
}

ordered_array_set ordered_array_set_create_from_array(const int a[], size_t size) {
    ordered_array_set set;
    set.data = (int*)malloc(size * sizeof(int));
    memcpy(set.data, a, size * sizeof(int));
    set.size = size;
    set.capacity = size;
    return set;
}

size_t ordered_array_set_in(ordered_array_set* set, int value) {
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

bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size != set2.size) {
        return false;
    }
    for (size_t i = 0; i < set1.size; i++) {
        if (ordered_array_set_in(&set2, set1.data[i]) == set2.size) {
            return false;
        }
    }
    return true;
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    size_t index = ordered_array_set_in(set, value);
    if (index == set->size) {
        ordered_array_set_isAbleAppend(set);
        size_t i;
        for (i = set->size; i > 0 && set->data[i - 1] > value; i--) {
            set->data[i] = set->data[i - 1];
        }
        set->data[i] = value;
        set->size++;
    }
}


void ordered_array_set_deleteElement(ordered_array_set* set, int value) {
    size_t pos = ordered_array_set_in(set, value);
    if (pos < set->size) {
        for (size_t i = pos; i < set->size - 1; i++) {
            set->data[i] = set->data[i + 1];
        }
        set->size--;
    }
}

ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set unionSet = ordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++) {
        ordered_array_set_insert(&unionSet, set1.data[i]);
    }
    for (size_t i = 0; i < set2.size; i++) {
        ordered_array_set_insert(&unionSet, set2.data[i]);
    }
    return unionSet;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set intersectionSet = ordered_array_set_create(set1.size < set2.size ? set1.size : set2.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (ordered_array_set_in(&set2, set1.data[i]) != set2.size) {
            ordered_array_set_insert(&intersectionSet, set1.data[i]);
        }
    }
    return intersectionSet;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set differenceSet = ordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (ordered_array_set_in(&set2, set1.data[i]) == set2.size) {
            ordered_array_set_insert(&differenceSet, set1.data[i]);
        }
    }
    return differenceSet;
}

ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    return ordered_array_set_difference(universumSet, set);
}

ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set unionSet = ordered_array_set_union(set1, set2);
    ordered_array_set intersectionSet = ordered_array_set_intersection(set1, set2);
    ordered_array_set symmetricDifferenceSet = ordered_array_set_difference(unionSet, intersectionSet);
    ordered_array_set_delete(&unionSet);
    ordered_array_set_delete(&intersectionSet);
    return symmetricDifferenceSet;
}

void ordered_array_set_print(ordered_array_set set) {
    printf("{");
    int is_empty = 1;

    for (size_t i = 0; i < set.size; i++) {
        printf("%d, ", *(set.data + i));
        is_empty = 0;
    }
    if (is_empty)
        printf("}\n");
    else
        printf("\b\b}\n");
}


void ordered_array_set_delete(ordered_array_set* set) {
    free(set->data);
    set->size = 0;
    set->capacity = 0;
}
