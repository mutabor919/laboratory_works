#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\vector\vector.h"

void test_pushBackVector_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 40);
    assert(v.data[v.size - 1] == 40);
    assert(v.capacity == 1);
}

void test_pushBackVector_fullVector(){
    vector v = createVector(2);
    pushBack(&v, 20);
    pushBack(&v, 40);
    pushBack(&v, 60);
    assert(v.data[v.size - 2] == 40);
    assert(v.capacity == 4);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(3);
    pushBack(&v, 20);
    pushBack(&v, 40);
    pushBack(&v, 60);
    int first_element = *atVector(&v, 0);
    int second_element = *atVector(&v, 1);
    int third_element = *atVector(&v, 2);
    assert(first_element == 20);
    assert(second_element == 40);
    assert(third_element == 60);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 20);
    int last_element = *atVector(&v, 1);
    assert(last_element == 20);
}

void test_back_oneElementInVector() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 20);
    int last_element = *back(&v);
    assert(last_element == 20);
}

void test_front_oneElementInVector(){
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 20);
    int first_element = *front(&v);
    assert(first_element == 10);
}

void test() {
    test_pushBackVector_emptyVector();
    test_pushBackVector_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main() {
    //vector v = createVector(SIZE_MAX);
    test();

    return 0;
}
