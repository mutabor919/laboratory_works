#include <stdio.h>
#include <assert.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

void test_getMemMatrix() {
    matrix m = getMemMatrix(1, 4);
    assert(m.nRows == 1 && m.nCols == 4 && m.values != NULL);
    freeMemMatrix(&m);
}

void test_getMemArrayOfMatrices() {
    matrix *ms = getMemArrayOfMatrices(3, 2, 2);
    for (size_t i = 0; i < 3; i++)
        assert(ms[i].nRows == 2 && ms[i].nCols == 2 && ms[i].values != NULL);
    assert(ms != NULL);
    freeMemMatrices(ms, 3);
}

void test_swapRows() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,4, 5, 6},2, 3);
    matrix m2 = createMatrixFromArray((int[]) {4, 5, 6,1, 2, 3},2, 3);
    swapRows(m1, 0, 1);
    assert(areTwoMatricesEqual(&m1, &m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_swapColumns() {
    matrix m1 = createMatrixFromArray((int[]) {1, 4,2, 5,3, 6},3, 2);
    matrix m2 = createMatrixFromArray((int[]) {4, 1,5, 2,6, 3},3, 2);
    swapColumns(m1, 0, 1);
    assert(areTwoMatricesEqual(&m1, &m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isSquareMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,2, 2, 2,3, 3, 3},3, 3);
    assert(isSquareMatrix(&m));
    freeMemMatrix(&m);
}

void test_areTwoMatricesEqual() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,4, 5, 6,7, 8, 9},3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,4, 5, 6,7, 8, 9},3, 3);
    assert(areTwoMatricesEqual(&m1, &m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isEMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,0, 1, 0,0, 0, 1},3, 3);
    assert(isEMatrix(&m));
    freeMemMatrix(&m);
}

void test_isSymmetricMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,2, 3, 7,3, 7, 1},3, 3);
    assert(isSymmetricMatrix(&m));
    freeMemMatrix(&m);
}

void test_transposeSquareMatrix() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,1, 2, 3,1, 2, 3},3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 1, 1,2, 2, 2,3, 3, 3},3, 3);
    transposeSquareMatrix(&m1);
    assert(areTwoMatricesEqual(&m1, &m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray((int[]) {8, 2, 3,5, 7, 1,4, 2, 3},3, 3);
    position p = getMinValuePos(m);
    assert(p.rowIndex == 1 && p.colIndex == 2);
    freeMemMatrix(&m);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray((int[]) {7, 4, 1,5, 9, 3,1, 10, 12},3, 3);
    position p = getMaxValuePos(m);
    assert(p.rowIndex == 2 && p.colIndex == 2);
    freeMemMatrix(&m);
}

void test() {
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
    test_swapRows();
    test_isSquareMatrix();
    test_isSymmetricMatrix();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_swapColumns();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

int main() {
    test();
    printf("All tests passed!\n");
    return 0;
}
