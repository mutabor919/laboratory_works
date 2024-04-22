#include <stdio.h>
#include <windows.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int max2(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int quantity = m.nRows + m.nCols - 2;
    int max_pseudo_diagonal[quantity];

    for (size_t i = 0; i < quantity; i++) {
        max_pseudo_diagonal[i] = 0;
    }

    int i_pseudo_diagonal;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (j != i) {
                if (i > j) {
                    i_pseudo_diagonal = j - i + m.nRows - 1;
                } else {
                    i_pseudo_diagonal = j - i + m.nRows - 2;
                }
                max_pseudo_diagonal[i_pseudo_diagonal] = max2(max_pseudo_diagonal[i_pseudo_diagonal], m.values[i][j]);
            }
        }
    }
    return getSum(max_pseudo_diagonal, quantity);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int quantity_rows, quantity_columns;
    printf("Введите количество рядов и столбцов: ");
    scanf("%d %d", &quantity_rows, &quantity_columns);

    matrix m = getMemMatrix(quantity_rows, quantity_columns);
    printf("Введите элементы матрицы: ");
    inputMatrix(&m);
    printf("%lld", findSumOfMaxesOfPseudoDiagonal(m));

    return 0;
}