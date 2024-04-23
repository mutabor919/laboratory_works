#include <stdio.h>
#include <windows.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

int maxAbsoluteValue(matrix m) {
    int max = abs(m.values[0][0]);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int absolut_value = abs(m.values[i][j]);
            if (absolut_value > max) {
                max = absolut_value;
            }
        }
    }
    return max;
}

void printMatrixWithMinAbsolutValue(matrix *ms, int n) {
    int min_absolut_value = maxAbsoluteValue(ms[0]);
    for (int i = 1; i < n; i++) {
        int matrix_norm = maxAbsoluteValue(ms[i]);
        if (matrix_norm < min_absolut_value) {
            min_absolut_value = matrix_norm;
        }
    }

    for (int i = 0; i < n; i++) {
        if (maxAbsoluteValue(ms[i]) == min_absolut_value) {
            printMatrix(ms[i]);
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
    printMatrixWithMinAbsolutValue(ms, quantity_matrices);

    return 0;
}