#include <stdio.h>
#include <windows.h>
#include "C:\Users\mutab\CLionProjects\13_laba\libs\data_structures\matrix\matrix.h"

bool isUnique(int *a, int n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (a[i] == a[j])
                return false;
        }
    }
    return true;
}

int getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long sumArray[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        sumArray[i] = getSum(m.values[i], m.nCols);
    }
    if (isUnique(sumArray, m.nRows)) {
        transposeSquareMatrix(&m);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int quantity_rows, quantity_columns;
    printf("Введите количество рядов и столбцов: ");
    scanf("%d %d", &quantity_rows, &quantity_columns);

    matrix m = getMemMatrix(quantity_rows, quantity_columns);
    inputMatrix(&m);
    transposeIfMatrixHasNotEqualSumOfRows(m);
    printMatrix(m);

    return 0;
}