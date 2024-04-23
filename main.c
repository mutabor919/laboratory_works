#include <stdio.h>
#include <windows.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            count += 1;
        }
    }
    return count;
}

int countZeroRows(matrix m) {
    int count_zero_rows = 0;
    for (int i = 0; i < m.nRows; i++) {
        if (countValues(m.values[i], m.nCols, 0) == m.nCols) {
            count_zero_rows += 1;
        }
    }
    return count_zero_rows;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int zero_rows_matrix[nMatrix];
    int maxZeroRows = 0;
    for (int i = 0; i < nMatrix; i++) {
        int zero_rows = countZeroRows(ms[i]);
        zero_rows_matrix[i] =zero_rows;
        if (zero_rows > maxZeroRows)
            maxZeroRows = zero_rows;
    }

    for (int i = 0; i < nMatrix; i++) {
        if (zero_rows_matrix[i] == maxZeroRows) {
            printMatrix(ms[i]);
            printf("\n");
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int quantity_rows, quantity_columns;
    printf("Введите количество рядов и столбцов: ");
    scanf("%d %d", &quantity_rows, &quantity_columns);

    int quantity_matrices;
    printf("Введите количество матриц: ");
    scanf("%d", &quantity_matrices);

    matrix *ms = getMemArrayOfMatrices(quantity_matrices, quantity_rows, quantity_columns);
    inputMatrices(ms, quantity_matrices);
    printMatrixWithMaxZeroRows(ms, quantity_matrices);

    return 0;
}