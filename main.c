#include <stdio.h>
#include <windows.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

matrix mulMatrices(matrix m1, matrix m2) {
    matrix result = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < result.nRows; i++) {
        for (int j = 0; j < result.nCols; j++) {
            result.values[i][j] = 0;
            for (size_t k = 0; k < m1.nCols; k++) {
                result.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
    return result;
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix m = mulMatrices(m1, m2);
    return isEMatrix(&m) ? true : false;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int quantity_rows_A, quantity_columns_A;
    printf("Введите количество рядов и столбцов для матрицы A: ");
    scanf("%d %d", &quantity_rows_A, &quantity_columns_A);

    matrix A = getMemMatrix(quantity_rows_A, quantity_columns_A);
    printf("Введите элементы матрицы: ");
    inputMatrix(&A);

    int quantity_rows_B, quantity_columns_B;
    printf("Введите количество рядов и столбцов для матрицы B: ");
    scanf("%d %d", &quantity_rows_B, &quantity_columns_B);

    matrix B = getMemMatrix(quantity_rows_B, quantity_columns_B);
    inputMatrix(&B);

    printf("%d", isMutuallyInverseMatrices(A, B));

    return 0;
}