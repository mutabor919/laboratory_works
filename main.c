#include <stdio.h>
#include <windows.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        if (!isNonDescendingSorted(m.values[i], m.nCols)) {
            return false;
        }
    }
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int quantity_matrices = 0;
    for (int i = 0; i < nMatrix; i++) {
        if (hasAllNonDescendingRows(ms[i])) {
            quantity_matrices += 1;
        }
    }
    return quantity_matrices;
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
    printf("%d", countNonDescendingRowsMatrices(ms, quantity_matrices));

    return 0;
}