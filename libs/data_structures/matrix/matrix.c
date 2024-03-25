#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
    m.values = NULL;
    m.nRows = 0;
    m.nCols = 0;
}

void freeMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMatrix(ms[i]);
    free(ms);
    ms = NULL;
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            scanf("%d", &m->values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

void printMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

void printMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        printMatrix(ms[i]);
        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2){
    assert(i1 >= 0 && i1 < m.nRows && i2 >= 0 && i2 < m.nRows);
    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        int temp = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = temp;
    }
}



